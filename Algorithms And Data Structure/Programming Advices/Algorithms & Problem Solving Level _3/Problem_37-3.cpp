#include<iostream>
#include<string>
#include<vector>

using namespace std;

string ReadText(string Message)
{
    string Text = "";

    cout << Message;

    if (cin.peek() == '\n')
    {
        cin.ignore(1, '\n');
    }

    do
    {
        getline(cin, Text);

        if (Text.empty())
        {
            cout << "⚠️ Input cannot be empty. Please try again.\n";
        }

    } while (Text.empty());

    return Text;

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

void PrintVector(vector<string>& vString)
{
    for (string& S : vString)
    {
        cout << S << "\n";
    }
}

int main()
{
    string Text;
    vector <string> vString;

    Text = ReadText("Please Enter Your String : ");

    vString = SplitString(Text, " ");

    cout << "\n\nTokens = " << vString.size() << "\n";
    PrintVector(vString);

}