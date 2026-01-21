#include <iostream>

using namespace std;

struct stEmployee
{
    string FullName;
    float Salary;
    char Char1 = 'h';
    char* vChar2;
};


int main()
{
    stEmployee Employee1, * ptr;

    char Char = 'P';

    Employee1.vChar2 = &Char;

    Employee1.FullName = "Mohammad Rajab Agha";
    Employee1.Salary = 5000;


    //The Normal Way To Print Info in StEmployee...
    cout << "The Normal Way To Print Info in StEmployee...\n\n";
    cout << Employee1.FullName << endl;
    cout << Employee1.Salary << endl;
    cout << Employee1.Char1 << endl;
    cout << *Employee1.vChar2 << endl;

    cout << "\n******\n";
    
    cout << "The Adress in pointer : \n\n";

    cout << (void*)Employee1.vChar2 << endl;
    cout << (void*)&Char << endl;

    cout << "\n******\n";

    cout << "The Addresses Of Struct : \n\n";

    cout << &Employee1.FullName << endl;
    cout << &Employee1.Salary << endl;
    cout << (void*)&Employee1.Char1 << endl;
    cout << &Employee1.vChar2 << endl;

    cout << "\n******\n";

    ptr = &Employee1;

    cout << "Using Pointer\n\n";

    cout << ptr->FullName << endl;
    cout << ptr->Salary << endl;
    cout << ptr->Char1 << endl;
    //
    cout << "Pointer Char : " << *(ptr->vChar2) << endl;//Pointer To Pointer Important
    //

    cout << "\n******\n";

    cout << (*ptr).FullName << endl;
    cout << (*ptr).Char1 << endl;
    cout << (*ptr).Salary << endl;
    cout << *(ptr->vChar2) << endl;

    cout << "\n******\n";
    cout << "The Addresses Of Struct By pointer : \n\n";
   
    cout << &ptr->FullName << endl;
    cout << &ptr->Salary << endl;
    cout << (void*) & ptr->Char1 << endl;
    cout << (void*) & Char << endl;
    cout << (void*)ptr->vChar2 << endl;

    //خد بالك البوينتر بيشر علي اول عنصر في الستركشر زي الاراي و الستركشر تشير ايضا الى اول عنصر 

    cout << "\n\n" << ptr << endl;
    cout << &Employee1 << endl;
    cout << &Employee1.FullName << endl;



    return 0;
}



//The Exeplanatoin...

//#include <iostream>
//
//using namespace std;
//
//struct stEmployee
//{
//    string FullName;
//    float Salary;
//    char Char1 = 'h';
//    char* vChar2;
//};
//
//
//
//
//int main()
//{
//    stEmployee Employee1, * ptr;
//
//    char Char = 'M';
//
//    Employee1.vChar2 = &Char;
//
//    Employee1.FullName = "Mohammad Agha";
//    Employee1.Salary = 5000;
//
//
//    /*cout << "************\n";
//
//    cout << Employee1.FullName << endl;
//    cout << Employee1.Salary << endl;
//    cout << Employee1.Char1 << endl;
//    cout << *Employee1.vChar2 << endl;*/
//
//
//
//    /*cout << "************\n";
//
//    cout << (void*)Employee1.vChar2 << endl;
//    cout << (void*)&Char << endl;*/
//
//    ptr = &Employee1;
//
//    /*cout << "************\n";
//
//    cout << ptr->FullName << endl;
//    cout<<(*ptr).FullName<<endl;*/
//
//
//    /*  cout << "************\n";
//
//      cout << ptr << endl;
//      cout << &Employee1 << endl;*/
//
//
//      /*  cout << "************\n";
//
//        cout <<(void*) & ptr->Char1 << endl;
//        cout << (void*)&Employee1.Char1 << endl;*/
//
//
//        /* cout << "************\n";
//
//         cout <<(void*) ptr->vChar2 << endl;
//         cout << (void*)&Char << endl;*/
//
//
//
//
//    return 0;
//}


//The Exeplanatoin2...

//Important...


//#include <iostream>
//#include<cstdio>
//#include<string>
//#include "C:\Users\ASUS\MyLibrary\MyLibraries.h"
//#include<iomanip>
//
//using namespace std;
//
//struct stEmployee
//{
//    string FullName;
//    float Salary;
//    char Char1;
//    char* vChar2;
//};
//
//int main()
//{
//    stEmployee Employee1;
//    stEmployee* ptr;
//    char Char3 = 'P';
//
//    ptr = &Employee1;
//
//    ptr->FullName = ReadInputs::ReadText("Pleae Ente Youe Full Name : ");
//    ptr->Salary = ReadInputs::ReadFloatNumber("Please enter Your Salary : ");
//    ptr->Char1 = ReadInputs::ReadChar("Please enter Character : ");
//    ptr->vChar2 = &Char3;
//
//
//    cout << "\n********************************\n";
//
//    cout << "Full Name : " << ptr->FullName << endl;
//    cout << "Salary : " << ptr->Salary << endl;
//    cout << "The Character IS : " << ptr->Char1 << endl;
//    cout << "The Char By ptr Is : " << *(ptr->vChar2) << endl;
//
//
//
//    return 0;
//}
//
//
//
//
