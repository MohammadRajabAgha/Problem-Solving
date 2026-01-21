#include<iostream>
#include<cmath>
#include<string>
using namespace std;

float ReadCirculeCircumference()
{
	float circulecircumference;

	cout << "Pleas enter the circumference\n";
	cin >> circulecircumference;

	return circulecircumference;
}

float CalculateCirculeAreaAlongTheCircumference(float circulecircumference)
{
	const float PI = 3.141592653589793238;
	float Area = pow(circulecircumference, 2) / (4 * PI);

	return Area;
}

void PrintCirculeAreaAlongTheCircumference(float Area)
{
	cout << "\nThe Circle Area is: " << Area << endl;
}

int main()
{
	PrintCirculeAreaAlongTheCircumference(CalculateCirculeAreaAlongTheCircumference(ReadCirculeCircumference()));

	return 0;
}