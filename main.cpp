#include <iostream>
#include "./include/Donor_list.h"
#include "./include/Donor.h"

using namespace std;

int main()
{

    Donor_list listy("idonors.txt");

    listy.print(detailed_op);

    cout << '\n';

    listy.filter(rhesus, "positive", false);

    cout << '\n' << "Filtered once: " << '\n' << '\n';

    listy.print_filtered();

    cout << '\n';

    listy.filter(age, ">75", true);

    cout << '\n' << "Filtered twice: " << '\n' << '\n';

    listy.print_filtered();




}
