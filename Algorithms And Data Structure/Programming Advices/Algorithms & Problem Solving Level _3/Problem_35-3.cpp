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

//void PrintEachWordInString(string Text)
//{
//    cout << "\nYour String Words are : \n\n";
//
//    for (short i = 0; i < Text.length(); i++)
//    {
//        if (Text[i] != ' ')
//        {
//            cout << Text[i];
//        }
//
//        else
//        {
//            cout << "\n";
//            continue;
//        }
//    }
//
//    cout << "\n\n";
//
//}

//void PrintEachWordInString(string Text)
//{
//    cout << "\nYour String Words are : \n\n";
//
//    for (short i = 0; i < Text.length(); i++)
//    {
//        if (Text[i] != ' ')
//            cout << Text[i];
//
//        if (Text[i] == ' ')
//            cout << '\n';
//
//        else
//            continue;
//    }
//
//    cout << "\n\n";
//
//}


//Best Way...

//void PrintEachWordInString(string Text)
//{
//    cout << "\nYour String Words are : \n\n";
//
//    for (short i = 0; i < Text.length(); i++)
//    {
//        if (Text[i] != ' ')
//        {
//            for (short j = i; j < Text.length() && Text[j] != ' '; j++)
//            {
//                cout << Text[j];
//                i = j;
//            }
//
//            cout << "\n";
//        }
//
//        else
//            continue;
//    }
//
//    cout << "\n\n";
//
//}


//Programming Advice...

void PrintEachWordInString(string Text)
{
    string delim = " ";// delimiter

    cout << "\nYour String Words are : \n\n";

    short Pos = 0;
    string sWord;// define a string variable 

    // use find() function to get the position of the delimiters
    while ((Pos = Text.find(delim)) != string::npos) /*Text.npos == std::string::npos == string::npos*/
    {
        sWord = Text.substr(0, Pos);// store the word

        if (sWord != "")
        {
            cout << sWord << endl;
        }

        Text.erase(0, Pos + delim.length());/* erase() until positon and move to next word. */

    }

   if (Text != "")
   {
       cout << Text << endl; // it print last word of the string...
   }


}

int main()
{
    string Text = ReadText("Please Enter Your String ? \n");

    PrintEachWordInString(Text);

    system("pause>0");
 }

//Mohammad Mahmoud Rajab Agha @ProgrammingAdvice