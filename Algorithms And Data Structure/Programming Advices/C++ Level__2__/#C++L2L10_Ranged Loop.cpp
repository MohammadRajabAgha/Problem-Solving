#include <iostream>

using namespace std;

int main()
{
    int Array1[] = { 10, 20, 30, 40,50 };
    
    for (int n : Array1)
    {
        cout << n << endl; 
    }
    
    cout << "\n**************************************\n\n";

    for (int n : {5, 1, 2, 47, 4, 56, 65})
    {
        cout << n << endl;
    }

    cout << "\n**************************************\n\n";

    for (int &N : Array1)
    {
        N = N * 5;
        cout << N << endl;
    }




    return 0;
}