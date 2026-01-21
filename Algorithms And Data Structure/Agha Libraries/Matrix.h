#pragma once

#pragma warning(disable : 4996)

#include<iostream>
#include<iomanip>

using namespace std;

namespace Matrix
{
    void FillMatrixWithRandomNumbers(int Matrix[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                Matrix[i][j] = NumberManipulater::RandomNumber(1, 100);
            }
        }
    }

    void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                cout << setw(3) << Matrix[i][j] << "     ";
            }
            cout << endl;
        }
    }

    int RowSumInMatrix(int Matrix[3][3], short RowNumber, short Cols)
    {
        int Sum = 0;

        for (short j = 0; j < Cols; j++)
        {
            Sum += Matrix[RowNumber][j];
        }

        return Sum;
    }

    void PrintEachRowSumInMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        cout << "\nThe Following are the Sum of each row in matrix : \n\n";

        for (short i = 0; i < Rows; i++)
        {
            cout << "Row " << i + 1 << " Sum = " << RowSumInMatrix(Matrix, i, Cols) << "\n";
        }

    }

    void SumMatrixRowsInArray(int Matrix[3][3], int RowsSumArr[3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            RowsSumArr[i] = RowSumInMatrix(Matrix, i, Cols);
        }
    }

    void PrintRowsSumInArray(int RowsSumArr[], short Rows)
    {
        cout << "\nThe Following are the Sum of each row in matrix : \n\n";

        for (short i = 0; i < Rows; i++)
        {
            cout << "Row " << i + 1 << " Sum = " << RowsSumArr[i] << "\n";
        }

    }

    int ColSumInMatrix(int Matrix[3][3], short Rows, short ColsNumber)
    {
        int Sum = 0;

        for (short i = 0; i < Rows; i++)
        {
            Sum += Matrix[i][ColsNumber];
        }
        return Sum;
    }

    void PrintEachColSumInMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        cout << "\nThe Following are the sum of each col in the matirx : \n";

        for (short j = 0; j < Cols; j++)
        {
            cout << "Col " << j + 1 << " Sum = " << ColSumInMatrix(Matrix, Rows, j) << "\n";
        }
    }

    void SumMatrixColsInArray(int Matrix[3][3], int ColsSumArr[3], short Rows, short Cols)
    {
        for (short i = 0; i < Cols; i++)
        {
            ColsSumArr[i] = ColSumInMatrix(Matrix, Rows, i);
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

    void FillMatrixWithOrderedNumbers(int Matrix[3][3], short Rows, short Cols)
    {
        int Counter = 0;

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                //Arr[i][j] = ++Counter;         ||->
                Counter++;
                Matrix[i][j] = Counter;
            }
        }
    }

    void TransposeMatrix(int Matrix[3][3], int ArrTransposed[3][3], int Rows, int Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                ArrTransposed[i][j] = Matrix[j][i];
            }
        }
    }

    void MultiplyTwoMatrices(int Matrix1[3][3], int Matrix2[3][3], int MatrixResults[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];
            }
        }
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

    int SumAllNumbersInMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        int Sum = 0;

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                Sum += Matrix[i][j];
            }

        }

        return Sum;

    }

    bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {
        return (SumAllNumbersInMatrix(Matrix1, Rows, Cols) == SumAllNumbersInMatrix(Matrix2, Rows, Cols));
    }

    bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (Matrix1[i][j] != Matrix2[i][j])
                {
                    return false;
                }
            }
        }

        return true;

    }

    bool CheckDiagonal(int Matrix[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (i == j)
                {
                    if (Matrix[i][j] != 1)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool CheckNON_Diagonal(int Matrix[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (i != j)
                {
                    if (Matrix[i][j] != 0)
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool IsIdentiyMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        //Check Diagonal Elements are 1 and NON_Diagonal Elements are 0

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                //Check Diagonal Elements...
                if (i == j && Matrix[i][j] != 1)
                {
                    return false;
                }

                //Check NON_Diagonal Elements...
                if (i != j && Matrix[i][j] != 0)
                {
                    return 0;
                }

            }
        }

        return true;

    }

    bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        //Check Diagonal Elements are Equal and NON_Diagonal Elements are 0

        int FirstDiagElement = Matrix[0][0];


        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                //Check Diagonal Elements...
                if (i == j && Matrix[i][j] != FirstDiagElement)
                {
                    return false;
                }


                //Check NON_Diagonal Elements...
                if (i != j && Matrix[i][j] != 0)
                {
                    return false;
                }

            }
        }

        return true;

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

    bool IsSparseMatrix(int Matrix1[3][3], short Rows, short Cols)
    {
        short MatrixSize = Rows * Cols;

        return (CountNumberInMatrix(Matrix1, 0, 3, 3) >= ceil((float)MatrixSize / 2));
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

    void PrintIntersectedNumbersInMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
    {
        int Number = 0;

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                Number = Matrix1[i][j];

                if (IsNumberInMatrix(Matrix2, Number, Rows, Cols))
                {
                    cout << setw(3) << Number << "    ";
                }

            }
        }
    }

    int MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        int Min = Matrix[0][0];

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (Min > Matrix[i][j])
                {
                    Min = Matrix[i][j];
                }

            }
        }

        return Min;

    }

    int MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        int Max = Matrix[0][0];

        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols; j++)
            {
                if (Max < Matrix[i][j])
                {
                    Max = Matrix[i][j];
                }

            }
        }

        return Max;

    }

    bool IsPalindromMatrix(int Matrix[3][3], short Rows, short Cols)
    {
        for (short i = 0; i < Rows; i++)
        {
            for (short j = 0; j < Cols / 2; j++)//important to do Cols / 2 
            {
                if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
                {
                    return false;
                }
            }
        }

        return true;

    }


}








//  Lesson#11/3                           Equial Matrices...

/*                                              Matrix1:
                                                02    02    04
                                                02    04    09
                                                07    07    04
                                                
                                                Matrix2:
                                                02    08    01
                                                03    01    08
                                                08    08    02

                                                Yes : Matrices are equal(SUM)...
    */                                           
                                   

//  Lesson#12/3                           Typical Matrices...

/*

                                                 Matrix1:
                                                  05    02    02
                                                  08    05    03
                                                  04    04    06

                                                 Matrix2:
                                                  05    02    02
                                                  08    05    03
                                                  04    04    06

                                                 No : Matrices are NOT Typical

*/


//  Lesson#13/3                           Identity Matrix...


/*
                                              Matrix1:
                                              01    00    00
                                              00    01    00
                                              00    00    01

                                              Yes : Matrix is identity.
*/


//  Lesson14/3                            Scalar Matrix...

/*
                                              Matrix1:
                                              09   00   00
                                              00   09   00
                                              00   00   09

                                              Yes : Matrix is Scalar.
*/



