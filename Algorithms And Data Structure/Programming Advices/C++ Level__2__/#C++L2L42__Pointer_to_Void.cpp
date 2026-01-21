#include <iostream>

using namespace std;

struct stInfo
{
    string Name = "Mohammad Agha";
    string Phone = "0988212317";
};

int main()
{
    
    void* ptr;

    int X = 50;

    float Y = 20.5;

    ptr = &X;

    cout << &X << endl;
    cout << ptr << endl;
    //cout << *ptr << endl;//ERROR....
    cout << *(int*)(ptr) << endl;
    cout << *((int*)(ptr)) << endl;
    cout << *(static_cast<int*>(ptr)) << endl;

    cout << "\n********************\n";

    ptr = &Y;

    cout << &Y << endl;
    cout << ptr << endl;
    //cout << *ptr << endl;//ERROR....
    cout << *(float*)(ptr) << endl;
    cout << *((float*)(ptr)) << endl;
    cout << *(static_cast<float*>(ptr)) << endl;

    cout << "\n********************\n";


    stInfo Info;

    ptr = &Info;
                                 
    cout << ptr << endl;
   // cout << *ptr << endl;//ERROR...
    cout << ((stInfo*)(ptr))->Name << endl;
    cout << ((stInfo*)(ptr))->Phone << endl;


    cout << (static_cast<stInfo*>(ptr))->Name << endl;
    cout << (static_cast<stInfo*>(ptr))->Phone << endl;



    cout << "\n********************\n";


    return 0;

}

