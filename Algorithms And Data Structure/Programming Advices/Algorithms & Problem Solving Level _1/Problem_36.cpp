#include<iostream>
#include<string>
using namespace std;

enum enOperationType { Add = '+',Subtract = '-',Multiply = '*',Divide = '/' };

float ReadNumber(string Message)
{
	float Number;
	
	cout << Message << endl;
	cin >> Number;

	return Number;
}

enOperationType ReadOperationType()
{
	char OperationType;

	cout << "Pleas enter Operation Type (+,-,*,/)?\n";
	cin >> OperationType;

	return (enOperationType)OperationType;
}

float CalculateOperation(float Number1, float Number2, enOperationType OperationType)
{
	switch (OperationType)
	{
	case(enOperationType::Add):
		return Number1 + Number2;
	case(enOperationType::Subtract):
		return Number1 - Number2;
	case(enOperationType::Multiply):
		return Number1 * Number2;
	case(enOperationType::Divide):
		return Number1 / Number2;
	default:
		return Number1 + Number2;
	}
}

int main()
{
	float Number1 = ReadNumber("Pleas enter First Number?\n");
	float Number2 = ReadNumber("Pleas enter Second Number?\n");

	enOperationType OperationType = ReadOperationType();
	cout << endl << Number1 << " " << char(OperationType) << " " << Number2 << " = " << CalculateOperation(Number1, Number2, OperationType) << endl;
	
	return 0;
}