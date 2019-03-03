#ifndef C_LIST_H
#define C_LIST_H
#include "List_item.h"
#include <string>

using namespace std;

enum result {Success, Failure, Unknown};

class C_list
{
    public:
        C_list();
        virtual ~C_list();

        string log;

        void add_item(list_type new_data);
        void print(output_type ot = normal_op);
        void print(string filename, output_type ot = normal_op);
        void print_reverse(output_type ot = normal_op);

        void delete_item(int idx);

        void insert_item(int idx, list_type new_data);

        list_type get_data(int idx);
        void set_data(int idx, list_type new_data);

        void swap_items(int idx_1, int idx_2);

        void sort_data();

    protected:
        int len;
        List_item* first_item;
        List_item* last_item;

        List_item* item(int idx);
        void clear_list();

        string res2str(result status);

        bool is_valid_idx(int idx);

        void swap_items(List_item* item_1, List_item* item_2);

        void quick_sort(int left, int right);

        bool operator<(List_item &li);
        bool operator>(List_item &li);
        bool operator<=(List_item &li);
        bool operator>=(List_item &li);
        bool operator==(List_item &li);
        bool operator!=(List_item &li);

    private:

};

#endif // C_LIST_H
