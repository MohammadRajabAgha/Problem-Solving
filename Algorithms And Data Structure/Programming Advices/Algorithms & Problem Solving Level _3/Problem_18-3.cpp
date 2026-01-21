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


int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
    int Matrix2[3][3] = { {5,80,90},{22,77,77},{1,8,33} };

    //int Matrix1[3][3], Matrix2[3][3];

    //FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1 : \n";
    PrintMatrix(Matrix1, 3, 3);


    // FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "Matrix2 : \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "Intersected Numbers are : \n";
    PrintIntersectedNumbersInMatrices(Matrix1, Matrix2, 3, 3);

    return 0;
}


/*
                                         Matrix1 :
                                         77    05    12
                                         22    20    01
                                         01    00    09

                                         Matrix2 :
                                         05    80    90
                                         22    77    77
                                         10    08    33

                                             Intersected Numbers are :
                                         77    5    22    1    1

*/


//First Way...


/*
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


int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
    int Matrix2[3][3] = { {5,80,90},{22,77,77},{1,8,33} };

    //int Matrix1[3][3], Matrix2[3][3];

    //FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1 : \n";
    PrintMatrix(Matrix1, 3, 3);


    // FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "Matrix2 : \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "Intersected Numbers are : \n";
    PrintIntersectedNumbersInMatrices(Matrix1, Matrix2, 3, 3);

    return 0;
}
*/

//Second way...


/*
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

void PrintIntersectedNumbersInMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    int Number = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Number = Matrix2[i][j];

            if (IsNumberInMatrix(Matrix1, Number, Rows, Cols))
            {
                cout << setw(3) << Number << "    ";
            }

        }
    }
}


int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
    int Matrix2[3][3] = { {5,80,90},{22,77,77},{1,8,33} };

    //int Matrix1[3][3], Matrix2[3][3];

    //FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1 : \n";
    PrintMatrix(Matrix1, 3, 3);


    // FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "Matrix2 : \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "Intersected Numbers are : \n";
    PrintIntersectedNumbersInMatrices(Matrix1, Matrix2, 3, 3);

    return 0;
}
*/

//Therd way...


/*
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

void PrintIntersectedNumbersInMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            for (short k = 0; k < Rows; k++)
            {
                for (short m = 0; m < Cols; m++)
                {
                    if (Matrix1[i][j] == Matrix2[k][m])
                    {
                        cout << Matrix2[k][m] << " ";
                        //cout << Matrix1[i][j] << " ";
                    }
                }
            }
        }
    }
    cout << "\n\n";
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {77,5,12},{22,20,1},{1,0,9} };
    int Matrix2[3][3] = { {5,80,90},{22,77,77},{10,8,33} };

    //int Matrix1[3][3], Matrix2[3][3];

    //FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "Matrix1 : \n";
    PrintMatrix(Matrix1, 3, 3);


    // FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "Matrix2 : \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "Intersected Numbers are : \n";
    PrintIntersectedNumbersInMatrices(Matrix1, Matrix2, 3, 3);

    return 0;
}
*/


