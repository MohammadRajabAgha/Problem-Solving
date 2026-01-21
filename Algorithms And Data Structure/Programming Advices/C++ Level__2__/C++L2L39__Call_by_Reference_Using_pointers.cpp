#include <iostream>
#include<string>

using namespace std;

void SwaByPrt(int *Num1, int *Num2)
{
    int temp = 0;

    temp = *Num1;
    *Num1 =*Num2;
    *Num2 = temp;

}

void SwaByRef(int& Num1, int& Num2)
{
    int temp = 0;

    temp = Num1;
    Num1 = Num2;
    Num2 = temp;
}

int main()
{

    int a = 1, b = 2;


    cout << "Before Swaping \n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;


    SwaByPrt(&a, &b);
    //SwaByRef(a,b)


    cout << "After  Swaping \n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;



    return 0;
}

