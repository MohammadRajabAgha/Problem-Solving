#include<iostream>
#include<cmath>
#include<string>
using namespace std;

float ReadSquareSide()
{
	float SquareSide;
	cout << " Pleas enter the Square rib in cm;\n ";
	cin >> SquareSide;

	return SquareSide;
}

float CalculateCircleAreaInscribedInSquare(float SquareSide)
{
	const float PI = 3.141592653589793238;
	float Area = (PI * pow(SquareSide, 2)) / 4;

	return Area;
}

void PrintCircleAreaInscribedInSquare(float Area)
{
	cout << "\nthe Circale Area is: " << Area << endl;
}

int main()
{
	PrintCircleAreaInscribedInSquare(CalculateCircleAreaInscribedInSquare(ReadSquareSide()));
	return 0;
}
