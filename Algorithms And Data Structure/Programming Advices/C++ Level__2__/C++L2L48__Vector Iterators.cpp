#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vNum = { 1,2,3,4,5 };

    vector<int>::iterator iter;

    for (iter = vNum.begin(); iter != vNum.end(); iter++)
    {
        cout << *iter << " ";
    }


    return 0;
}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//int main()
//{
//    vector <int> num{ 1, 2, 3, 4, 5 };
//
//    //vector <int>::iterator x;
//
//    for (auto x = num.begin(); x != num.end(); x++)
//    {
//        cout << *x << " ";
//    }
//
//
//    return 0;
//
//}