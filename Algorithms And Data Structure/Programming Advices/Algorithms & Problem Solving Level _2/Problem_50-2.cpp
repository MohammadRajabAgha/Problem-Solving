#include<iostream>
#include<string>
#include<cmath>
using namespace std;

float ReadPositiveNumber(string Message)
{	
    float Number;

    do
    {
        cout << Message << endl;
        cin >> Number;

    } while (Number < 0);

	return Number;
}

float MySqrt(float Number)
{
	return pow(Number, 0.5);
}

float MySqrt2(float Number) 
{
    if (Number == 0) {
        return 0;
    }

    float XQ = Number / 2;
    for (int i = 1; i <= 15; i++) 
    {
        XQ = (XQ + (Number / XQ)) / 2;
    }
    return XQ;
}

int main()
{
    float Number = ReadPositiveNumber("PLease enter a Positive Number?");

	cout << "\nMy Sqrt Result : " << MySqrt(Number);
    cout << "\nMy Sqrt 2 Result : " << MySqrt2(Number);
	cout << "\nC++ Sqrt Result : " << sqrt(Number);

	return 0;
}



//Newton's Method.

//#include <iostream>
//#include <cmath> // لإضافة دالة sqrt() للمقارنة
//using namespace std;
//
//float ReadNumber(string message) {
//    float Number = 0;
//    cout << message << endl;
//    cin >> Number;
//    return Number;
//}
//
//float MySqrt(float Number) {
//    if (Number < 0) {
//        return -1; // أفضل من إرجاع 0 للأعداد السالبة
//    }
//
//    if (Number == 0) {
//        return 0;
//    }
//
//    float XQ = Number / 2;
//    for (int i = 1; i <= 15; i++) 
//    {
//        XQ = (XQ + (Number / XQ)) / 2;
//    }
//    return XQ;
//}
//
//int main() {
//    float Num = ReadNumber("أدخل رقمًا من فضلك");
//    float myResult = MySqrt(Num);
//
//    if (myResult == -1) {
//        cout << "No Negative" << endl;
//    }
//    else {
//        cout << "My: " << myResult << endl;
//        cout << " C++: " << sqrt(Num) << endl;
//       /* cout << sqrt(Num) * sqrt(Num) << "\n";*/
//    }
//
//    return 0;
//}


//Newton-Raphson Method In Programming Advice.  

//#include <iostream>
//#include <cmath> // لإضافة دالة sqrt() للمقارنة
//using namespace std;
//
//float ReadNumber(string message) {
//    float Number = 0;
//    cout << message << endl;
//    cin >> Number;
//    return Number;
//}
//
//float MySqrt(float Number) {
//    if (Number < 0) {
//        return -1; // أفضل من إرجاع 0 للأعداد السالبة
//    }
//
//    if (Number == 0) {
//        return 0;
//    }
//
//    float X = Number / 2;
//    for (int i = 1; i <= 4; i++) {
//        X = (X + (Number / X)) / 2;
//    }
//    return X;
//}
//
//int main() {
//    float Num = ReadNumber("أدخل رقمًا من فضلك");
//    float myResult = MySqrt(Num);
//
//    if (myResult == -1) {
//        cout << "No Negative" << endl;
//    }
//    else {
//        cout << "My: " << myResult << endl;
//        cout << " C++: " << sqrt(Num) << endl;
//    }
//
//    return 0;
//}