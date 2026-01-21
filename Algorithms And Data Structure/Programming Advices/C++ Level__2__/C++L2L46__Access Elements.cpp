#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vNum = { 1,2,3,4,5 };

    cout << "Using at() : \n";
    cout << "Element at Index [0] : " << vNum.at(0) << endl;
    cout << "Element at Index [2] : " << vNum.at(2) << endl;
    cout << "Element at Indxe [4] : " << vNum.at(4) << endl;
    //cout << "Element at Indxe [5] : " << num.at(5) << endl;//Exeption


    cout << "\n\nUsing [i] \n";
    cout << "Element at Index 0 : " << vNum[0] << endl;
    cout << "Element at Index 2 : " << vNum[2] << endl;
    cout << "Elemnent at Index 4 : " << vNum[4] << endl;
    //cout << "Element at Indxe [5] : " << num[5] << endl;//Warning

    cout << "\n\n for...Loop Using .at() : \n";
    for (int i = 0; i < vNum.size(); i++)
    {
        cout << vNum.at(i) << " ";
    }

    cout << endl;


    cout << "\n\nfor...Loop Using [i] : \n";
    for (int i = 0; i < vNum.size(); i++)
    {
        cout << vNum[i] << " ";
    }

    cout << "\n\nChanged Value Of Vector : \n";
    cout << "Please enter a New Element : \n";
    for (int i = 0; i < vNum.size(); i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> vNum[i];
    }


    cout << "\n\nfor...Loop Using [i] After Changed 1 : \n";
    for (int i = 0; i < vNum.size(); i++)
    {
        cout << vNum[i] << " ";
    }


    //Change the values of vector
    vNum.at(0) = 55;
    vNum.at(1) = 66;
    vNum.at(2) = 77;
    vNum.at(3) = 88;
    vNum.at(4) = 99;

    cout << "\n\nfor...Loop Using [i] After Changed 2 : \n";
    for (int i = 0; i < vNum.size(); i++)
    {
        cout << vNum[i] << " ";
    }

    cout << "\n\n**************************************************************************\n\n";

    return 0;
}
