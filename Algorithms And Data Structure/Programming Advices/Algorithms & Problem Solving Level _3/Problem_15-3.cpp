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
            Matrix[i][j] = RandomNumber(1, 10);
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

short CountNumberInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
{
    
    short NumberCount = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number)
                NumberCount++;
        }
    }

    return NumberCount;

}

int main()
{ 
    srand((unsigned)time(NULL));

    int Matrix[3][3], Number;

    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix, 3, 3);

    cout << "Enter The Nubmer To Count in Matrix ? ";
    cin >> Number;

    cout << "\nNumber " << Number << " Count in Matrix is "
         << CountNumberInMatrix(Matrix, Number, 3, 3) << "\n\n";
   
     

    return 0;
}


