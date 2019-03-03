#include "../include/C_list.h"
#include <iostream>
#include <fstream>

using namespace std;

C_list::C_list()
{
    len = 0;
    first_item = NULL;
    last_item = NULL;

    log = "\n###############---LOG---###############\nInitializing the list \n";
}

C_list::~C_list()
{
    log.append("#########################\n");
    clear_list();

    ofstream fout;

    fout.open("log.txt");
    fout << log;
    fout.close();
}

bool C_list::is_valid_idx(int idx) {

    if((idx < len && idx >= 0) || (len == 0 && idx == 0)) {
        return true;
    }

    return false;

}

List_item* C_list::item(int idx) {

    List_item* li;

    if( idx < len / 2) {

        li = first_item;

        for(int i = 0; i < idx; i++) {
            li = li->next;
        }

    } else {

        li = last_item;

        for(int i = len-1; i > idx; i--) {
            li = li->prev;
        }
    }

    return li;
}

void C_list::add_item(list_type new_data) {

    insert_item(len, new_data);

}

void C_list::insert_item(int idx, list_type new_data) {

    string this_log = "Trying to insert data to the position " + to_string(idx) + "\n";

    result status = Failure;

    if(is_valid_idx(idx) || idx == len) {
        List_item* new_item = new List_item(new_data);

        if(len==0) {

            first_item = new_item;
            last_item = new_item;

        } else if(idx == 0) {

            new_item->next = first_item;
            first_item->prev = new_item;
            first_item = new_item;

        } else if(idx == len) {


            last_item->next = new_item;
            new_item->prev = last_item;

            new_item->next = NULL;

            last_item = new_item;

        } else {

            List_item* cur_item = item(idx);

            cur_item->prev->next = new_item;
            new_item->prev = cur_item->prev;
            new_item->next = cur_item;
            cur_item->prev = new_item;

        }

        status = Success;
        len++;

    }

    this_log.append(res2str(status) + "\n");

    log.append(this_log);
}

void C_list::print(output_type ot) {

    result status = Failure;
    log.append("Trying to print list\n");

    if(len > 0) {

        List_item* li = first_item;

        for(int i = 0; i < len; i++) {
            cout << li->str(ot) << "\n";
            li = li->next;
        }
        cout << '\n';

        status = Success;

    }

    log.append(res2str(status) + "\n");

}

void C_list::print(string filename, output_type ot) {

    result status = Failure;
    log.append("Trying to print list to a file " + filename + "\n");

    ofstream fout;
    fout.open(filename);

    if(len > 0) {

        if(!fout.is_open()) {
            log.append("Error while opening file\n");
        } else {
            List_item* li = first_item;

            for(int i = 0; i < len; i++) {
                fout << li->str(ot) << "\n";
                li = li->next;
            }


            status = Success;
        }

    }

    fout.close();

    log.append(res2str(status) + "\n");

}

void C_list::print_reverse(output_type ot) {

    log.append("Trying to print reverse list\n");

    if(len > 0) {

        List_item* li = last_item;

        for(int i = len-1; i >= 0; i--) {
            cout << li->str(ot) << "\n";
            li = li->prev;
        }
        cout << '\n';

    }

}

void C_list::delete_item(int idx) {

    result status = Failure;
    string this_log = "Trying to delete item with index " + to_string(idx) + "\n";

    List_item* li;

    if(is_valid_idx(idx)) {
        if(len==1) {

            li = first_item;
            first_item = NULL;
            last_item = NULL;

        } else if(idx == 0) {

            li = first_item;
            first_item = first_item->next;
            li = NULL;

        } else if(idx == len-1){

            li = last_item;
            last_item = last_item->prev;
            li = NULL;

        } else {

            li = item(idx-1);
            List_item* prev = item(idx-2);
            prev->next = li->next;
            li = NULL;

        }

        len--;
        status = Success;

    }

    this_log.append(res2str(status) + "\n");

    log.append(this_log);

}

void C_list::clear_list() {
    for(int i=0; i<len; i++) {
        delete_item(0);
    }
}

string C_list::res2str(result status) {
    switch (status) {
        case Success:
            return "Success";
            break;
        case Failure:
            return "Failure";
            break;
        default:
            return "Unknown";
    }
}

list_type C_list::get_data(int idx) {

    string this_log = "Trying to get data at the position " + to_string(idx) + "\n";
    result status = Failure;

    if(is_valid_idx(idx)) {

        return *item(idx)->data;
        status = Success;

    }

    this_log.append(res2str(status));

    if(status == Failure) {
        this_log.append(". Gonna generate glourious random number!\n");
    } else {
        this_log.append("\n");
    }

    log.append(this_log);

    return Donor("");

}

void C_list::set_data(int idx, list_type new_data) {

    string this_log = "Trying to set data to the element " + to_string(idx) + "\n";
    result status = Failure;

    if(is_valid_idx(idx)) {

        List_item* li = item(idx);
        *li->data = new_data;
        status = Success;

    }

    this_log.append(res2str(status) + "\n");

    log.append(this_log);

}

void C_list::swap_items(int idx_1, int idx_2) {

    string this_log = "Trying to swap element " + to_string(idx_1) + " with element " + to_string(idx_2) + "\n";
    result status = Failure;

    if(is_valid_idx(idx_2)) {

        if(is_valid_idx(idx_1)) {

            List_item* item_1 = item(idx_1);
            List_item* item_2 = item(idx_2);

            swap_items(item_1, item_2);

            status = Success;

        } else {

            this_log.append("Index " + to_string(idx_1) + " is incorrect\n");

        }
    } else {
        this_log.append("Index " + to_string(idx_2) + " is incorrect\n");
    }

    this_log.append(res2str(status) + "\n");

    log.append(this_log);

}

void C_list::swap_items(List_item* item_1, List_item* item_2) {

    list_type* temp;
    temp = item_1->data;
    item_1->data = item_2->data;
    item_2->data = temp;

}


void C_list::sort_data() {

    log.append("Sorting list\n");
    quick_sort(0, len-1);
}

void C_list::quick_sort(int left, int right) { // не работает, пока не понимаю, почему

    if (left < right) {

        List_item* j_item = item(left);

        int i = left;

        List_item* pivot = item(right);

        for (int j = left; j < right; j++) {

            if (*j_item < *pivot) {

                if (i != j) {
                    swap_items(i, j);
                }
                i++;

            }
            j_item = j_item->next;
        }

        swap_items(i, right);
        quick_sort(left, i-1);
        quick_sort(i+1, right);

    }

}



