#include<iostream>
#include<string>
using namespace std;
void PrintLettersAtoZ()
{
	cout << "The Capital Letters:\n\n";

	for (int i = 65; i <= 90; i++)
	{
		cout << char(i) << "\n";
	}
	
}
int main()
{
	PrintLettersAtoZ();
	return 0;
}