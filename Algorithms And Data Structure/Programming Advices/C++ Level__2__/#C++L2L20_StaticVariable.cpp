#include <iostream>

using namespace std;

void MyFun()
{
    static int Num = 1;

    cout << Num << "\n";

    Num++;
}


int main()
{
    MyFun();//1
    MyFun();//2
    MyFun();//3


    return 0;

}

