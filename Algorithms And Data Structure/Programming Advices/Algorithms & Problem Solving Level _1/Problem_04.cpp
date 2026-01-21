#include<iostream>
using namespace std;

struct stInfo
{
	short Age;
	bool HasDriverLicense;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Pleas enter Your Age?\n";
	cin >> Info.Age;

	cout << "pleas enter Has Driver License?\n";
	cin >> Info.HasDriverLicense;

	return Info;
}

bool IsAccepted(stInfo Info)
{
	return (Info.Age > 21 && Info.HasDriverLicense);
}

void PrintInfo(stInfo Info)
{
	if (IsAccepted(Info))//exepression هام جدا 
	{
		cout << "\n Hired \n";
	}
	else
	{
		cout << "\n Rejection \n";

	}
}

int main()
{
	PrintInfo(ReadInfo());

	return 0;
}