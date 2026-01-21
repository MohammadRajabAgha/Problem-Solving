#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    fstream MyFile;

    //First File...
    MyFile.open("MyFile.txt", ios::out);//Write Mode...//Out Mode...

    if (MyFile.is_open())
    {
        MyFile << "Hi, This is The first Line\n";
        MyFile << "Hi, This is The Second Line \n";
        MyFile << "Hi, This is The Third Line\n";


        MyFile.close();
    }
    else
    {
        cout << "Error\n";
    }


    //Second File...
    MyFile.open("C:\\Users\\ASUS\\Documents\\MyFile.txt", ios::out);//Write Mode...

    if (MyFile.is_open())
    {
        MyFile << "This is The Information That I Saved In File In C:\\ \n";
        MyFile << "This is The Information That I Saved In File In User \n";
        MyFile << "This is The Information That I Saved In File In Asus \n";
        MyFile << "This is The Information That I Saved In File In Documents \n";
        MyFile << "This is The Information That I Saved In File In Documents \n";

        MyFile.close();
    }
    else
    {
        cout << "Error\n";
    }

    return 0;
}


//#include <iostream>
//#include "C:\Users\ASUS\MyLibrary\MyLibraries.h"
//#include<vector>
//#include<fstream>
//#include<iomanip>
//
//using namespace std;
//
//struct stEmployees
//{
//    string FirstName;
//    string LastName;
//    string FullName;
//    short Age = 0;
//    float Salary = 0;
//};
//
//
//void ReadEmployeesVector(vector <stEmployees>& vEmployees)
//{
//    stEmployees TempEmployee;
//
//    char ReadMore = 'Y';
//
//    cout << "Read Employees Information : \n\n";
//
//    do
//    {
//        TempEmployee.FirstName = ReadInputs::ReadText("Please enter Your First Name ? ");
//        TempEmployee.LastName = ReadInputs::ReadText("Please enter Your Last Name ? ");
//        TempEmployee.FullName = ReadInputs::GetFullName(TempEmployee.FirstName, TempEmployee.LastName);
//        TempEmployee.Age = ReadInputs::ReadShortNumber("Please enter Your Age ? ");
//        TempEmployee.Salary = ReadInputs::ReadFloatNumber("PLease enter Your Salary ? ");
//
//        vEmployees.push_back(TempEmployee);
//
//        ReadMore = ReadInputs::ReadChar("\nDo You Want To Add More Employee? [Y/N] ? ");
//
//    } while (ReadMore == 'Y' || ReadMore == 'y');
//}
//
//void PrintVectorInFile(vector <stEmployees>& vEmployees)
//{
//    fstream VectorFile;
//
//    VectorFile.open("VectorFile.txt", ios::out);//Write Mode...
//
//    if (VectorFile.is_open())
//    {
//        VectorFile << "Employees Information : \n";
//
//        for (short i = 0; i < vEmployees.size(); i++)
//        {
//            VectorFile << "*************************\n\n";
//            VectorFile << "Employee N." << i + 1 << endl;
//            VectorFile << "Full Name : " << vEmployees[i].FullName << endl;
//            VectorFile << "Salary : " << vEmployees[i].Salary << endl;
//            VectorFile << "Age : " << vEmployees[i].Age << endl;
//        }
//        VectorFile.close();
//    }
//
//}
//
//int main()
//{
//    vector <stEmployees> vEmployees;
//
//    ReadEmployeesVector(vEmployees);
//    PrintVectorInFile(vEmployees);
//
//
//
//    return 0;
//
//}