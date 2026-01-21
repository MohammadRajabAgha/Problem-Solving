#include <iostream>   
#include <string>     
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

void PrintNumberPattern(int Num)
{

    cout << "\n";

    for (int i = 1; i <= Num; i++)
    {
        

        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << "\n";
    }
    
}

int main()
{
    PrintNumberPattern(ReadPositiveNumber("PLeas enter a Positive Number?"));


    return 0;
}