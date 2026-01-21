#include <iostream>
#include<cstdlib>
#include<iomanip>
#include<string>

using namespace std;

int RandomNumber(int From, int To)
{
    int  randNum = 0;

    randNum = From + rand() % (To - From + 1);

    return  randNum;
}

void FillMatrixWithRandomNumbers(int Arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Arr[i][j] = RandomNumber(1, 100);
        }
    }
}

void PrintMatrix(int Arr[3][3], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(3) << Arr[i][j] << "     ";
        }

        cout << endl;
    }
}

int ColSumInMatrix(int Arr[3][3], short Rows, short ColsNumber)
{
    int Sum = 0;

    for (short i = 0; i < Rows; i++)
    {
        Sum += Arr[i][ColsNumber];
    }
    return Sum;
}

void SumMatrixColsInArray(int Arr[3][3], int ColsSumArr[3], short Rows, short Cols)
{
    for (short i = 0; i < Cols; i++)
    {
        ColsSumArr[i] = ColSumInMatrix(Arr, Rows, i);
    }
}

void PrintColsSumArr(int ColsSumArr[3], short Cols)
{
    cout << "\nThe Following are the sum of each col in the matirx : \n";

    for (short j = 0; j < Cols; j++)
    {
        cout << "Col " << j + 1 << " Sum = " << ColsSumArr[j] << "\n";
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Arr[3][3];
    int ColsSumArr[3];

    FillMatrixWithRandomNumbers(Arr, 3, 3);
    cout << "The Following is a 3*3 Random Matrix : \n";
    PrintMatrix(Arr, 3, 3);

    SumMatrixColsInArray(Arr, ColsSumArr, 3, 3);

    PrintColsSumArr(ColsSumArr, 3);

    return 0;
}
