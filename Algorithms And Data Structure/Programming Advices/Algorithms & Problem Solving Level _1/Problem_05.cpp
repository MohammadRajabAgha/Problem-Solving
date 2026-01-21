#include<iostream>
using namespace std;

struct stInfo //stores The Cadidate's Age HasDriverLicense HasRecomendation.
{
	short Age;
	bool HasDriverLicense;
	bool HasRecomendation;
};

stInfo ReadInfo()//Read and stores The Value in a struct (ReadInfo())
{
	stInfo Info;

	cout << "Pleas enter Your Age?\n";
	cin >> Info.Age;

	cout << "Pleas enter Has Driver Licens?\n";
	cin >> Info.HasDriverLicense;

	cout << "Pleas enter Has Recomebdation?";
	cin >> Info.HasRecomendation;

	return Info;// Return the struct with user information
}

bool IsAsccept(stInfo Info)//The Result will stor in (IsAsccept)
{
	if (Info.HasRecomendation)
	{
		return true;
	}

	else
	{
		return (Info.Age > 21 && Info.HasDriverLicense);
	}

}

void PrintInfo(stInfo Info)
{
	if (IsAsccept(Info))
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
