#include <iostream>
#include <vector>
using namespace std;

void ReadNumbersInVector(vector <int>& vNumbers)
{
    int Number = 0;
    char ReadMore = 'Y';

    while (ReadMore == 'Y' || ReadMore == 'y')
    {
        cout << "Please enter a Number ? ";
        cin >> Number;

        vNumbers.push_back(Number);

        cout << "Do You Want To Add More ? [Y/N] ? ";
        cin >> ReadMore;

        cout << "\n";
    }

}

void PrintNubmersInvector(vector <int>& vNumbers)
{
    cout << "Vrctor Number : \n";

    for (int Number : vNumbers)
    {
        cout << Number << "\n";
    }

    cout << endl;
}

int main()
{
    vector <int> vNumbers;

    ReadNumbersInVector(vNumbers);
    PrintNubmersInvector(vNumbers);

    return 0;

}

//My Solution 2 better ٍSolution


//#include <iostream>
//#include <vector>
//using namespace std;
//
//void ReadNumbersInVector(vector <int>& vNumbers)
//{
//    int Number = 0;
//    char ReadMore = 'Y';
//
//    while (ReadMore == 'Y' || ReadMore == 'y')
//    {
//        cout << "Please enter a Number ? ";
//        cin >> Number;
//
//        vNumbers.push_back(Number);
//
//        cout << "Do You Want To Add More ? [Y/N] ? ";
//        cin >> ReadMore;
//
//        cout << "\n";
//    }
//
//}
//
//void PrintNubmersInvector(const vector <int>& vNumbers)
//{
//    cout << "Vrctor Number : \n";
//
//    for (const int& Number : vNumbers)
//    {
//        cout << Number << "\n";
//    }
//
//    cout << endl;
//}
//
//int main()
//{
//    vector <int> vNumbers;
//
//    ReadNumbersInVector(vNumbers);
//    PrintNubmersInvector(vNumbers);
//
//    return 0;
//
//}





//My Solution...

//#include <iostream>
//#include <vector>
//using namespace std;
//
//void ReadNumbersInVector(vector <int>& vNumbers, string Message)
//{
//    int Number = 0;
//    char AddMore = 'Y';
//
//    do
//    {
//        cout << Message;
//        cin >> Number;
//        vNumbers.push_back(Number);
//
//        cout << "Do You Want To Add More ? [Y/N] ? ";
//        cin >> AddMore;
//
//        cout << "\n";
//
//    } while (AddMore == 'Y' || AddMore == 'y');
//
//}
//
//void PrintNubmersInvector(vector <int>& vNumbers)
//{
//    for (int& Number : vNumbers)
//    {
//        cout << Number << " ";
//    }
//    cout << endl;
//}
//
//
//int main()
//{
//    vector <int> vNumbers;
//
//    ReadNumbersInVector(vNumbers, "Please enter a Number ? ");
//
//    PrintNubmersInvector(vNumbers);
//
//    return 0;
//
//}
