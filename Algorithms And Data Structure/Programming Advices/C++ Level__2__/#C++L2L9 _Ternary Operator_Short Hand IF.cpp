#include<iostream>
#include <string>
#include "C:\Users\ASUS\MyLibrary\MyLibraries.h";

int main()
{
    int Mark = 0;
    string Result = "";

    Mark = ReadInputs::ReadFloatNumber("Please enter Your Mark ? ");
    cout << "\n";


   //First Way..
    Result = (Mark >= 50) ? "PASS" : "FAIL";
    cout << Result << "\n\n";


    //Second Way..
    cout << ((Mark >= 50) ? "PASS" : "FAIL");
    cout << "\n\n";


    //Third way..
    (Mark >= 50) ? cout << "PASS" : cout << "FAIL";
    cout << "\n\n";


    return 0;
}
