#include<iostream>

using namespace std;

void Function1(int X)
{
    X++;
    cout << &X << endl;
}

int main()
{
    int a = 10;

    cout << "Function 1: ";
    Function1(a);

    cout << "\n a : ";
    cout << a << endl;
    cout << &a << endl;

    return 0;

}