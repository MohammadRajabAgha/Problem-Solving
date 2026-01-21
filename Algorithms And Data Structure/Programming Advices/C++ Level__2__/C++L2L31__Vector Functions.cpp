#include<vector>
#include<iostream>

using namespace std;

int main() 
{
    vector <int> vNumbers;


    vNumbers.push_back(10);  
    vNumbers.push_back(20); 
    vNumbers.push_back(30); 
    vNumbers.push_back(40);   
    vNumbers.push_back(50);   
    vNumbers.push_back(60);
    vNumbers.push_back(70);
    vNumbers.push_back(80);
    vNumbers.push_back(90);
    vNumbers.push_back(100);
    vNumbers.push_back(110);
    vNumbers.push_back(120);
    vNumbers.push_back(130);
    vNumbers.push_back(140);
    vNumbers.push_back(150);
    vNumbers.push_back(160);
    vNumbers.push_back(170);
    vNumbers.push_back(180);
    vNumbers.push_back(190);
    vNumbers.push_back(200);
    vNumbers.push_back(210);
    vNumbers.push_back(220);
    vNumbers.push_back(230);
    vNumbers.push_back(240);
    vNumbers.push_back(250);
    vNumbers.push_back(260);
    vNumbers.push_back(270);
    vNumbers.push_back(280);
    vNumbers.push_back(290);
    vNumbers.push_back(300);


    if (!vNumbers.empty())
    {
        cout << "First Element: " << vNumbers.front() << endl;
        cout << "Last Element: " << vNumbers.back() << endl;
    }

    //returns the number of elements present in the vector    
    cout << "Size: " << vNumbers.size() << endl;
    
    //check the overall size of a vector    
    cout << "Capacity : " << vNumbers.capacity() << endl; 
    
    //returns 1 (true) if the vector is empty 
    cout << "Empty : " << vNumbers.empty() << endl;

    cout << vNumbers.at(9) << endl;

    return 0;
}