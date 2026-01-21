#include<iostream>
#include<string>
#include<vector>
#include <iomanip> // this library stored the std::setw

using namespace std;


int main()
{
	int a = 10;

	int& X = a;

	cout << &X << endl;
	cout << &a << endl;


	cout << X << endl;
	cout << a << endl;

	int* P = &a;
	cout << P << endl;
	cout << *P << endl;

	P = &X;
	cout << P << endl;
	cout << *P << endl;

	int b = 20;
	P = &b;

	cout << P << endl;
	cout << *P << endl;


	return 0;
}