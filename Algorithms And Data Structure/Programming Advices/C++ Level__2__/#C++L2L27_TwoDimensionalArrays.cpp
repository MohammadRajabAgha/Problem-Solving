#include <iostream>
#include <string>

using namespace std;

int main()
{
    //<T> std::Array[Row][Column]...
    int Arr[3][4] =
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };


    for (int i = 0; i < 3; i++)//Row
    {
        for (int j = 0; j < 4; j++)//Column
        {
            cout << Arr[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}

