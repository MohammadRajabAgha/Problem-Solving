#include <iostream>
#include <string>     
using namespace std;

string ReadPassword(string Message)
{
    string Password;
    cout << Message << endl;
    cin >> Password;

    return Password;
}

bool GuessPassword(string OriginalPassword)
{
    int Count = 0;
    cout << "\n";

    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                string GuessPassword = "";
                Count++;

                GuessPassword += char(i);
                GuessPassword += char(j);
                GuessPassword += char(k);

                cout << "Trial [" << Count << "]:" << GuessPassword << endl;


                if (OriginalPassword == GuessPassword)
                {
                    cout << "\nPassword is " << GuessPassword << "\n";
                    cout << "Found after " << Count << " Trial(s)\n";
                    return true;//important.
                }
               
                
            }
        }
    }
    
    return false;//important.
}

int main()
{
    GuessPassword(ReadPassword("PLeas enter a 3-Letter Password (all Capital)?"));

    return 0;
}


//#include <iostream>
//#include <string>     
//#include <chrono> // للقياس الزمني
//#include <iomanip> // للتنسيق
//#include <windows.h> // 
//
//using namespace std;
//using namespace std::chrono;
//
//void SetMaxPerformance() 
//{
//    SetThreadExecutionState(ES_CONTINUOUS | ES_SYSTEM_REQUIRED);
//    
//     //SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
//}
//
//string ReadPassword(string Message)
//{
//    string Password;
//    cout << Message << endl;
//    cin >> Password;
//
//    return Password;
//}
//
//bool GuessPassword(string OriginalPassword)
//{
//    auto start = high_resolution_clock::now();
//    int Count = 0;
//
//    cout << "\n";
//
//    for (int i = 65; i <= 90; i++)
//    {
//        for (int j = 65; j <= 90; j++)
//        {
//            for (int k = 65; k <= 90; k++)
//            {
//                string GuessPassword = "";
//                Count++;
//
//                GuessPassword += char(i);
//                GuessPassword += char(j);
//                GuessPassword += char(k);
//
//                cout << "Trial [" << Count << "]:" << GuessPassword << "\n";
//
//                // تنظيف الشاشة كل 50 محاولة
//                if (Count % 50 == 0)
//                {
//                    cout << "\rCurrent trial: " << Count << " - Testing: " << GuessPassword;
//                    cout.flush();
//                }
//
//                if (OriginalPassword == GuessPassword)
//                {
//                    auto stop = high_resolution_clock::now();
//                    auto duration = duration_cast<microseconds>(stop - start);
//
//                    cout << "\nPassword is " << GuessPassword << "\n";
//                    cout << "Found after " << Count << " Trial(s)\n";
//                    cout << fixed << setprecision(6);
//                    cout << "Execution time: " << duration.count() / 1000000.0 << " seconds\n";
//                    return true;//important.
//                }
//
//
//            }
//        }
//    }
//    auto stop = high_resolution_clock::now();
//    auto duration = duration_cast<microseconds>(stop - start);
//    cout << fixed << setprecision(6);
//    cout << "Execution time: " << duration.count() / 1000000.0 << " seconds\n";
//
//    return false;//important.
//}
//
//int main()
//{
//    SetMaxPerformance();
//
//    GuessPassword(ReadPassword("PLeas enter a 3-Letter Password (all Capital)?"));
//
//    return 0;
//}