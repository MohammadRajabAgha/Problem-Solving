#include <iostream>
#include<cstdlib>
#include <iomanip>
#include<cmath>

using namespace std;

int RandomNumber(int From, int To)
{
    int  randNum = 0;

    randNum = From + rand() % (To - From + 1);

    return  randNum;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            // cout << setw(3) << Arr[i][j] << "     ";
            printf(" %0*d   ", 2, Matrix[i][j]);
        }

        cout << "\n";
    }

    cout << endl;

}

bool IsNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number)
            {
                return true;
            }
        }
    }

    return false;

}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3], Number;

    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix: \n";
    PrintMatrix(Matrix, 3, 3);

    cout << "Please enter The Number To Look For in the Matrix ? ";
    cin >> Number;

    if (IsNumberInMatrix(Matrix,Number, 3, 3))
    {
        cout << "\nYes : It is There.\n";
    }
    else
    {
        cout << "\nNo : It's NOT There.\n";
    }

    return 0;
}


