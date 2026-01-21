#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void ReadInfo(float &diagonale,float &siderectangle)
{
	cout << "Pleas enter the Side Rectangle:\n";
	cin >> siderectangle;

	cout << "Pleas enter the Diagonal:\n";
	cin >> diagonale;

	
}

float RectangleAreaThroughDiagonalAndSide(float diagonale, float siderectangle)
{
	float Area = (siderectangle) * (sqrt(pow(diagonale, 2) - pow(siderectangle, 2)));
	return Area;
}

void PrintRectangleAreaThroughDiagonalAndSide(float Area)
{
	cout << "\nThe Rectangle Area is:" << Area << endl;
}

int main()
{
	float diagonale, siderectangle;

	ReadInfo(diagonale, siderectangle);
	RectangleAreaThroughDiagonalAndSide(RectangleAreaThroughDiagonalAndSide(diagonale, siderectangle));
	return 0;
}