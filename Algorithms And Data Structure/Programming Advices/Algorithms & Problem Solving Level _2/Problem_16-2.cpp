#include <iostream>   
#include <string>     
using namespace std;

void PrintAllWordsFromAAAtoZZZ()
{
    cout << "\n";
    string Word = "";

    for (int i = 65; i <= 90; i++)
    {
        cout << char(i);
  
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                Word = Word + char(i);
                Word = Word + char(j);
                Word = Word + char(k);

                cout << Word << endl;
                Word = "";
            }
        }
        cout << "\n*****************************************\n";
    }
}

int main()
{
    PrintAllWordsFromAAAtoZZZ();

    return 0;
}


//#include <iostream>   
//#include <string>     
//using namespace std;
//
//
//void PrintAllWordsFromAAAtoZZZ()
//{
//
//    for (int i = 65; i <= 90; i++)
//    {
//        cout << char(i) << endl;
//        cout << "*****************************************\n\n";
//
//        for (int j = 65; j <= 90; j++)
//        {
//            for (int k = 65; k <= 90; k++)
//            {
//                cout << char(i) << char(j) << char(k);
//                cout << "\n";
//            }
//        }
//    }
//}
//
//
//int main()
//{
//    PrintAllWordsFromAAAtoZZZ();
//
//    return 0;
//}
