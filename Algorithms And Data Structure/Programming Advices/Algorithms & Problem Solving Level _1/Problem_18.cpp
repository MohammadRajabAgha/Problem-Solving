#include<iostream>
#include<cmath>
#include<string>
using namespace std;

float ReadRadious()
{
	float r;
	cout << "Pleas enter the Radious in cm;\n";
	cin >> r;

	return r;
}

 float CalculateCircalArea(float r)
{
	 const float PI = 3.141592653589793238;

	 float Area = PI * pow(r, 2);
	 return Area;

}

 void PrintCircalArea(float Area)
 {
	 cout << "\nthe Circal Area is:" << Area << " cm^2" << endl;
 }

int main()
{
	float r;
	
	PrintCircalArea(CalculateCircalArea(ReadRadious()));
	return 0;
}