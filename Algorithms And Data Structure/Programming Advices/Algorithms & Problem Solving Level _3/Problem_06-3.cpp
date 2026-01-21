#include <iostream>

using namespace std;

void FillMatrixWithOrderedNumbers(int Arr[3][3], short Rows, short Cols)
{
    int Counter = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            //Arr[i][j] = ++Counter;         ||->
            Counter++;
            Arr[i][j] = Counter;
        }
    }
}

void PrintMatrix(int Arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << Arr[i][j] << "     ";
        }
        cout << "\n";
    }
}

int main()
{
    int Arr[3][3];

    FillMatrixWithOrderedNumbers(Arr, 3, 3);
    cout << "The Following is a 3*3 Order Matrix : \n";
    PrintMatrix(Arr, 3, 3);

    return 0;

}

