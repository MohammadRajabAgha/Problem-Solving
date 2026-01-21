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

void PrintMiddleRowInMatrix(int Matrix[3][3], short Rows, short Cols)
{

    short MiddleRow = Rows / 2;


    for (short j = 0; j < Cols; j++)
    {
        printf(" %0*d   ", 2, Matrix[MiddleRow][j]);
    }

    cout << endl;

}

void PrintMiddleColInMatrix(int Matrix[3][3], short Rows, short Cols)
{

    short MiddleCol = Cols / 2;

    for (short i = 0; i < Rows; i++)
    {
        printf(" %0*d   ", 2, Matrix[i][MiddleCol]);
    }

    cout << endl;

}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix[3][3];

    FillMatrixWithRandomNumbers(Matrix, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix, 3, 3);

    cout << "Middle Row Of Matrix :\n";
    PrintMiddleRowInMatrix(Matrix, 3, 3);

    cout << "\nMiddle Col Of Matrix : \n";
    PrintMiddleColInMatrix(Matrix, 3, 3);

    system("pause>0");
}


//#include <iostream>
//#include<cstdlib>
//#include <iomanip>
//#include<cmath>
//
//using namespace std;
//
//int RandomNumber(int From, int To)
//{
//    int  randNum = 0;
//
//    randNum = From + rand() % (To - From + 1);
//
//    return  randNum;
//}
//
//void FillMatrixWithRandonNumbers(int Matrix[3][3], short Rows, short Cols)
//{
//    for (short i = 0; i < Rows; i++)
//    {
//        for (short j = 0; j < Cols; j++)
//        {
//            Matrix[i][j] = RandomNumber(1, 10);
//        }
//    }
//}
//
//void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
//{
//    for (short i = 0; i < Rows; i++)
//    {
//        for (short j = 0; j < Cols; j++)
//        {
//            // cout << setw(3) << Arr[i][j] << "     ";
//            printf(" %0*d   ", 2, Matrix[i][j]);
//        }
//
//        cout << "\n";
//    }
//
//    cout << endl;
//
//}
//
//void PrintMiddleRowInMatrix(int Matrix[3][3], short Rows, short Cols)
//{
//
//    if (Rows == 1 || Rows == 2)
//        return;
//
//
//    for (short i = 0; i < Rows; i++)
//    {
//        for (short j = 0; j < Cols; j++)
//        {
//            if (i == floor(Rows / 2))
//            {
//                printf(" %0*d   ", 2, Matrix[i][j]);
//            }
//        }
//    }
//
//    cout << endl;
//
//}
//
//void PrintMiddleColInMatrix(int Matrix[3][3], short Rows, short Cols)
//{
//
//    if (Cols == 1 || Cols == 2)
//        return;
//
//    for (short i = 0; i < Rows; i++)
//    {
//        for (short j = 0; j < Cols; j++)
//        {
//            if (j == floor(Cols / 2))
//            {
//                printf(" %0*d   ", 2, Matrix[i][j]);
//            }
//        }
//    }
//
//    cout << endl;
//
//}
//
//
//int main()
//{
//    srand((unsigned)time(NULL));
//
//    int Matrix[3][3];
//
//    FillMatrixWithRandonNumbers(Matrix, 3, 3);
//    cout << "Matrix1: \n";
//    PrintMatrix(Matrix, 3, 3);
//
//    cout << "Middle Row Of Matrix :\n";
//    PrintMiddleRowInMatrix(Matrix, 3, 3);
//
//    cout << "\nMiddle Col Of Matrix : \n";
//    PrintMiddleColInMatrix(Matrix, 3, 3);
//
//    system("pause>0");
//}