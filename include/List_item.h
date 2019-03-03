#ifndef LIST_ITEM_H
#define LIST_ITEM_H
#include <iostream>
#include "C_list.h"
#include "Donor.h"

using namespace std;

typedef Donor list_type;

class List_item
{
    public:
        List_item(list_type new_data);
        virtual ~List_item();

        list_type* data;
        List_item* next;
        List_item* prev;

        string str(output_type ot = normal_op);

        bool operator<(List_item &li);
        bool operator>(List_item &li);
        bool operator<=(List_item &li);
        bool operator>=(List_item &li);
        bool operator==(List_item &li);
        bool operator!=(List_item &li);

    protected:

    private:

};

#endif // LIST_ITEM_H
