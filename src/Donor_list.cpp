#include "Donor_list.h"
//#include "./Donor.h"
#include <fstream>

Donor_list::Donor_list(string file_name)
{
    ifstream fin;
    fin.open(file_name);

    string s;

    if(fin.is_open()) {

        while(!fin.eof()) {

            getline(fin, s);
            if (int(s[s.length()-1]) == 13) s = s.substr(0, s.length()-1); //Обрезает символ переноса строки
            this->add_item(s);

        }



    }

    delete_item(len-1);// удаляет пустую последнюю строку

    fin.close();
}

Donor_list::~Donor_list()
{
    //dtor
}

void Donor_list::show_only_valid() {

    int counter = 0;
    List_item* li = first_item;

    for(int i = 0; i < len; i++) {

        if(li->data->is_valid()) {
            cout << li->data->str(detailed_op) << '\n';
            counter++;
        }

        li = li->next;

    }

    cout << "Total items: " << len << ", valid items: " << counter << '\n';

}

void Donor_list::filter(filters by, string cond, bool more) {

    List_item* li = first_item;
    int counter = 0;

    switch (by) {

        case age:
            {

            char oper = cond[0];
                cond = cond.substr(1, cond.length()-1);


            for (int i = 0; i < len; i++) {

                li->data->set_filter(stoi(cond), oper, more);
                 if(li->data->get_filter()) counter++;
                li = li->next;

            }

            break;

            }
        case gend:
            {

            gender g = str2gen(cond);

            for (int i = 0; i < len; i++) {

                li->data->set_filter(g, more);
                if(li->data->get_filter()) counter++;
                li = li->next;

            }

            break;
            }
        case blood_type:
            {
            blood b = str2blood(cond);

            for (int i = 0; i < len; i++) {

                li->data->set_filter(b, more);
                if(li->data->get_filter()) counter++;
                li = li->next;
            }

            break;
            }
        case rhesus:
            {
            Rh r = str2rh(cond);

            for (int i = 0; i < len; i++) {

                li->data->set_filter(r, more);
                if(li->data->get_filter()) counter++;
                li = li->next;

            }

            break;
            }

    }

    cout << "Total items: " << len << ", filtered items: " << counter << '\n';

}

void Donor_list::print_filtered(output_type ot) {

    List_item* li = first_item;

    for (int i=0; i < len; i++) {

        if(li->data->get_filter()) cout << li->data->str(ot) << '\n';
        li = li->next;
    }


}
