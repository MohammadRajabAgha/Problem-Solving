#include <iostream>
#include <string>
using namespace std;

void DeletTextFromLine(string& Line, short unsigned DeletFrom, short unsigned DeletTo)
{
    Line.erase(DeletFrom, DeletTo);
}


int main()
{
    string S1 = "My Name is Mohammad Mahmoud Raja Agha.";

    cout << "Delet Text From Line : "; 
    DeletTextFromLine(S1, 3, 6);

    cout <<"\n"<< S1 << endl;

    //Prints the length of the string
    cout << "\n1 - " << "The Length Of The String : " << S1.length() << "\n\n";

    //Returns the letter at Index 3 and Position 4...
    cout << "2 - " << "The Letter at Index 3 and Position 4 : " << S1.at(3) << "\n\n";

    //Adds @ProgrammingAdvices to the end of string
    cout << "3 - " << "Adds 'Text' to the end of string : " << S1.append(" @Programing Advice.") << "\n\n";
    
    //inserts Ali at Index 20    
    cout << "4 - " << "Inserts Ali at Index 7 Exactly : " << S1.insert(7, " Ali ") << "\n\n";

    //Prints all the next 8 letters from position 16.
    cout << "5 - " << "Prints all The Next 8 Letters From Position 16 : " << S1.substr(16, 8) << "\n\n";//Mohammad

    //Adds One Character To The End Of The String
    S1.push_back('X');
    cout << "6 - " << "Adds One Character (X) To The End Of The String : " << S1 << "\n\n";

    //Removes One Character From The End Of The String    
    S1.pop_back();     
    cout << "7 - " << "Remove 1 Character (X) From The End Of The String : " << S1 << "\n\n";

    //Finds Mohammad in the string    
    cout << "8 - " << "Find Text (\"Mohammad\") in The String : "
         << S1.find("Mohammad") << "\n\n";//return The Index Of (M)...

    cout << "9 - " << "Find Text (\"mohammad\") in The String : "
         << S1.find("mohammad") << "\n\n";//return  18446744073709551615

    cout << "10 - " << "Find Text (\"mohammad\") in The String : ";
    if (S1.find("mohammad") == S1.npos)
    {
        cout << "mohammad Not Found. " << "\n\n";
    }

    cout << "11 - " << "The Number Of No Position in String : " << S1.npos << "\n\n";

    //clears all string letters.  
    S1.clear(); 
    if (S1.empty())
    {
        cout << "12 - " << "S1 : " << "Empty" << "\n\n";
    }
    else
    {
        cout << "12 - " << "S1 : " << S1 << "\n\n";

    }

    return 0;
}


//#include <iostream>
//#include <string>
//using namespace std;
//
//
//int main()
//{
//    string S1 = "My Name is  Mohammad Mahmoud Raja Agha.";
//
//    string S2;
//
//
//    cout << "\n*****************************************\n\n";
//
//    cout << "S1: " << S1 << "\n\n";
//
//    for (int i = 0; i < S1.length(); i++)
//    {
//        S2 += S1.at(i);
//    }
//
//    cout << "S2 : " << S2 << "\n";
//
//    cout << "\n*****************************************\n\n";
//
//    for (int i = S1.length(); i >= 0; i--)
//    {
//        S1 = S1.insert(i, "*");
//    }
//    cout << "S1 After Modification : " << S1 << "\n\n";
//
//    cout << "\n*****************************************\n\n";
//
//    S1 = "My Name is  Mohammad Mahmoud Raja Agha.";
//
//    cout << "\n*****************************************\n\n";
//
//    S2.clear();
//
//    for (const char& c : S1)
//    {
//        S2.push_back('*');  // نضيف نجمة قبل كل حرف
//        S2.push_back(c);    // نضيف الحرف نفسه
//    }
//
//    cout << "S2 After Modification : " << S2 << "\n\n";
//
//    cout << "\n*****************************************\n\n";
//
//    cout << "Find Text (\"Mohammad\") in The String : \n";
//    cout << S1.find("  Mohammad") << endl;
//    cout << S1.find(" Mohammad") << endl;
//    cout << S1.find("Mohammad") << endl;
//
//    cout << "\nFind Text (\"mohammad\") in The String : ";
//    cout << S1.find("mohammad") << endl;
//
//    cout << "\nFind Text (\"mohammad\") in The String : ";
//    if (S1.find("mohammad") == S1.npos)
//    {
//        cout << "mohammad Not Found. " << endl;
//    }
//    cout << "\n*****************************************\n";
//    cout << "\n*****************************************\n\n";
//
//
//    //Prints the length of the string
//    cout << "1 - " << "The Length Of The String : " << S1.length() << "\n\n";
//
//    //Returns the letter at Index 3 and Position 4...
//    cout << "2 - " << "The Letter at Index 3 and Position 4 : " << S1.at(3) << "\n\n";
//
//    //Adds @ProgrammingAdvices to the end of string
//    cout << "3 - " << "Adds 'Text' to the end of string : " << S1.append(" @Programing Advice.") << "\n\n";
//
//    //inserts Ali at Index 20    
//    cout << "4 - " << "Inserts Ali at Index 7 Exactly : " << S1.insert(7, " Ali ") << "\n\n";
//
//    //Prints all the next 8 letters from position 16.
//    cout << "5 - " << "Prints all The Next 8 Letters From Position 16 : " << S1.substr(16, 8) << "\n\n";//Mohammad
//
//    //Adds One Character To The End Of The String
//    S1.push_back('X');
//    cout << "6 - " << "Adds One Character (X) To The End Of The String : " << S1 << "\n\n";
//
//    //Removes One Character From The End Of The String    
//    S1.pop_back();
//    cout << "7 - " << "Remove 1 Character (X) From The End Of The String : " << S1 << "\n\n";
//
//    //Finds Mohammad in the string    
//    cout << "8 - " << "Find Text (\"Mohammad\") in The String : "
//        << S1.find("Mohammad") << "\n\n";//return The Index Of (M)...
//
//    cout << "9 - " << "Find Text (\"mohammad\") in The String : "
//        << S1.find("mohammad") << "\n\n";//return  18446744073709551615
//
//    cout << "10 - " << "Find Text (\"mohammad\") in The String : ";
//    if (S1.find("mohammad") == S1.npos)
//    {
//        cout << "mohammad Not Found. " << "\n\n";
//    }
//
//    cout << "11 - " << "The Number Who Comes Out When No Position in String : " << S1.npos << "\n\n";
//
//    //Clears All String Letters. The First Method 
//    S1.clear();
//    //OR To Clears All String Letters. The Second Method
//
//   /* while (S2.length() > 0)
//    {
//        S2.pop_back();
//    }*/
//
//
//    if (S1.empty())
//    {
//        cout << "12 - " << "S1 : " << "Empty" << "\n\n";
//    }
//    else
//    {
//        cout << "12 - " << "S1 : " << S1 << "\n\n";
//
//    }
//
//    return 0;
//}
//
//
//
//
