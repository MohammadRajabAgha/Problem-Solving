#include<iostream>
#include<cmath>
#include<string>
using namespace std;

int ReadNumber()
{
	int Number;
	cout << "Pleas enter the number:\n";
	cin >> Number;

	return Number;
}

int ReadPower()
{
	int M;
	cout << "Pleas enter the Power?\n";
	cin >> M;
	return M;
}

int PowerOfM(int Num, int M)
{
	if (M == 0)
		return  1;

	else
	{
		int Power = 1;
		for (int count = M; count >= 1; count--)
		{
			Power = Power * Num;

		}

		return Power;
	}
}

int main()
{
	cout << endl << "Result " << PowerOfM(ReadPower(), ReadNumber());
	return 0;
}