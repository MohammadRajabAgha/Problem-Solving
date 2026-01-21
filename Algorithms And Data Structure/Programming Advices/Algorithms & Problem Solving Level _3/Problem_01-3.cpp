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

int main()
{
    srand((unsigned)time(NULL));

    int Arr[3][3];

    FillMatrixWithRandomNumbers(Arr, 3, 3);
    cout << "The Following is a 3*3 Random Matrix : \n";
    PrintMatrix(Arr, 3, 3);


    system("pause");
}
