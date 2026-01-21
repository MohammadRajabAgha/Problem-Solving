#include <iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vNum = { 1,2,3,4,5 };

    cout << "Initial Vector : \n";

    for (const int& Num : vNum)
    {
        cout << Num << endl;
    }

    cout << "\n\n**************************\n";
    cout << "\n Test 1 Without & : \n";
    for (int Num : vNum)
    {
        Num = 20;
        cout << Num << endl;
    }

    cout << endl;

    for (const int &Num : vNum)
    {
      
        cout << Num << endl;
    }
    cout << "\n**************************\n\n";


    cout << "\n\n**************************\n";
    cout << "\n Test 2 : \n";

    cout << "\nUpdate Vector With &: \n";

    for (int& Num : vNum)
    {
        Num = 20;
        cout << Num << endl;
    }

    cout << endl;

    for (const int &Num : vNum)
    {
        cout << Num << endl;
    }

    cout << "\n**************************\n\n";


    vNum[1] = 40;
    vNum.at(2) = 80;
    vNum.at(4) = 90;

    cout << "\n\nUpdated Vector: \n";
    for (const int& Num : vNum)
    {
        cout << Num << endl;
    }

    return 0;
}


