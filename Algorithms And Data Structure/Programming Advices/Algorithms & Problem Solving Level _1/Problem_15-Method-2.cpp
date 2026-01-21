#include<iostream>
#include<string>
using namespace std;

struct strectangleInfo
{
	int length;
	int width;

};

strectangleInfo ReadrectangleInfo()
{
	strectangleInfo Info;

	cout << "Pleas enter Rectangle Length?\n";
	cin >> Info.length;

	cout << "Pleas enter Rectangle Width?\n";
	cin >> Info.width;

	return Info;
}

int CalculaterectangleArea(strectangleInfo Info)
{
	return  Info.length * Info.width;
}

void PrintRectangleArea(strectangleInfo& Info)
{
	cout << "*****************************************************************************\n";
	int Area = CalculaterectangleArea(Info);
	cout << "The Rectangle Length: " << Info.length << "\n";
	cout << "The Rectangle Width: " << Info.width << "\n";
	cout << "The Rectangle Area is:" << Area << endl;
}

int main()
{
	strectangleInfo myRectangle = ReadrectangleInfo();
	PrintRectangleArea(myRectangle);

	return 0;

}