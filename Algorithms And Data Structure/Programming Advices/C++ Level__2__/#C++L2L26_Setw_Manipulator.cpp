#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    cout << "____________________________________________" << endl;
    cout << "|" << left << setw(10) << "Code" << "|" << left << setw(20) << "Name" << "|" << left << setw(10) << "Mark" << "|" << endl;
    cout << "|__________|____________________|__________|" << endl;
    cout << "|" << left << setw(10) << "C101" << "|" << left << setw(20) << "Introuduction To C++" << "|" << left << setw(10) << "90" << "|" << endl;
    cout << "|" << left << setw(10) << "C102" << "|" << left << setw(20) << "C++ Level 1" << "|" << left << setw(10) << "93" << "|" << endl;
    cout << "|" << left << setw(10) << "C103" << "|" << left << setw(20) << "Algorithms and DS" << "|" << left << setw(10) << "85" << "|" << endl; 
    cout << "|__________|____________________|__________|" << endl;

    cout << "\n************************************************************\n";

    cout << "Before Shift \n\n";

    cout << "---------------------------------------------------\n";
    cout << "  code   |             Name            |   Mark   |\n";
    cout << "---------|-----------------------------|----------|\n";
    cout << left << setw(9) << "C101" << "|" << left << setw(29) << "Introductio To Programming 1" << "|" << left << setw(10) << "99" << "|" << endl;
    cout << left << setw(9) << "C102" << "|" << left << setw(29) << "Cal_1" << "|" << left << setw(10) << "85" << "|" << endl;
    cout << left << setw(9) << "C1031" << "|" << left << setw(29) << "DM" << "|" << left << setw(10) << "89" << "|" << endl;
    cout << "---------|-----------------------------|----------|\n";


    cout << "\nAfter Shift \n\n";

    cout << "___________________________________________________\n";
    cout << "  code   |             Name            |   Mark   |\n";
    cout << "_________|_____________________________|__________|\n";
    cout << left << setw(9) << "C101" << "|" << left << setw(29) << "Introductio To Programming 1" << "|" << left << setw(10) << "99" << "|" << endl;
    cout << left << setw(9) << "C102" << "|" << left << setw(29) << "Cal_1" << "|" << left << setw(10) << "85" << "|" << endl;
    cout << left << setw(9) << "C1031" << "|" << left << setw(29) << "DM" << "|" << left << setw(10) << "89" << "|" << endl;
    cout << "_________|_____________________________|__________|\n";





    return 0;
}

