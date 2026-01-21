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

void DeletRecordFromFile(string FileName, string Record)
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
    cout << "File Content Before Delete.\n";
    PrintFileContent("File.txt");

    DeletRecordFromFile("File.txt", "Mohammad Agha");

    cout << "\n\nFile Content After Delete.\n";
    PrintFileContent("File.txt");



    return 0;

}

