#ifndef DONOR_LIST_H
#define DONOR_LIST_H

#include <C_list.h>

enum filters {gend, age, blood_type, rhesus};

class Donor_list : public C_list
{
    public:
        Donor_list(string file_name);
        virtual ~Donor_list();

        void show_only_valid();
        void filter(filters by, string cond, bool more);

        void print_filtered(output_type ot = normal_op);

    protected:


    private:
};

#endif // DONOR_LIST_H
