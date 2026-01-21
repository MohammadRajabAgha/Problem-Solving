#include <iostream>

using namespace std;

void FillMatrixWithOrderedNumbers(int Arr[3][3], short Rows, short Cols)
{
    int Counter = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
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

    cout << endl;

}

void TransposeMatrix(int Arr[3][3], int ArrTransposed[3][3], int Rows, int Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            ArrTransposed[i][j] = Arr[j][i];
        }
    }
}

int main()
{
    int Arr[3][3];
    int ArrTransposed[3][3];

    FillMatrixWithOrderedNumbers(Arr, 3, 3);
    cout << "The Following is a 3*3 Order Matrix : \n";
    PrintMatrix(Arr, 3, 3);

    TransposeMatrix(Arr, ArrTransposed, 3, 3);

    cout << "The Following is The Transposed Matrix : \n";
    PrintMatrix(ArrTransposed, 3, 3);

    return 0;

}

