#include <iostream>
#include<string>
#include<vector>
#include<fstream>
#include "C:\Users\ASUS\MyLibrary\MyLibraries.h"


using namespace std;


void SaveVectorToFile(string FileName,const vector <string>& vFileContent)
{
    fstream MyFile;

    MyFile.open(FileName, ios::out);//Write Mode...

    if (MyFile.is_open())
    {
        for (const string& Line : vFileContent)
        {
            if (Line != "")
            {
                MyFile << Line << endl;
            }
        }

        MyFile.close();
    }
}

int main()
{
    vector <string> vFileContent;

    ReadVector::ReadTextInVector(vFileContent, "Please enter Your Name ? ");

    SaveVectorToFile("File.txt", vFileContent);

    Files::PrintFileContent("File.txt");


    return 0;

}




