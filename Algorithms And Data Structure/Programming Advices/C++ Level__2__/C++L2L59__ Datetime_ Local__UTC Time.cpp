#pragma warning(disable : 4996) 

#include<ctime>
#include<iostream>

using namespace std;

string LocalTime()
{
    //"Don't Forget This Code"
//#pragma warning(disable : 4996)
    
    time_t t = time(0); // get time now

    char* dt = ctime(&t);   // convert to string form  

    return dt;
}

string GMT_Time()
{
    //"Don't Forget This Code"
  //#pragma warning(disable : 4996)

    time_t t = time(0); // get time now

    // converting now to tm struct for UTC date/time
    tm* GMT = gmtime(&t);

    char* dt = asctime(GMT);//converting time struct to String


    return dt;
}

int main()
{
    time_t t = time(0); // get time now

    char* dt = ctime(&t);   // convert to string form  

    cout << "Local date and time is: " << dt << "\n";

    // converting now to tm struct for UTC date/time
    tm* GMT = gmtime(&t);

    dt = asctime(GMT);//converting time struct to String

    cout << "UTC date and time is: " << dt;

    cout << "\n\n***********************************\n";


    cout << "Local date and time is: " << LocalTime() << "\n";

    cout << "UTC date and time is: " << GMT_Time() << "\n";

    return 0;
}