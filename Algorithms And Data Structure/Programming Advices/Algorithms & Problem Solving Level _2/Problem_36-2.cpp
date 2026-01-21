#include<iostream>
#include<string>
using namespace std;

int ReadNumber()
{
	int Number;

	cout << "Please enter a Number?";
	cin >> Number;

	return Number;
}

void AddArrayElement(int Arr[100], int& arrLength,int Number)
{
		arrLength++;
		Arr[arrLength - 1] = Number;
	
}

void InputUserNumbersInArray(int Arr[100], int &arrLength)
{

	bool AddMore = true;

	do
	{
		AddArrayElement(Arr, arrLength, ReadNumber());

		cout << "Do You Want To add more Numbers?[0]:NO,[1]:Yes? ";
		cin >> AddMore;

		cout << "\n";

	} while (AddMore);
	cout << endl;

}

void PrintArray(int Arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int Arr[100], arrLength = 0;

	InputUserNumbersInArray(Arr, arrLength);


	cout << "Array Length : " << arrLength << "\n";

	cout << "Array Elements : ";
	PrintArray(Arr, arrLength);

	return 0;
}