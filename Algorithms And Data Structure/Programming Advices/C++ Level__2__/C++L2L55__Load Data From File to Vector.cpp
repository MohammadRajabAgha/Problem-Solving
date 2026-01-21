#include <iostream>
#include<string>
#include<vector>
#include<fstream>

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

int main()
{
    vector <string> vFileContent;

    LoadDataFromFileToVector("File.txt", vFileContent);

    for (const string& Line : vFileContent) 
    {
        cout << Line << endl;
    }




}




