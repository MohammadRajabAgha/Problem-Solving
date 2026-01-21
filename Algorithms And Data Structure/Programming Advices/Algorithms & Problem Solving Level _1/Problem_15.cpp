#include<iostream>
#include<string>
using namespace std;

void ReadrectangleInfo(float &Length,float &Width)
{

	cout << "Pleas enter Rectangle Length?\n";
	cin >> Length;

	cout << "Pleas enter Rectangle Width?\n";
	cin >> Width;
}

float CalculaterectangleArea(float Length, float Width)
{
	return  Length * Width;
}

void PrintRectangleArea(float Area)
{
	cout << "*****************************************************************************\n";
	cout << "The Rectangle Area is:" << Area << endl;
}

int main()
{
	float Length, Width;
	
	ReadrectangleInfo(Length, Width);
	PrintRectangleArea(CalculaterectangleArea(Length, Width));

	return 0;
}