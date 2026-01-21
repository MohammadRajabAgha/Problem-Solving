#include<iostream>
#include<string>
#include<vector>
#include <iomanip> // this library stored the std::setw

using namespace std;


int main() 
{
	//The Lesson....

	cout << "The Lesson\n";

	int a = 10;
	int& x = a;

	cout << &a << endl;
	cout << &x << endl;

	cout << a << endl;
	cout << x << endl;

	cout << "\n_____________________________________________________________________________________________\n";
	cout << "\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	cout << "\n_____________________________________________________________________________________________\n\n\n";



	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));

	vector <int> vNumbers = { 1,2,3,4,5 };
	vector <int>& vNumbersV2 = vNumbers;

	cout << "Not Using & in for loop" << "\n\n\n";


	// vNumber Loop
	cout << "vNumber Loop : ";

	cout << "\n----------------------------------------------------------------------------------\n";
	cout << "|" << left << setw(12) << "Numbers" << "|" << left << setw(33) << "&Numbers" << "|" << left << setw(33) << "&vNumbers" << "|" << endl;
	cout << "-------------|---------------------------------|---------------------------------|\n";
	for (int Numbers : vNumbers)
	{
		cout << "|" << left << setw(12) << Numbers << "|" << left << setw(33) << &Numbers << "|" << left << setw(33) << &vNumbers << "|" << endl;
	}
	cout << "----------------------------------------------------------------------------------\n";



	//vNumberV2 Loop
	cout << "\nvNumberV2 Loop : ";

	cout << "\n----------------------------------------------------------------------------------\n";
	cout << "|" << left << setw(12) << "Numbers" << "|" << left << setw(33) << "&Numbers" << "|" << left << setw(33) << "&vNumberV2" << "|" << endl;
	cout << "-------------|---------------------------------|---------------------------------|\n";
	for (int Numbers : vNumbersV2)
	{
		cout << "|" << left << setw(12) << Numbers << "|" << left << setw(33) << &Numbers << "|" << left << setw(33) << &vNumbersV2 << "|" << endl;
	}
	cout << "----------------------------------------------------------------------------------\n";



	cout << "\n**************************************************************\n";


	cout << "\n\nUsing & in for loop" << "\n\n\n";




	// vNumber Loop


	cout << "vNumber Loop : ";

	cout << "\n----------------------------------------------------------------------------------\n";
	cout << "|" << left << setw(12) << "Numbers" << "|" << left << setw(33) << "&Numbers" << "|" << left << setw(33) << "&vNumbers" << "|" << endl;
	cout << "-------------|---------------------------------|---------------------------------|\n";
	for (int& Numbers : vNumbers)
	{
		cout << "|" << left << setw(12) << Numbers << "|" << left << setw(33) << &Numbers << "|" << left << setw(33) << &vNumbers << "|" << endl;
	}
	cout << "----------------------------------------------------------------------------------\n";


	// vNumberV2 Loop


	cout << "\nvNumberV2 Loop : ";

	cout << "\n----------------------------------------------------------------------------------\n";
	cout << "|" << left << setw(12) << "Numbers" << "|" << left << setw(33) << "&Numbers" << "|" << left << setw(33) << "&vNumberV2" << "|" << endl;
	cout << "-------------|---------------------------------|---------------------------------|\n";
	for (int& Numbers : vNumbersV2)
	{
		cout << "|" << left << setw(12) << Numbers << "|" << left << setw(33) << &Numbers << "|" << left << setw(33) << &vNumbersV2 << "|" << endl;
	}
	cout << "----------------------------------------------------------------------------------\n";


	return 0;
}