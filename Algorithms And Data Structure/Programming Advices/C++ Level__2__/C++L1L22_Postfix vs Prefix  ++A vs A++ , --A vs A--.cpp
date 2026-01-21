#include <iostream>

using namespace std;

int main()
{
	int x = 10, y;

	y = ++x + x++ + x++;

	cout << "Y = " << y << endl;//36...Error...

	cout << "X = " << x << endl;//13...

	return 0;
}
