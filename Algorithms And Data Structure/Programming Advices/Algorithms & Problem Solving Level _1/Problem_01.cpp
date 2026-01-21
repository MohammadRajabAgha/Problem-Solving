#include<iostream>
#include<string>//Include string To work with std::string. 
using namespace std;

void PrintName(string Name)
{

	//adding new line before for Formatting.
	cout << "\n Your Name is: " << Name << endl;

}

int main()
{

	PrintName("Mohammad");

	return 0;//Return 0 To indication successful execution.

}