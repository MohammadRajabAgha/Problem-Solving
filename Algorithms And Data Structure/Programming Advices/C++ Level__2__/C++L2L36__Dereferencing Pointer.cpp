#include<iostream>
using namespace std;

int main() 
{
    int a = 10;  
    
    cout << "a value        = " << a << endl;//10 
    cout << "a address     = " << &a << endl;//000000368114F9F4 
    
    int* p; 
    p = &a;   
    
    cout << "Pointer Value = " << p << endl;//000000368114F9F4  
    cout << "Value of the address that p is pointing to is " << *p << endl;//10 

    *p = 20;   
    cout << a << endl;//20 
    cout << *p << endl;//20     
    
    a = 30;   
    cout << a << endl;//30  
    cout << *p << endl;//30 
 
    cout << endl;
    
    return 0;

}