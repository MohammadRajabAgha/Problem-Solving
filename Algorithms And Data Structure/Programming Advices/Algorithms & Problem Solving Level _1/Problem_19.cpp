#include<iostream>
#include<cmath>
#include<string>
using namespace std;

float ReadDiamter()
{
	float diamter;
	cout << "Pleas enter the Diammter:\n";
	cin >> diamter;

	return diamter;
}

float CalcukateCircleAreaThroughDiameter(float diamter)
{
	const float PI = 3.141592653589793238;
	float Area = (PI * pow(diamter, 2)) / 4;

	return (float)Area;
}

void PrintCircleAreaThroughDiameter(float Area)
{
	cout << "\nThe Circle Area is: " << Area << endl;
}

int main()
{
	PrintCircleAreaThroughDiameter(CalcukateCircleAreaThroughDiameter(ReadDiamter()));
	return 0;
}