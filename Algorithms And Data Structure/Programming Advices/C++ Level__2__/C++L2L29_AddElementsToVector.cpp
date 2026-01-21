#include<iostream>
#include<vector>

using namespace std; 

// std::vector<T> vector_name

int main()
{ 
    vector <int> vNumbers;  
    
    vNumbers.push_back(10);
    vNumbers.push_back(20);  
    vNumbers.push_back(30);   
    vNumbers.push_back(40);
    vNumbers.push_back(50);  
    
    cout << "Numbers Vector: \n\n";
    
    // ranged loop
    for (int & Number : vNumbers)
    {      
        cout << Number << endl;  
    }    

    cout << endl; 

    vNumbers.pop_back();
    vNumbers.pop_back();

    cout << "\n***********************\n";

    for (int& Number : vNumbers)
    {
        cout << Number << endl;
    }

      cout << endl;

     





    return 0; 

} 