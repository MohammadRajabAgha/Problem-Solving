#include<iostream>
using namespace std;

void ReadMark(int Mark[3])
{
		cout << "PLeas enter Mark1?\n";
		cin >> Mark[0];
	
		cout << "PLeas enter Mark2?\n";
		cin >> Mark[1];

		cout << "PLeas enter Mark3?\n";
		cin >> Mark[2];
}

int Caluclatesum3Mark(int Mark[3])
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum = sum + Mark[i];
	}
	return sum;
}

float Caluclateavg3Mark(int Mark[3])
{
	return (float)Caluclatesum3Mark(Mark) / 3;
}

void PrintSum(float avg)
{
	cout << "The avg is " << avg << endl;
}

int main()
{
	int Mark [3] ;
	ReadMark(Mark);
	PrintSum(Caluclateavg3Mark(Mark));

	return 0;
}