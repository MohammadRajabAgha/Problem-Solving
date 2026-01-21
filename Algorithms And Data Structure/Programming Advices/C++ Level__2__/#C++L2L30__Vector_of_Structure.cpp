#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stEmployee
{
    string FirstName;
    string LastName;
    float Salary;

};


int main()
{
    vector <stEmployee> vEmployees;

    stEmployee tempEmployee;

    tempEmployee.FirstName = "Mohammad";
    tempEmployee.LastName = "Rajab Agha";
    tempEmployee.Salary = 10000;
    
    vEmployees.push_back(tempEmployee);


    tempEmployee.FirstName = "Mohammad";
    tempEmployee.LastName = "Abu_Hadhoud";
    tempEmployee.Salary = 5000;
    
    vEmployees.push_back(tempEmployee);



    tempEmployee.FirstName = "Ali";
    tempEmployee.LastName = "Ahmed";
    tempEmployee.Salary = 3000;
    
    vEmployees.push_back(tempEmployee);

    cout << "Employees Vector : \n\n";

    for (stEmployee &Employee : vEmployees)
    {
        cout << "First Name : " << Employee.FirstName << endl;
        cout << "Last Name  : " << Employee.LastName << endl;
        cout << "Salary : " << Employee.Salary << endl;
        cout << endl;
    }

    cout << endl;




    return 0;
}

