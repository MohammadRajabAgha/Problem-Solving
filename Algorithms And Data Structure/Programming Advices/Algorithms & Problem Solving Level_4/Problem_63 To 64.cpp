#include <iostream>
#include<string>
#include<vector>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

string ReadDateString(string Message)
{
    string DateString = "";

    cout << Message;
    getline(cin >> ws, DateString);

    return DateString;
}

vector<string> SplitString(string Text, string Delim)
{
    vector <string> vString;

    short Pos = 0;

    // define a string variable 
    string sWord;//....|| string Token;

    // use find() function to get the position of the delimiter
    while ((Pos = Text.find(Delim)) != std::string::npos)
    {
        sWord = Text.substr(0, Pos);// store the word

        if (sWord != "")
        {
            vString.push_back(sWord);
        }

        Text.erase(0, Pos + Delim.length());/* erase() until positon and move to next word. */

    }

    if (Text != "")
    {
        vString.push_back(Text);// It adds last word of the string...
    }

    return vString;

}

stDate StringToDate(string Text)
{
    vector<string> vDate = SplitString(Text, "/");
  
    stDate Date;

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string DateToString(stDate Date)
{
    return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main()
{
    string DateString = ReadDateString("Please enter Date dd/mm/yyyy ? ");

    stDate Date = StringToDate(DateString);

    cout << "\nDay : " << Date.Day;
    cout << "\nMonth : " << Date.Month;
    cout << "\nYear : " << Date.Year;


    cout << "\n\nYour Entered : " << DateToString(Date);

    system("pause>0");
    return 0;
}

