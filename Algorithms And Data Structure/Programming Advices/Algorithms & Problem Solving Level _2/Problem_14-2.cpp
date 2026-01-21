#include <iostream>   
#include <string>     
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;
}

void PrintInvertedLetterPattern(int Num)
{
    cout << "\n";

    for (int i = 65 + Num - 1; i >= 65; i--)
    {
        // Calculate the number of times to print the current letter.
        // When i = 65 + Number - 1, (65 + Number - 1 - i) equals 0,
        // so the inner loop runs 'Number' times.
        // For each subsequent row, this value increases, reducing the count by 1 each time.
        for (int j = 1; j <= Num - ((65 + Num - 1) - i); j++)
        {
        
            cout << char(i);
        }
        cout << "\n";

    }
}

int main()
{
    PrintInvertedLetterPattern(ReadPositiveNumber("PLeas enter a Positive Number?"));


    return 0;
}





//#include <iostream>   
//#include <string>     
//using namespace std;
//
//int ReadPositiveNumber(string Message)
//{
//    int Number = 0;
//    do
//    {
//        cout << Message << endl;
//        cin >> Number;
//    } while (Number <= 0);
//
//    return Number;
//}
//
//void PrintInvertedLetterPattern(int Num)
//{
//    cout << "\n";
//
//    for (int i = 64 + Num; i >= 65; i--)
//    {
//    
//        for (int j = 1; j <= Num - (64 + Num - i); j++)
//        {
//            cout << char(i);
//        }
//        cout << "\n";
//
//    }
//}
//
//int main()
//{
//    PrintInvertedLetterPattern(ReadPositiveNumber("PLeas enter a Positive Number?"));
//
//
//    return 0;
//}

























//#include <iostream>   
//#include <string>     
//using namespace std;
//
//int ReadPositiveNumber(string Message)
//{
//    int Number = 0;
//    do
//    {
//        cout << Message << endl;
//        cin >> Number;
//    } while (Number <= 0);
//
//    return Number;
//}
//
//void PrintInvertedLetterPattern(int Num)
//{
//    cout << "\n";
//
//    for (int i = Num; i >= 1; i--)
//    {
//        for (int j = 1; j <= i; j++)
//        {
//            cout << char(i+64);
//        }
//        cout << "\n";
//
//    }
//}
//
//int main()
//{
//    PrintInvertedLetterPattern(ReadPositiveNumber("PLeas enter a Positive Number?"));
//
//
//    return 0;
//}