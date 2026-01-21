#include<iostream>
#include<cmath>
#include <string>
using namespace std;

struct strTaskDuration
{
	int NumberOfDays, NumberOfHours, NumberOfMinutes, NumberOfSeconds;
};

float ReadPositiveNumber(string Message)
{
	float Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

strTaskDuration SecondsToTaskDuration(int TotalSeconds)
{
	strTaskDuration TaskDuration;
	int Reminder = 0;
	

	const int SecondsPerDay = 24 * 60 * 60;
	const int SecondsPerHours = 60 * 60;
	const int SecondsPerMinutes = 60;

	TaskDuration.NumberOfDays = floor(TotalSeconds / SecondsPerDay);
	Reminder = TotalSeconds % SecondsPerDay;

	TaskDuration.NumberOfHours = floor(Reminder / SecondsPerHours);
	Reminder = Reminder % SecondsPerHours;

	TaskDuration.NumberOfMinutes = floor(Reminder / SecondsPerMinutes);
	Reminder = Reminder % SecondsPerMinutes;

	TaskDuration.NumberOfSeconds = Reminder;


	return TaskDuration;
}

void PrintTotalSeconds(strTaskDuration TaskDuration)
{
	cout << TaskDuration.NumberOfDays << ":"
		<< TaskDuration.NumberOfHours << ":"
		<< TaskDuration.NumberOfMinutes << ":"
		<< TaskDuration.NumberOfSeconds << ":";
}

int main()
{
	int TotalSeconds = ReadPositiveNumber("Pleas enter Number Of seconds?");

	PrintTotalSeconds(SecondsToTaskDuration(TotalSeconds));

	return 0;
}