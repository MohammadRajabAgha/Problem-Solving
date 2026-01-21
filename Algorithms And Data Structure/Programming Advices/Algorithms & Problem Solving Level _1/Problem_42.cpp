#include<iostream>
#include<string>
using namespace std;

struct strTaskDuration
{
	int NumberOfDays = 0;
	int NumberOfHours = 0;
	int NumberOfMinutes = 0;
	int NumberOfSeconds = 0;
};

int ReadPositiveNumber(string Message)
{
	int Number = 0;

	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number <= 0);

	return Number;
}

strTaskDuration ReadTaskDuration()
{
	strTaskDuration TaskDuration;

	TaskDuration.NumberOfDays = ReadPositiveNumber("Pleas enter Number Of Days?");
	TaskDuration.NumberOfHours = ReadPositiveNumber("Pleas enter Number Of Hours?");
	TaskDuration.NumberOfMinutes = ReadPositiveNumber("Pleas enter Number Of Minutes?");
	TaskDuration.NumberOfSeconds = ReadPositiveNumber("Pleas enter Number Of seconds?");

	return TaskDuration;
}

int TaskDurationInSeconds(strTaskDuration TaskDuration)
{
	
	int DurationInSeconds = 0;

	DurationInSeconds = TaskDuration.NumberOfDays * 24 * 60 * 60;
	DurationInSeconds += TaskDuration.NumberOfHours * 60 * 60;
	DurationInSeconds += TaskDuration.NumberOfMinutes * 60;
	DurationInSeconds += TaskDuration.NumberOfSeconds;

	return DurationInSeconds;
}

int main()
{
	
	cout << "\nTask Duration In Seconds " << TaskDurationInSeconds(ReadTaskDuration()) << endl;

	return 0;
}