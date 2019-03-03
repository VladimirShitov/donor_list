#ifndef DONOR_H
#define DONOR_H
#include <iostream>

using namespace std;

enum gender {male, female, other, unknown_gender};
enum blood {O, A, B, AB, alien};
enum Rh {positive, negative, unknown_Rh};

enum output_type {normal_op, full_op, short_op, detailed_op};
enum comp_criterion {by_name, by_age, by_year};

const string delim_date = "/";
const string delim_info = ", ";

gender str2gen(string s);
string gen2str(gender g);

blood str2blood(string s);
string blood2str(blood b);

Rh str2rh(string s);
string rh2str(Rh rh);


class Donor
{
    public:
        Donor(string f_name, string l_name, gender g, int d, int m, int y, blood b, Rh rh);
        Donor(string f_name, string l_name, string g, string d, string m, string y, string b, string rh);
        Donor(string info);
        virtual ~Donor();

        string get_first_name();
        string get_last_name();
        string get_full_name();
        string get_short_name();

        string get_bday();
        gender get_gender();
        string get_gender_str();
        blood get_blood_type();
        string get_blood_type_str();
        Rh get_rh();
        string get_rh_str();

        bool is_year_leap();
        int get_age();
        int get_year();

        bool compare(Donor *d, string oper, comp_criterion comp = by_name);

        string str(output_type ot = normal_op);

        void set_first_name(string f_name);
        void set_last_name(string l_name);
        void set_gender (gender g);
        void set_day(int d);
        void set_month(int m);
        void set_year(int y);
        void set_blood(blood b);
        void set_rhesus(Rh rh);

        void set_gender (string g);
        void set_day(string d);
        void set_month(string m);
        void set_year(string y);
        void set_blood(string b);
        void set_rhesus(string rh);

        bool is_valid();

        bool get_filter();

        void set_filter(gender g, bool more);
        void set_filter(blood b, bool more);
        void set_filter(Rh r, bool more);
        void set_filter(int age, char cond, bool more);



    protected:

    private:
        string first_name;
        string last_name;
        gender gen;
        int day;
        int month;
        int year;
        blood b_group;
        Rh rhesus;

        bool valid;
        bool filtered;

        void validate();

};

#endif // DONOR_H
