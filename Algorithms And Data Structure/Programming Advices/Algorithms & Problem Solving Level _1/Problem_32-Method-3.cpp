#include <iostream>
using namespace std;

int Powerfunction(int Num, int M)
{
    int power = 1;
    for (int i = 1; i <= M; i++)
    {
        power = power * Num;
    }

    return power;
}


int main()
{
    int Num, M;
    cout << "Pleas enter The Number\n";
    cin >> Num;

    cout << "Pleas enter Pow\n";
    cin >> M;

    cout << "The Power is: " << Powerfunction(Num, M) << endl;


    return 0;
}