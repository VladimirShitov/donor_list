#include "C_list.h"

List_item::List_item(list_type new_data): data(new list_type(new_data))
{

}

string List_item::str(output_type ot) {
    return data->str(ot);
}

List_item::~List_item()
{
    cout << "I am ~List_item() and I work" << '\n' << '\n';
    delete data;
}

bool List_item::operator<(List_item &li) {
    return data->compare(li.data, "<");
}

bool List_item::operator>(List_item &li){
    return data->compare(li.data, ">");
}

bool List_item::operator<=(List_item &li) {
    return data->compare(li.data, "<=");
}

bool List_item::operator>=(List_item &li) {
    return data->compare(li.data, ">=");
}

bool List_item::operator==(List_item &li) {
    return data->compare(li.data, "==");
}

bool List_item::operator!=(List_item &li) {
    return data->compare(li.data, "!=");
}

