#pragma once

#pragma warning(disable : 4996)

#include<iostream>
#include<string>
#include <limits>
#include <cctype> // لاستخدام isalpha()
using namespace std;

namespace ReadInputs
{
    int ReadNumber(string Message)
    {
        int Number; 

        cout << Message;
        cin >> Number; 

        while (cin.fail()) 
        {
            // user didn't input a number   
             cin.clear();     
             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

             cout << "Invalid Number, Enter a valid one:" << endl;   
             cin >> Number;   

        }
        return Number;
    }

    short ReadShortNumber(string Message)
    {
        short Number;

        cout << Message;
        cin >> Number;

        while (cin.fail())
        {
            // user didn't input a number   
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Invalid Number, Enter a valid one:" << endl;
            cin >> Number;

        }
        return Number;
    }

    int ReadPositiveNumber(string Message) 
    {
        int Number = 0;

        do
        {

            Number = ReadNumber(Message);

        } while (Number < 0);

        return Number;
    }

    int ReadNegativeNumber(string Message)
    {
        int  Number = 0;

        do
        {

            Number = ReadNumber(Message);

        } while (Number > 0);

        return Number;
    }

    bool ReadBooleanInput(string Message)
    {
        //The input You Should By Number {0/1}.
        int Num = 0;

        cout << Message << "\n";
        cin >> Num;

        return Num;
    }

    int ReadNumberInRange(int From, int To, string Message)
    {
        int Number = 0;

        do
        {
            Number = ReadNumber(Message + " [" + to_string(From) + "-" + to_string(To) + "]: ");

        } while (Number < From || Number > To);

        return Number;
    }

    float ReadFloatNumber(string Message)
    {
        float Number = 0;

       
        cout << Message;
        cin >> Number;

        while (cin.fail())
        {
            // user didn't input a number   
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      
            cout << "Invalid Number, Enter a valid one:" << endl;
            cin >> Number;
        }

        return Number;
    }

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
                cout << "Input cannot be empty. Please try again.\n";
            }

        } while (Text.empty());

        return Text;
    }

    string GetFullName(string FirstName, string LastName, bool Reversed = 0)
    {
        string FullName = "";

        if (Reversed)
            FullName = LastName + " " + FirstName;

        else
            FullName = FirstName + " " + LastName;

        return FullName;
    }

    char ReadChar(const string& Message)
    {
        char Character;

        while (true) {
            cout << Message;
            cin >> Character;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input (cin failed), please try again: ";
            }
            else if (!isalpha(Character)) { // إذا لم يكن حرفًا أبجديًا
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input (must be a letter), please try again: ";
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return Character;
            }
        }
    }

    char GetGradeLetter(int Grade)
    {
        if (Grade >= 90)
            return 'A';

        else if (Grade >= 80)
            return 'B';

        else if (Grade >= 70)
            return 'C';

        else if (Grade >= 60)
            return 'D';

        else if (Grade >= 50)
            return 'E';

        else
            return 'F';
    }

    enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };
    enOperationType ReadOperationType()
    {
        char OpT = '+';

        cout << "Pleas enter Operation Type ( + , - , * , / )? \n";
        cin >> OpT;

        return (enOperationType)OpT;
    }

}

