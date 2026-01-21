#include<iostream>
#include<string>
using namespace std;

void PrintCapitalletters()
{
	cout << "*************************************\n";
	cout << "The Capital Letters is \n";

	for (int count = 65; count <= 90; count++)
	{
		
		cout << char(count) << "\n";
	}
}
void PrintSmallLetters()
{
	cout << "*************************************\n";
	cout << "The Small Letters is \n";

	for (int Count = 97; Count <= 122; Count++)
	{
		cout << char(Count) << "\n";

	}
}

int main()
{
	PrintCapitalletters();
	PrintSmallLetters();

	return 0;
}