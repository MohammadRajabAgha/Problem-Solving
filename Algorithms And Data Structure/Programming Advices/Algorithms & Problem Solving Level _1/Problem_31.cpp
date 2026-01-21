#include <iostream>
#include <cmath>  
#include<string>
using namespace std;

int ReadNumber(string Message)
{
    int Number;
    cout << Message << endl;
    cin >> Number;

    return Number;
}

void PowerOf2_3_4(int Num)
{
    cout << "************************\n";
    int a, b, c;

    a = Num * Num;
    b = Num * Num * Num;
    c = Num * Num * Num * Num;
    cout << a << " " << b << " " << c << endl;
}
int main() 
{
    

   
    PowerOf2_3_4(ReadNumber("Pleas enter a number?"));

    return 0;
}