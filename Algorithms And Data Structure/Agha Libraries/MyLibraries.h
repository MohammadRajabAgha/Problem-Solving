//#pragma once
//
//#pragma warning(disable : 4996)
//
////To Calling.....
//
////#include "C:\Users\ASUS\MyLibrary\MyLibraries.h"
//
////Re:Mohammed Mahmoud Rajab Agha 
//
//
//#ifndef MY_LIBRARIES_H
//#define MY_LIBRARIES_H
//
//// أقسام المكتبات
//#include "C:\Users\ASUS\MyLibrary\NumberManipulater.h"
//
// 
// 
//#include "C:\Users\ASUS\MyLibrary\StringManipulation.h"
//
//#include "C:\Users\ASUS\MyLibrary\ArrayInputs.h"
//
//#include "C:\Users\ASUS\MyLibrary\Matrix.h"
//
//#include "C:\Users\ASUS\MyLibrary\ReadInputs.h"
//#include "C:\Users\ASUS\MyLibrary\PrintInputs.h"
//
//#include "C:\Users\ASUS\MyLibrary\PrintArray.h"
//
//#include "C:\Users\ASUS\MyLibrary\ReadVector.h"
//#include "C:\Users\ASUS\MyLibrary\PrintVector.h"
//
//
//#include "C:\Users\ASUS\MyLibrary\Files.h"
//
//
//#include "C:\Users\ASUS\MyLibrary\BankProject.h"
//
//#include "C:\Users\ASUS\MyLibrary\TimeManipulater.h"
//
//
//#endif

#pragma once

#pragma warning(disable : 4996)

//To Calling.....
//
//                                 #include "C:\Users\ASUS\MyLibrary\MyLibraries.h"
//Re:Mohammed Mahmoud Rajab Agha 



#ifndef MY_LIBRARIES_H
#define MY_LIBRARIES_H

// 1. تضمين جميع المكتبات الأساسية
#include "NumberManipulater.h"
#include "StringManipulation.h"
#include "ArrayInputs.h"
#include "Matrix.h"
#include "ReadInputs.h"
#include "PrintInputs.h"
#include "PrintArray.h"
#include "ReadVector.h"
#include "PrintVector.h"
#include "Files.h"
#include "BankProject.h"
#include "TimeManipulater.h"

// 2. إنشاء namespace تجميعي رئيسي
namespace MyLibraries
{
    // 3. إعادة تصدير namespaces الفرعية
    namespace ReadInputs = ::ReadInputs;
    namespace PrintInputs = ::PrintInputs;
    namespace ArrayInputs = ::ArrayInputs;
    namespace PrintArray = ::PrintArray;
    namespace ReadVector = ::ReadVector;
    namespace PrintVector = ::PrintVector;
    namespace Matrix = ::Matrix;
    namespace Files = ::Files;
    namespace StringManipulation = ::StringManipulation;
    namespace BankProject = ::BankProject;
    namespace NumberManipulater = ::NumberManipulater;
    namespace TimeManipulater = ::TimeManipulater;

    // 4. دوال مساعدة عامة (اختياري)
    void ShowAllAvailableNamespaces()
    {
        cout << "\n==== Available Namespaces ====\n";
        cout << "1. ReadInputs\n";
        cout << "2. PrintInputs\n";
        cout << "3. PrintLogicalResult\n";
        cout << "4. ArrayInputs\n";
        cout << "5. PrintArray\n";
        cout << "6. ReadVector\n";
        cout << "7. PrintVector\n";
        cout << "8. Matrix\n";
        cout << "9. Files\n";
        cout << "10. StringManipulation\n";
        cout << "11. BankProject\n";
        cout << "12. NumberManipulater\n";
        cout << "13. TimeManipulater\n";
        cout << "=============================\n";
    }
}

#endif