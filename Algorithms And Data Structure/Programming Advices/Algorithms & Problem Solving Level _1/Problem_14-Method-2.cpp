#include<iostream>
#include<string>
using namespace std;

void Swapprocedural(int Number1, int Number2)
{
	int temp = Number1;
	Number1 = Number2;
	Number2 = temp;
	cout << "*******************************\n";
	cout << Number1 << "\n";
	cout << Number2 << "\n";
}
int main()
{
	int Number1, Number2;
	cout << "Pleas enter Number1:\n";
	cin >> Number1;

	cout << "Pleasw enter Number2:\n";
	cin >> Number2;

	Swapprocedural(Number1, Number2);
	

	return 0;
}