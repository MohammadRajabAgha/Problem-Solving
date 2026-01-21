#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> vNum = { 1,2,3,4,5 };

    cout << vNum.at(0) << endl;
   

    try
    {
        cout << vNum.at(3) << endl;
    }

    catch (...)
    {
        cout << "Out Of bound\n";
    }

}