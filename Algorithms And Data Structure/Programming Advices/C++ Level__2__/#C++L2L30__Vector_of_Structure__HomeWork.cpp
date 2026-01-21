#include <iostream>
#include <string>
#include <vector>
#include "C:\Users\ASUS\MyLibrary\MyLibraries.h";

using namespace std;

struct stEmployee
{
    string FirstName;
    string LastName;
    float Salary;

};

void ReadEmployees(vector <stEmployee> &vEmployees)
{
    char ReadMore = 'Y';

    stEmployee tempEmployee;

    while (ReadMore == 'Y' || ReadMore == 'y')
    {
        tempEmployee.FirstName = ReadInputs::ReadText("Please enter Your First Name : ");
        tempEmployee.LastName = ReadInputs::ReadText("Please enter Your Last Name : ");
        tempEmployee.Salary = ReadInputs::ReadFloatNumber("Please enter Your Salary : ");

        vEmployees.push_back(tempEmployee);

        ReadMore = ReadInputs::ReadChar("\nDo You Want To Read More Employee ? [Y/N] ? ");

    }
}

void PrintEmployees(vector <stEmployee>& vEmployees)
{
    cout << "\nEmployees Vectore : \n\n";

    for (stEmployee &Employee : vEmployees)
    {
        cout << "First Name : " << Employee.FirstName << endl;
        cout << "Last Name  : " << Employee.LastName << endl;
        cout << "Salary : " << Employee.Salary << endl;
        cout << endl;
    }
    cout << endl;
}


int main()
{
    vector <stEmployee> vEmployees;

    ReadEmployees(vEmployees);

    PrintEmployees(vEmployees);

    return 0;
}

//#include <iostream>
//#include <string>
//#include <vector>
//#include "C:\Users\ASUS\MyLibrary\MyLibraries.h";
//
//using namespace std;
//
//struct stEmployee
//{
//    string FirstName;
//    string LastName;
//    float Salary;
//
//};
//
//void ReadEmployees(vector <stEmployee>& vEmployees)
//{
//    char ReadMore = 'Y';
//
//    stEmployee tempEmployee;
//
//    while (ReadMore == 'Y' || ReadMore == 'y')
//    {
//        tempEmployee.FirstName = ReadInputs::ReadText("Please enter Your First Name : ");
//        tempEmployee.LastName = ReadInputs::ReadText("Please enter Your Last Name : ");
//        tempEmployee.Salary = ReadInputs::ReadFloatNumber("Please enter Your Salary : ");
//
//        vEmployees.push_back(tempEmployee);
//
//        ReadMore = ReadInputs::ReadChar("Do You Want To Add More ? [Y/N] ? ");
//
//        cout << "\n\n**********************************************\n\n";
//    }
//}
//
//void PrintEmployees(const vector <stEmployee>& vEmployees)
//{
//    cout << "Employees Vectore : \n\n";
//
//    for (const stEmployee& Employee : vEmployees)
//    {
//        cout << "First Name : " << Employee.FirstName << endl;
//        cout << "Last Name  : " << Employee.LastName << endl;
//        cout << "Salary : " << Employee.Salary << endl;
//        cout << endl;
//    }
//    cout << endl;
//}
//
//
//
//int main()
//{
//    vector <stEmployee> vEmployees;
//
//    ReadEmployees(vEmployees);
//    PrintEmployees(vEmployees);
//
//    return 0;
//}
//
