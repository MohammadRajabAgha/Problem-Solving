#include <iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

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

void SaveVectorToFile(const vector <string>& vFileContent, string FileName)
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

void UpdateRecordInFile(string FileName, string Record, string UpdateTo)
{
    vector <string> vFileContent;

    LoadDataFromFileToVector(FileName, vFileContent);

    for (string& Line : vFileContent)
    {
        if (Line == Record)
        {
            Line = UpdateTo;
        }
    }

    SaveVectorToFile(vFileContent, "File.txt");

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

int main()
{
    cout << "File Content Before Update.\n";
    PrintFileContent("File.txt");

    UpdateRecordInFile("File.txt", "Ali", "Zakaria");

    cout << "\n\nFile Content After Update.\n";
    PrintFileContent("File.txt");



    return 0;

}

