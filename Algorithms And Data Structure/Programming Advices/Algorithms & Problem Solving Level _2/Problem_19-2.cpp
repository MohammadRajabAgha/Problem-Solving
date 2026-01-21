#include<iostream>
#include<cstdlib>
#include <ctime>      // Include ctime for the time() function
using namespace std;

int RandomNumber(int From,int To)
{
	int randNum = From + rand() % (To - From + 1);

	return randNum;
}

int main()
{
	// Seed the random number generator with the current time.
	// This ensures that we get a different sequence of random numbers on each run.
	srand((unsigned)time(NULL));
	    

	cout << RandomNumber(20, 50) << "\n";
	cout << RandomNumber(20, 50) << "\n";
	cout << RandomNumber(20, 50) << "\n";


	return 0;
}
