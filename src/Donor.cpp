#include "Donor.h"

gender str2gen(string s) {

    if ( s == "male" || s == "Male" || s == "M") {
        return male;
    } else if ( s == "female" || s == "Female" || s == "F") {
        return female;
    } else if ( s == "Other") {
        return other;
    } else {
        return unknown_gender;
    }
}

string gen2str(gender g) {

    switch(g) {
        case male:
            return "male";
        case female:
            return "female";
        case other:
            return "other";
        default:
            return "unknown gender";
    }
}

blood str2blood(string s) {

    if( s == "0" || s == "O") {
        return O;
    } else if( s == "A") {
        return A;
    } else if( s == "B") {
        return B;
    } else if( s == "AB") {
        return AB;
    } else {
        return alien;
    }

}

string blood2str(blood b) {

    switch(b) {
        case O:
            return "O";
        case A:
            return "A";
        case B:
            return "B";
        case AB:
            return "AB";
        default:
            return "alien";
    }
}

Rh str2rh(string s) {

    if( s == "positive" || s == "+" || s == "(Rh+)") {
        return positive;
    } else if( s == "negative" || s == "-" || s == "(Rh-)") {
        return negative;
    } else {
        return unknown_Rh;
    }

}

string rh2str(Rh rh) {

    switch(rh) {
        case positive:
            return "positive";
        case negative:
            return "negative";
        default:
            return "unknown Rh";
    }
}

enum comparisons {equals, greater_than, less_than};

comparisons compare_strings(string a, string b) {

    for (int i=0; i < min(a.length(), b.length()); i++) {

        if( int(a[i]) < int(b[i]) ) {

            return less_than;

        } else if ( int(a[i]) > int(b[i]) ) {

            return greater_than;

        }

    }

    if (a.length() < b.length()) {
        return less_than;
    } else if (a.length() > b.length()) {
        return greater_than;
    }

    return equals;

}

int nSubstrings(string s, string sub_s) {

    int counter = 0;
    bool found = true;
    int pos;

    while (found) {

        pos = s.find(sub_s);

        if(pos >= 0 && pos <= s.length()) {

            counter++;
            s = s.substr(pos+sub_s.length(), s.length()-sub_s.length());

        } else found = false;

    }

    return counter;

}


Donor::Donor(string f_name, string l_name, gender g, int d, int m, int y, blood b, Rh rh)
{
    valid = true;

    set_first_name(f_name);
    set_last_name(l_name);
    set_gender(g);
    set_day(d);
    set_month(m);
    set_year(y);
    set_blood(b);
    set_rhesus(rh);
}

Donor::Donor(string f_name, string l_name, string g, string d, string m, string y, string b, string rh)
{
    valid = true;

    set_first_name(f_name);
    set_last_name(l_name);
    set_gender(g);
    set_day(d);
    set_month(m);
    set_year(y);
    set_blood(b);
    set_rhesus(rh);

}

Donor::Donor(string info) {

    valid = true;

    int n = 6;
    string arr[n];
    int delim_idx;
    int i = 0;

    arr[0] = "0";
    arr[1] = "0";
    arr[2] = "0";
    arr[3] = "0/0/0";
    arr[4] = "0";
    arr[5] = "0";

    do {

        delim_idx = info.find(delim_info);

        if(delim_idx > 0 && delim_idx < info.length()) {

            arr[i] = info.substr(0, delim_idx);
            info = info.substr(delim_idx + delim_info.length(), info.length() - delim_idx - delim_info.length());
            i++;

        } else if (i == 5){
            arr[i] = info;
        } else {
            arr[i] = "0";
        }

    } while(delim_idx > 0);

    set_first_name(arr[0]);
    set_last_name(arr[1]);
    set_gender(arr[2]);
    set_blood(arr[4]);
    set_rhesus(arr[5]);

    string date[3];

    for (int j = 0; j < 3; j++) {

        delim_idx = arr[3].find(delim_date);

        if (delim_idx > 0) {

            string temp = arr[3].substr(0, delim_idx);
            date[j] = temp;
            arr[3] = arr[3].substr(delim_idx+1, arr[3].length() - delim_idx - delim_date.length());

        } else if (j==2) {

            date[j] = arr[3];
        } else {
            date[j] = "0";
        }

    }

    set_day(date[0]);
    set_month(date[1]);
    set_year(date[2]);

}

Donor::~Donor(){

}

string Donor::get_first_name() {
    return first_name;
}

string Donor::get_last_name() {
    return last_name;
}
string Donor::get_full_name() {
    return last_name + " " + first_name;
}

string Donor::get_short_name() {
    return last_name + " " + first_name.substr(0, 1) + ".";
}

string Donor::get_bday() {
    return to_string(day) + delim_date + to_string(month) + delim_date + to_string(year);
}

gender Donor::get_gender() {
    return gen;
}

string Donor::get_gender_str() {
    return gen2str(gen);
}

blood Donor::get_blood_type() {
    return b_group;
}

string Donor::get_blood_type_str() {
    return blood2str(b_group);
}

Rh Donor::get_rh() {
    return rhesus;
}

string Donor::get_rh_str() {
    return rh2str(rhesus);
}

bool Donor::is_year_leap() {

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }

    return false;
}

int Donor::get_year() {
    return year;
}


int Donor::get_age() {
    return 2019 - year; // TODO: погуглить, как получать дату
}

string Donor::str(output_type ot) {

    switch(ot) {

        case full_op:
            return (last_name + " " + first_name + " " + get_bday() + " " + get_blood_type_str() + " " +
                get_rh_str());

        case short_op:
            return (last_name + " " + first_name.substr(0, 1) + ". " + to_string(get_age()) + " " +
                get_blood_type_str()) + " " +  get_rh_str();

        case detailed_op:
            return (last_name + " " + first_name + " " + to_string(day) + "/" +
                to_string(month) + "/" + to_string(year) + " " + gen2str(gen) + " " +
                get_blood_type_str()) + " " +  get_rh_str();

        default:
            return (last_name + " " + first_name + " " + to_string(get_age()) + " " + get_blood_type_str() +
                " " + get_rh_str());

    }
}

bool Donor::compare(Donor *d, string oper, comp_criterion comp) {

    switch (comp) {

        case by_age:

            if (oper == "<") {

                return get_age() < d->get_age();

            } else if (oper == ">") {

                return get_age() > d->get_age();

            } else if (oper == "<=") {

                return get_age() <= d->get_age();

            } else if (oper == ">=") {

                return get_age() >= d->get_age();

            } else if (oper == "==") {

                return get_age() == d->get_age();

            } else {

                return false;

            }

        case by_year:

            if (oper == "<") {

                return get_year() < d->get_year();

            } else if (oper == ">") {

                return get_year() > d->get_year();

            } else if (oper == "<=") {

                return get_year() <= d->get_year();

            } else if (oper == ">=") {

                return get_year() >= d->get_year();

            } else if (oper == "==") {

                return get_year() == d->get_year();

            } else {

                return false;

            }

        case by_name:

            comparisons res = compare_strings(get_full_name(), d->get_full_name());

            if (oper == "<") {

                    switch (res) {
                        case equals:
                            return false;
                        case less_than:
                            return true;
                        case greater_than:
                            return false;
                    }

                } else if (oper == ">") {

                    switch (res) {
                        case equals:
                            return false;
                        case less_than:
                            return false;
                        case greater_than:
                            return true;
                    }

                } else if (oper == "<=") {

                    switch (res) {
                        case equals:
                            return true;
                        case less_than:
                            return true;
                        case greater_than:
                            return false;
                    }

                } else if (oper == ">=") {

                    switch (res) {
                        case equals:
                            return true;
                        case less_than:
                            return false;
                        case greater_than:
                            return true;
                    }

                } else if (oper == "==") {

                    switch (res) {
                        case equals:
                            return true;
                        case less_than:
                            return false;
                        case greater_than:
                            return false;
                    }

                }

        }

        return false;
}


void Donor::set_first_name(string f_name) {
    if (f_name.length() > 0 ) {

        first_name = f_name;
        if(!valid) {
            validate();
        }

    } else {

        valid = false;
        f_name = "NA";
    }
}

void Donor::set_last_name(string l_name) {
    if (l_name.length() > 0 ) {

        last_name = l_name;
        if(!valid) {
            validate();
        }

    } else {
        valid = false;
        l_name = "NA";
    }
}

void Donor::set_gender (gender g) {

     gen = g;

     if (g == unknown_gender ) {
        valid = false;
     } else if(!valid) {
        validate();
    }
}

void Donor::set_day(int d) {

    if (d > 0 && d < 32) {

        day = d;
        if(!valid) {
            validate();
        }

    } else {
        day = 0;
        valid = false;
    }

}

void Donor::set_month(int m) {

    if (m > 0 && m < 13) {

        month = m;
        if(!valid) {
            validate();
        }

    } else {
        month = 0;
        valid = false;
    }

}

void Donor::set_year(int y) {

    if (y > 1800 && y < 2020) {

        year = y;
        if(!valid) {
            validate();
        }

    } else {
        year = 0;
        valid = false;
    }

}

void Donor::set_blood(blood b) {

    b_group = b;

    if(b == alien) {
        valid = false;
    } else if(!valid) {
        validate();
    }

}

void Donor::set_rhesus(Rh rh) {

    rhesus = rh;

    if(rh == unknown_Rh) {
        valid = false;
    } else if(!valid) {
        validate();
    }

}

void Donor::set_gender (string g) {

     set_gender(str2gen(g));

}

void Donor::set_day(string d) {

    set_day(stoi(d));

}

void Donor::set_month(string m) {

    set_month(stoi(m));

}

void Donor::set_year(string y) {

    set_year(stoi(y));

}

void Donor::set_blood(string b) {

    set_blood(str2blood(b));

}

void Donor::set_rhesus(string rh) {

    set_rhesus(str2rh(rh));

}

void Donor::validate() {

    if ( (day > 0 && day < 32) &&
         (month > 0 && month < 13) &&
         (year > 1800 && year < 2020) &&
         (b_group != alien) &&
         (rhesus != unknown_Rh) &&
         (last_name.length() > 0) &&
         (first_name.length() > 0)

       ) {
            valid = true;
       } else {
            valid = false;
        }


}

bool Donor::is_valid() {

    return valid;

}


void Donor::set_filter(gender g, bool more) {

    filtered = (gen == g);

}

void Donor::set_filter(blood b, bool more) {

    filtered = ( (more && (filtered && (b_group == b))) ||
                       (!more && (b_group == b)) );

}

void Donor::set_filter(Rh r, bool more) {

    filtered = ( (more && (filtered && (rhesus == r))) ||
                       (!more && (rhesus == r)) );

}

void Donor::set_filter(int age, char cond, bool more) {

    switch(cond) {

        case '>':
            filtered = ( (more && (filtered && (get_age() > age))) ||
                       (!more && (get_age() > age)) ) ;
            break;
        case '<':
            filtered = ( (more && (filtered && (get_age() < age))) ||
                       (!more && (get_age() < age)) ) ;
            break;
        case '=':
            filtered = ( (more && (filtered && (get_age() == age))) ||
                       (!more && (get_age() == age)) ) ;
            break;
        default:
            break;

    }
}

bool Donor::get_filter() {

    return filtered;

}





