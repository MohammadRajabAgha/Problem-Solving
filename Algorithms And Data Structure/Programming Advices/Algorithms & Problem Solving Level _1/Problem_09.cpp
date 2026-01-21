#include<iostream>
using namespace std;

void ReadNumber(int Num[3])
{
	

	for (int i = 0; i < 3; i++)
	{
		cout << "PLeas enter Number 1?\n";
		cin >> Num[i];
	}
}

int Caluclatesum(int Num[3])
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum = sum + Num[i];
	}
	return sum;
}

void PrintSum(int total)
{
	cout << "The Sum is " << total << endl;
}

int main()
{
	int Num[3];
	ReadNumber(Num);
	PrintSum(Caluclatesum(Num));

 return 0;
}