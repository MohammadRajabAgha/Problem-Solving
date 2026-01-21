 #include<iostream>
#include<fstream>
using namespace std; 

int main() 
{
    fstream MyFile2;
    
    MyFile2.open("MyFile2.txt", ios::out | ios::app);//append Mode...

   if(MyFile2.is_open())
    {
        MyFile2 << "Allah Akbar\n";
        MyFile2 << "Allah Akbar\n";

        MyFile2.close();

    }
    
    return 0;

} 