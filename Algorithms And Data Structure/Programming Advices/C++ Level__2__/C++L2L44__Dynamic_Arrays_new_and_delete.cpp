#include<iostream>
using namespace std; 

int main() 
{
    int Length; 

    cout << "Enter total number of students: ";
    cin >> Length;
    
    float* ptr; 
    
    // memory allocation of num number of floats  
    ptr = new float[Length];
    
    cout << "Enter grades of students." << endl;
    for (int i = 0; i < Length; i++)
    {  
        cout << "Student" << i + 1 << ": ";     
        cin >> *(ptr + i);   
    }


    cout << "\nDisplaying grades of students." << endl; 
    for (int i = 0; i < Length; i++)
    {
        cout << "Student" << i + 1 << ": " << *(ptr + i) << endl; 
    } 
    
    // ptr memory is released
    delete[] ptr; 
    
    return 0; 

} 



//
//#include <iostream>
//using namespace std;
//
//int main() {
//    short num = 15;
//
//    /* A pointer is a variable used to contain the Address of other variables,
//       function or anything in the memory */
//
//       //Declaration of a pointer to the variable "num":
//    short* pointer = &num;// Note that the type of the pointer MUST match the type of the variable
//
//    /* From the pointer, we can access the Address/Value of a variable */
//
//    //Accessing the Address:
//    cout << "Address of num (using num) = " << &num << endl; //output: Address
//    cout << "Address of num (using pointer) = " << pointer << endl; // output: same Address
//
//    //Accessing the Value:
//    cout << "Value of num (using num) = " << num << endl; //output: 15
//    cout << "Value of num (using pointer) = " << *pointer << endl; //output: 15
//
//    //Changing the Value:
//    *pointer = *pointer / (num - 10);
//    cout << "Value of num (using num) = " << num << endl; //output: 3
//    cout << "Value of num (using pointer) = " << *pointer << endl; //output: 3
//
//
//    //You can also access the Address of the Pointer itself, because the Pointer has an Address like any other variable
//    cout << "Address of Pointer = " << &pointer << endl; //output: Address of Pointer
//
//    /* We can change the variable at which the pointer is pointing
//       AS LONG AS the second variable has the same Type as the original one */
//    short num2 = -10;
//    pointer = &num2;
//
//    cout << pointer << endl; //output: other Hexadecimal (new address -> num2)
//    cout << *pointer << endl; //output: -10
//
//    /* Common Mistakes using Pointers:
//        1. The pointer itself store the ADDRESS of the variable NOT the VALUE of it
//          pointer = num; (ERROR)
//          pointer = &num; (CORRECT)
//
//        2. The *pointer stores/leads to the VALUE of the variable not the ADDRESS
//          *pointer = &num; (ERROR)
//          *pointer = num + 10; (CORRECT) //Increases the value of num by 10
//
//        3. The pointer can change the variable at which it's pointing AS LONG AS the second variable has the same Type of the original variable
//          int num1 = 10, *pointerInt;
//          short num2 = 20;
//
//          pointerInt = &num1; (CORRECT)
//          pointerInt = &num2; (ERROR)
//
//          int num3 = 0;
//          pointerInt = &num3; (CORRECT)
//    */
//
//    /* Using Pointers with Arrays */
//    int arr[4] = { 1, 2, 3, 4 }, * pointerArr = arr;
//    //pointerArr = &arr; (ERROR)
//    cout << arr << endl; //output: Address of first element
//    cout << &arr << endl; //output: same Address
//    cout << &arr[0] << endl; //output: same Address
//    cout << pointerArr << endl << endl; //output: same Address
//
//    //If you want to access the address of arr[n], use pointerArr + n
//    cout << &arr[2] << endl; //output: Address of third element
//    cout << pointerArr + 2 << endl; //output: same Address
//
//    //If you want to access the Value of arr[n], use *(pointer + n)
//    cout << *(pointerArr + 2) << endl << endl; //output: 3
//    *(pointerArr + 3) = 40; //Changes the forth element to 40
//
//    //I tried using a pointer of string and a pointer of char[], but its behaviour was inapprehensible
//
//    /* Using Pointers with Structures */
//    struct stPerson {
//        string name = "Abdulrahman Salem";
//        short age = 19;
//        float salary = 12.5;
//    };
//    /* Yes, you can define a structure inside of a function,
//       but it will be limited to the scope of the function (not global) */
//
//    stPerson person1, * pointerStruct = &person1;
//
//    cout << &person1 << endl; //output: Address of the first variable of the Structure
//    cout << &person1.name << endl; //output: same Address
//    cout << pointerStruct << endl; //output: same Address
//    cout << &pointerStruct << endl << endl; //output: Address of the Pointer itself
//
//    /* From the Pointer, you can access the Address/Value of any variable inside the Structure */
//
//    //Accessing the Addresses:
//    cout << &pointerStruct->name << endl; //output: Address of the variable "name"
//    cout << &pointerStruct->age << endl; //output: Address of the variable "age"
//    cout << &pointerStruct->salary << endl << endl; //output: Address of the variable "salary"
//    //Accessing the Values:
//    cout << "Name   : " << pointerStruct->name << endl; //output: Abdulrahman
//    cout << "Age    : " << pointerStruct->age << endl; //output: 19
//    cout << "Salary : " << pointerStruct->salary << endl << endl; //output: 12.5
//    //Changing the Values:
//    pointerStruct->name = "Maher Ali";
//    pointerStruct->age = 52;
//    pointerStruct->salary = 8500;
//
//    cout << "Name   : " << pointerStruct->name << endl; //output: Maher Ali
//    cout << "Age    : " << pointerStruct->age << endl; //output: 52
//    cout << "Salary : " << pointerStruct->salary << endl << endl; //output: 8500
//
//    /* Void Pointers */
//    string animal = "cat";
//    int price = 20;
//    void* ptr;
//
//    //A void Pointer is a pointer used to point at ANY variable of ANY Type
//    ptr = &animal;
//    cout << "Address of String (using Sring) = " << &animal << endl; //output: Address of String
//    cout << "Address of String (using Pointer) = " << ptr << endl; //output: same Address
//    //If you want to access the value of a variable through a void Pointer, use the static_cast
//    cout << "Value of String (using String) = " << animal << endl; //output: cat
//    cout << "Value of String (using Pointer) = " << *static_cast<string*>(ptr) << endl; //output: cat
//    *static_cast<string*>(ptr) = "horse";
//    cout << "New value of String (using String) = " << animal << endl; //output: horse
//    cout << "New value of String (using Pointer) = " << *static_cast<string*>(ptr) << endl << endl; //output: horse
//
//    /*  DO NOT use C-Style cast (string *)ptr, because it's less safe and can cause unintended conversions
//        always use static_cast in this case */
//
//        //Similarly:
//    ptr = &price;
//    //And so on.. 
//
//    /* Using Pointers, we can create variables in run-time and delete them whenever we
//       want from the memory in run-time. This enhances the performance of the program */
//
//    int* someVariable;
//    //Creating a variable:
//    someVariable = new int;
//    // We now have an int variable and can access it through its Pointer
//    *someVariable = 2006;
//    /* Instead of creating a variable in a line and then giving its value in another
//       line, we can say: someVariable = new int(2006); and the result will be the same.
//       We can even do all those steps in one line: int * someVariable = new int(2006); */
//
//    cout << *someVariable << endl; //output: 2006
//
//    //Deleting the variable:
//    delete someVariable;
//    //cout << *someVariable << endl; (ERROR)
//
//    /* Using Pointers to create dynamic arrays */
//    unsigned short arrLng = 0;
//    cout << "Enter Array Length: ";
//    cin >> arrLng;
//    string* arrStrPointer = new string[arrLng]; //This creates a string array with the exact size the user wants, and we can access this array through the pointer.
//
//    //Filling the Array:
//    for (short i = 0; i < arrLng; i++) {
//        printf("Enter Element[%d]: ", i + 1);
//        cin >> *(arrStrPointer + i);
//    }
//    cout << endl;
//
//    //Printing the Array:
//    cout << "Array Elements:\n";
//    for (short i = 0; i < arrLng; i++)
//        cout << "Element[" << i + 1 << "]: " << *(arrStrPointer + i) << '\n';
//    cout << endl;
//
//    //Deleting the Array:
//    delete[] arrStrPointer;
//
//    return 0;
//}