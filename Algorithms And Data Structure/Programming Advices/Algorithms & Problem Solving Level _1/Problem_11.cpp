#include<iostream>
using namespace std;

enum enPassFail { Fail, Pass };

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

enPassFail Checkavg(float avg)
{
	if (avg >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void PrintResult(float avg)
{
	cout << "The avg is " << avg << endl;

	if (Checkavg(avg) == enPassFail::Pass)
		cout << "You PASS\n";
	else
		cout << "You FAIL\n";
}

int main()
{
	int Mark[3];
	ReadMark(Mark);
	PrintResult(Caluclateavg3Mark(Mark));
	
	return 0;
}