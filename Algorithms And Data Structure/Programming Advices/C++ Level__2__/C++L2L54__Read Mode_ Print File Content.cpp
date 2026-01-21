
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void PrintFileContent(const string& FileName)
{
    fstream MyFile;

    MyFile.open(FileName, ios::in);//Read Mode...

    if (!MyFile)
    {
        cout << "Invalid Path or File doesn't exist!\n";
        return;
    }

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            cout << Line << endl;
        }
        MyFile.close();
    }
}

void ClearFileContent(const string& FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
        MyFile.close();
    }
}

int main()
{
    PrintFileContent("MyFile.txt");

    return 0;

}   

//Project To Practes...

//#include <iostream>
//#include <string>
//#include <fstream>
//#include "C:\Users\ASUS\MyLibrary\MyLibraries.h"
//using namespace std;
//
//void ReadDataToFile(const string& FileName, string Data)
//{
//    fstream File;
//
//    File.open(FileName, ios::out | ios::app);//Append Mode...
//
//    if (File.is_open())
//    {
//        File << Data << endl;
//
//        File.close();
//    }
//}
//
//void PrintFileContent(const string& FileName)
//{
//    fstream File;
//
//    File.open(FileName, ios::in);//write Mode...
//
//    if (File.is_open())
//    {
//        string Line;
//
//        while (getline(File, Line))
//        {
//            cout << Line << endl;
//        }
//
//        File.close();
//    }
//}
//
//void CopyFileContentToAnotherFile(string FileNameFrom, string FileNameTo)
//{
//    fstream  MyFileFrom, MyFileTo;
//
//    MyFileFrom.open(FileNameFrom, ios::in);//Write Mode...
//    MyFileTo.open(FileNameTo, ios::out | ios::app);//Append Mode...
//
//    if (MyFileFrom.is_open() && MyFileTo.is_open())
//    {
//        string Line;
//
//        while (getline(MyFileFrom, Line))
//        {
//            MyFileTo << Line << endl;
//        }
//
//        MyFileFrom.close();
//        MyFileTo.close();
//    }
//}
//
//string ReadFileName(string Message)
//{
//    string FileName;
//
//    cout << Message;
//    cin >> FileName;
//
//    FileName.append(".txt");
//
//    return FileName;
//}
//
//int main()
//{
//    string FileName1 = ReadFileName("Please enter File Name ? Without[\".txt\"] : ");
//
//    string FileName2 = ReadFileName("Please enter File Name ? Without[\".txt\"] : ");
//
//    ReadDataToFile(FileName1, ReadInputs::ReadText("Please Enter Data ? "));
//
//    cout << "File 1 : \n";
//    PrintFileContent(FileName1);
//
//    CopyFileContentToAnotherFile(FileName1, FileName2);
//
//    cout << "File 2 After Copy : \n";
//    PrintFileContent(FileName1);
//
//
//
//    return 0;
//}