#include<iostream>
using namespace std;

enum enPassFail { Fail, Pass };

int ReadMark()
{
	short Mark;
	cout << "Pleas enter The Mark?\n";
	cin >> Mark;
	return Mark;
}

enPassFail CheckMark(int Mark)
{
	if (Mark >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void PrintMark(int Mark)
{
	if (CheckMark(Mark) == enPassFail::Pass)
		cout << "PASS\n";
	else
		cout << "Fail\n";
}

int main()

{
	PrintMark(ReadMark());

	return 0;
}