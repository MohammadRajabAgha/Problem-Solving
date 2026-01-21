#include<iostream>
#include<string>
using namespace std;

void PrintTableHeader()
{
	cout << "\n\n\t\t\t Multiplication Tab1e From 1 to 10 \n\n";

	cout << "\t";

	for (int i = 1; i <= 10; i++)
	{
		{
			cout << i << "\t";

		}
	}

	cout << "\n_______________________________________________________________________________________\n";

}

string ColumnSeparator(int i)//هام
{
	if (i < 10)
		return "    |";
	else
		return "   |";
}

void MultipliactionTable()
{

	PrintTableHeader();
	
		for (int i = 1; i <= 10; i++)
		{
			cout << " " << i << ColumnSeparator(i) << "\t";
			for (int j = 1; j <= 10; j++)
			{
				cout << i * j << "\t";
			}
			cout << endl;
		}
}

int main()
{
	MultipliactionTable();

	return 0;
}