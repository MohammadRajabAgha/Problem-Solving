#include <iostream>

using namespace std;


int main()
{
    int a = 10;

    int b = 20;

    cout << "a Value = " << a << "\n";
    cout << "a address = " << &a << "\n\n";


    cout << "b Value = " << b << "\n";
    cout << "b address = " << &b << "\n\n";


    int* P = &a;

    cout << "Pointer Values = " << P << endl;
    cout << "The value Of The Address  = " << *P << endl;

    P = &b;
    cout << "Pointer Values = " << P << endl;
    cout << "The value Of The Address  = " << *P << endl;


    return 0;
}




