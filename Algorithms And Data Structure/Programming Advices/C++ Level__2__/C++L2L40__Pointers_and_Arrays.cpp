#include <iostream>

using namespace std;

int main()
{
    //int Arr[4] = { 10,20,30,40 };
    int Arr[] = { 10,20,30,40 };

    int* Ptr;

    //Ptr=&Arr[0];
    Ptr = Arr;
    

    //ptr is equivalent to &arr[0];
    //ptr + 1 is equivalent to &arr[1];
    // ptr + 2 is equivalent to &arr[2];
    // ptr + 3 is equivalent to &arr[3];


    cout << "The Address Of Number : \n";
    
  /*  cout << &Arr << endl;*/
    cout << Ptr << endl;
    cout << Ptr + 1 << endl;
    cout << Ptr + 2 << endl;
    cout << Ptr + 3 << endl;

  /*  for (int i = 0; i <= 3; i++)
   {
        cout << (Ptr + i) << endl;
   }*/


    //The Value Of Array...


    cout << "\nThe Value Of Array : \n";

    cout << *(Ptr) << endl;
    cout << *(Ptr + 1) << endl;
    cout << *(Ptr + 2) << endl;
    cout << *(Ptr + 3) << endl;
    

    //for (int i = 0; i <= 3; i++)
    //{
    //    cout << *(Ptr + i) << endl;
    //    cout << ptr[i] << endl;
    //}

    return 0;
}




