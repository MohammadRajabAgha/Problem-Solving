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

string ReplaceWordInString(string Text, string StringToReplace, string sReplaceTo)
{

    int Pos = Text.find(StringToReplace);

    while (Pos != string::npos)
    {
        Text.replace(Pos, StringToReplace.length(), sReplaceTo);

        Pos = Text.find(StringToReplace);//Find Next....
    }

    return Text;
}

string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = "";

    FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

    return FormattedDateString;
}

//My Solution

/*
enum enDateFormat { DayMonthYear = 1, YearDayMonth, MonthDayYear, DashMonthDayYear, DashDayMonthYear, StringDayMonthYear };

string FormatDate(stDate Date, enDateFormat DateFormat = enDateFormat::DayMonthYear)
{
    switch (DateFormat)
    {
    case enDateFormat::DayMonthYear:
        return to_string(Date.Day) + '/' + to_string(Date.Month) + '/' + to_string(Date.Year);

    case enDateFormat::YearDayMonth:
        return to_string(Date.Year) + '/' + to_string(Date.Day) + '/' + to_string(Date.Month);

    case enDateFormat::MonthDayYear:
        return to_string(Date.Month) + '/' + to_string(Date.Day) + '/' + to_string(Date.Year);

    case enDateFormat::DashMonthDayYear:
        return to_string(Date.Month) + '-' + to_string(Date.Day) + '-' + to_string(Date.Year);

    case enDateFormat::DashDayMonthYear:
        return to_string(Date.Day) + '-' + to_string(Date.Month) + '-' + to_string(Date.Year);

    case enDateFormat::StringDayMonthYear:
        return "Day : " + to_string(Date.Day) +
            ", Month : " + to_string(Date.Month) +
            ", Year : " + to_string(Date.Year);

    }
}
*/

int main()
{
    string DateString = ReadDateString("Please enter Date dd/mm/yyyy ? ");

    stDate Date = StringToDate(DateString);

    cout << "\n" << FormatDate(Date) << "\n";
    cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << FormatDate(Date, "Day : dd, Month : mm, Year : yyyy") << "\n";

    system("pause>0");
    return 0;
}

