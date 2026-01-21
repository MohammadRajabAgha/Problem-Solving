#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void ReadTriangleData(float& ITriangleSide, float& ITrianglebase)
{
	
	cout << "PLeas enter Side \n";
	cin >> ITriangleSide;

	cout << "Pleas enter the base \n";
	cin >> ITrianglebase;
}

float CalculateCirculeAreaBy_I_Triangle(float ITriangleSide, float ITrianglebase)
{
	const float PI = 3.141592653589793238;
	float Area = (PI * pow(ITrianglebase, 2) / 4) * ((2 * ITriangleSide - ITrianglebase) / (2 * ITriangleSide + ITrianglebase));
	
	return Area;
}

void PrintCirculeAreaBy_I_Triangle(float Area)
{
	cout << "\nThe Circle Area is; " << Area << endl;
}

int main()
{
	float ITriangleSide, ITrianglebase;

	ReadTriangleData(ITriangleSide, ITrianglebase);

	PrintCirculeAreaBy_I_Triangle(CalculateCirculeAreaBy_I_Triangle(ITriangleSide, ITrianglebase));

	return 0;
}