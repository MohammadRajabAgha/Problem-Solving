#include <iostream>

using namespace std;

int main()
{
    int* ptrX;

    float* ptrY;

    ptrX = new int;
    ptrY = new float;

    *ptrX = 45;
    *ptrY = 58.23f;

    cout << *ptrX << endl;
    cout << *ptrY << endl;

    cout << "\n*******************************************\n";

    cout << ptrX << endl;
    cout << ptrY << endl;

    cout << "\n*******************************************\n";

    cout << &ptrX << endl;
    cout << &ptrY << endl;

    cout << "\n*******************************************\n";


    delete ptrX;
    delete ptrY;


    return 0;
}

