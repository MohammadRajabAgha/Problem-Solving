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

int ReverseNumber(int Number)
{
    int Remainder = 0; 
    int Number2 = 0;   

   
    while (Number > 0)
    {
        Remainder = Number % 10;         
        Number = Number / 10;            
        Number2 = Number2 * 10 + Remainder; 
    }

    return Number2;  
}

void PrintDigits(int Number)
{
    int Remainder = 0;  

    while (Number > 0)
    {
        Remainder = Number % 10; 
        Number = Number / 10;    
        cout << Remainder << endl;
    }
}

int main()
{
    
    PrintDigits(ReverseNumber(ReadPositiveNumber("Please enter a positive number?")));

    return 0;  
}


//#include<iostream>
//#include<string>
//using namespace std;
//
//int ReadPositiveNumber(string Message)
//{
//	int Number;
//
//	do
//	{
//		cout << Message << endl;
//		cin >> Number;
//	} while (Number <= 0);
//
//	return Number;
//}
//
//void PrintDigitsInaReversedOrder(int Number)//important.
//{
//	int Sum = 0, Reminder = 0;
//
//	while (Number > 0)
//	{
//		Reminder = Number % 10;//Extract the last digit of Number.
//		Number = Number / 10;//Remove the last digit from Number.
//		cout << Reminder << "\n";
//	}
//}
//
//int ReversedNumber(int Number)//important.
//{
//	int Sum = 0, Reminder = 0;
//	int Number2 = 0;
//
//	while (Number > 0)
//	{
//		Reminder = Number % 10;//Extract the last digit of Number.
//		Number = Number / 10;//Remove the last digit from Number.
//		Number2 = Number2 * 10 + Reminder;//Append the digit to Number2 by shifting left and adding Remainder.
//
//	}
//	return Number2;;
//}
//
//void PrintDigitInOrder(int Number)
//{
//
//	PrintDigitsInaReversedOrder(ReversedNumber(Number));
//
//}
//
//int main()
//{
//
//	PrintDigitInOrder(ReadPositiveNumber("Pleas enter a Positive Number?"));
//
//
//	return 0;
//}
//
