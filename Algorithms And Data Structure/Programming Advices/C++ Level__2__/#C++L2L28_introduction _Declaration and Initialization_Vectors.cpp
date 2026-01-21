#include<iostream>
#include<vector>

using namespace std; 

int main() 
{    
    // std::vector<T> vector_name

    vector <int> vNumbers = { 10, 20, 30, 40, 50 , 60 , 70 , 80 , 90 };

    cout << "Numbers Vector = "; 
    

    // ranged loop...
    for (int  &Number : vNumbers) 
    {     
        cout << Number << "  ";  
    
    }  

    cout << endl;

    //for (int& Number : vNumbers)
    //{
    //    Number = Number / 10;

    //}

    //cout << "Numbers Vector after modify = ";

    //// ranged loop...
    //for (int& Number : vNumbers)
    //{
    //    cout << Number << "  ";

    //}

    //cout << endl;

    return 0; 

} 