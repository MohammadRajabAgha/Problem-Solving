#include<iostream>
#include<string>
using namespace std;

struct stInfo
{
	string FirstName;
	string LastName;
	bool Reversied;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Pleas enter First Name?\n";
	cin >> Info.FirstName;

	cout << "Pleas enter Last Name?\n";
	cin >> Info.LastName;

	cout << "Do You Want Reversied?\n";
	cin >> Info.Reversied;

	return Info;
}

string GetFullName(stInfo Info)
{
	string FullName;

	if (Info.Reversied)
		FullName = Info.LastName + " " + Info.FirstName;
	else
		FullName = Info.FirstName + " " + Info.LastName;

	return FullName;

}

void PrintFullName(string FullName)
{
	cout << "\n Your Full Name is " << FullName;
}

int main()
{
	PrintFullName(GetFullName(ReadInfo()));

	return 0;
}


//#include<iostream>
//#include<string>
//using namespace std;
//
//enum enReversed { False=0, True=1 };
//
//struct stInfo
//{
//	string FristName;
//	string LastName;
//	enReversed Reversed;
//};
//
//stInfo ReadInfo()
//{
//	int enNum;
//	stInfo Info;
//
//	cout << "PLeas enter First Name?\n";
//	cin >> Info.FristName;
//
//	cout << "Pleas enter Last Name?\n";
//	cin >> Info.LastName;
//
//	cout << "Do You want Reversed The Name ( False=0, True=1 )?\n";
//	cin >> enNum;
//	Info.Reversed = enReversed(enNum);
//	
//
//	return Info;
//}
//
//bool checkReversed(stInfo Info)
//{
//	if (Info.Reversed == enReversed::True)
//		return true;
//	else
//		return false;
//}
//
//string GetFullName(stInfo Info)
//{
//	string FullName;
//
//	if (checkReversed(Info))
//		return  FullName = Info.LastName + " " + Info.FristName;
//	else
//	return FullName = Info.FristName + " " + Info.LastName;
//}
//
//void PrintFullName(string FullName)
//{
//	cout << "Your Full Name is: " << FullName << endl;
//}
//
//int main()
//{
//	PrintFullName(GetFullName(ReadInfo()));
//	return 0;
//}