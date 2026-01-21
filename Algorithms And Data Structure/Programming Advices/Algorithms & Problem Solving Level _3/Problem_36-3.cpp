#include <iostream> 
#include<string>
#include<cctype> 

using namespace std;

string ReadText(const string& Message)
{
    string Text;

    cout << Message;

    getline(cin, Text);

    return Text;

}

short CountWordsInString(string Text)
{
    string delim = " ";// delimiter
    short Counter = 0;
    short Pos = 0;
    string sWord;// define a string variable 

    // use find() function to get the position of the delimiters
    while ((Pos = Text.find(delim)) != string::npos) /*Text.npos == std::string::npos == string::npos*/
    {
        sWord = Text.substr(0, Pos);// store the word

        if (sWord != "")
        {
            Counter++;
        }

        Text.erase(0, Pos + delim.length());/* erase() until positon and move to next word. */

    }

    if (Text != "")
    {
        Counter++; // it Count last word of the string...
    }

    return Counter;
}

int main()
{
    string Text = ReadText("Please Enter Your String ? \n");

    cout << "\nThe Number Of Words in Your String is : " << CountWordsInString(Text) << endl;

    system("pause>0");
}

//Mohammad Mahmoud Rajab Agha @ProgrammingAdvice