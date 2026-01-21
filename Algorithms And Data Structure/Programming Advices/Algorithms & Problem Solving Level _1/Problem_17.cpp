#include<iostream>
using namespace std;

void ReadInfo(float& base, float& high)
{
	cout << "enter the base:\n";
	cin >> base;
	cout << "enter the high:\n";
	cin >> high;
}

float CalculateTriangleArea(float base, float high)
{
	return  (base * high) / 2;
}

void PrintTriangleArea(float Area)
{
	cout << "the triangle area is:" << Area << " cm^2" << endl;
}

int main()
{
	float base, high,trianglearea;

	ReadInfo(base, high);
	PrintTriangleArea(CalculateTriangleArea(base, high));
	return 0;
}