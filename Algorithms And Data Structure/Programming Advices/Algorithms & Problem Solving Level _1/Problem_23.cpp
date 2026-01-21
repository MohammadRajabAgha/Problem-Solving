#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void ReadTriangleData(float& side1, float& side2, float& side3)
{
	cout << "Pleas enter the Side1?\n";
	cin >> side1;

	cout << "Pleas enter the Side2?\n";
	cin >> side2;

	cout << "Pleas enter the Side3?\n";
	cin >> side3;
}

float CalculateCircleAreaBy_A_Triangle(float side1, float side2, float side3)
{
	const float PI = 3.141592653589793238;

	float P = (side1 + side2 + side3) / 2;
	float Z = (side1 * side2 * side3) / (4 * sqrt(P * (P - side1) * (P - side2) * (P - side3)));

	float Area = PI * pow(Z, 2);
	return Area;
}

void PrintCircleAreaBy_A_Triangle(float Area)
{
	cout << "\nThe Circle Area is:" << Area << endl;
}

int main()
{
	float side1, side2, side3;

	ReadTriangleData(side1, side2, side3);
	PrintCircleAreaBy_A_Triangle(CalculateCircleAreaBy_A_Triangle(side1, side2, side3));

	
	return 0;
}