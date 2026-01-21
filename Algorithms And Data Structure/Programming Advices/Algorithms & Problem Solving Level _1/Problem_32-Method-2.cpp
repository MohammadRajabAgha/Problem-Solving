#include<iostream>
using namespace std;
int power0fFunc(int Number, int M)
{
	int i = 1;
	int Power = 1;
	while ( i<=M )
	{
		Power = Power * Number;
		i++;
	}

	return Power;;
}
int main()
{
	int Number, M;

	cout << "Pleas enter the Number\n";
	cin >> Number;
	cout << "Pleas enter the Power\n";
	cin >> M;

	cout << power0fFunc(Number, M);

	return 0;

}