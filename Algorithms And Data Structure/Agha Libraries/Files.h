#pragma once

#pragma warning(disable : 4996)

#include<iostream>
#include<fstream>
#include<string>
#include "ReadInputs.h"
#include<vector>
using namespace std;

namespace Files
{
    void AppendDataToFile(const string& FileName, string Data )
    {
        fstream File;

        File.open(FileName, ios::out | ios::app);//Append Mode...

        if (File.is_open())
        {
            File << Data << endl;

            File.close();
        }
    }

    string ReadFileName(string Message)
    {
        string FileName;

        FileName = ReadInputs::ReadText(Message);
        
        FileName.append(".txt");//Enter File Name (Without \".txt\")
        
        
        return FileName;
    }

    void PrintFileContent(const string& FileName)
    {
        fstream File;

        File.open(FileName, ios::in);//Read Mode...

        if (!File)
        {
            cout << "Invalid Path or File doesn't exist!\n";
            return;
        }

        if (File.is_open())
        {
            string Line;

            while (getline(File, Line))
            {
                cout << Line << endl;
            }
            File.close();
        }
    }

    void ClearFileContent(const string& FileName)
    {
        fstream File;

        File.open(FileName, ios::out);//Write Mode...

        if (File.is_open())
        {
            File.close();
        }

    }

    void CopyFileContentToAnotherFile(string FileNameFrom, string FileNameTo)
    {
        fstream MyFileFrom, MyFileTo;

        MyFileFrom.open(FileNameFrom, ios::in);
        MyFileTo.open(FileNameTo, ios::out | ios::app);

        string Line;

        if (MyFileFrom.is_open() && MyFileTo.is_open())
        {
            while (getline(MyFileFrom, Line))
            {
                MyFileTo << Line << endl;
            }

            MyFileTo.close();

            MyFileFrom.close();

        }


    }

    void LoadDataFromFileToVector(string FileName, vector <string>& vFileContent)
    {
        fstream MyFile;

        MyFile.open(FileName, ios::in);//Read Mode...

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                vFileContent.push_back(Line);
            }

            MyFile.close();
        }
    }

    void SaveVectorToFile(const vector <string>& vFileContent,string FileName)
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

    void DeletRecordFromFile( string Record,string FileName)
    {
        vector <string> vFileContent;

        LoadDataFromFileToVector(FileName, vFileContent);

        for (string& Line : vFileContent)
        {
            if (Line == Record)
            {
                Line = "";
            }
        }

        SaveVectorToFile(vFileContent, FileName);

    }

    void DeletLineInFile(short unsigned Line, string FileName)
    {
        vector <string> vFileContent;

        LoadDataFromFileToVector(FileName, vFileContent);

        vFileContent.at(Line - 1) = "";

        SaveVectorToFile(vFileContent, FileName);

    }

    void UpdateRecordInFile(string FileName, string Record, string UpdateTo)
    {
        vector <string> vFileContent;

        LoadDataFromFileToVector(FileName, vFileContent);

        for (string& Line : vFileContent)//& is Necessary...
        {
            if (Line == Record)
            {
                Line = UpdateTo;
            }
        }

        SaveVectorToFile(vFileContent, "File.txt");

    }

}