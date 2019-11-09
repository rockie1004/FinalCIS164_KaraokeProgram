#pragma once
#pragma warning(disable : 4996)//compiler can't do locatltime_s function so this stops the prompting for avoiding deprecated localtime function.
#include <time.h>       /* time_t, struct tm, time, mktime */
#include <string>
#include <iostream>
#include <iterator> 
#include <utility>
using namespace std;
////global


void days();
struct tm* setDate(int, int, int);
struct tm* setDate(int, int, int, time_t&);
int getInputReprompt(std::string, int, int);

void addDays(tm*, int);
std::string displayDate(const tm* const timeinfo);


//adapted from http://www.cplusplus.com/reference/ctime/mktime/
 struct tm* setDate(int year, int month, int day)
 {
	 time_t rawtime;
	 return setDate(year, month, day, rawtime);
 }
struct tm* setDate(int year, int month, int day, time_t& storeTime) {
	struct tm* timeinfo;

	/* get current timeinfo and modify it to the user's choice */
	time(&storeTime);
	timeinfo = localtime(&storeTime);
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	/* call mktime: timeinfo->tm_wday will be set */
	storeTime=mktime(timeinfo);
	return timeinfo;
};

tm* addDays(tm* startingDate, int addDays) {
	tm* newDate = startingDate;
	newDate->tm_mday += addDays;
	mktime(newDate);
	return newDate;
};

//returns date as a string
std::string displayDate(tm* dateStruct) {
	char    time_buf[256];
	strftime(time_buf, sizeof(time_buf),
		"%D", dateStruct);
	return time_buf;
};
string dateToKey(tm* dateStruct) {
	char    time_buf[256];
	strftime(time_buf, sizeof(time_buf),
		"%F", dateStruct);
	return time_buf;
};

//Promput user for the components of a date, enforce ranges
tm* userInputDate() {
	const int MIN_YEAR = 1980;
	const int MAX_YEAR = 2300;
	const int MIN_MONTH = 1;
	const int MAX_MONTH = 12;
	const int MIN_DAY = 1;
	int max_day = 31;
	int month, day, year = 0;
month=	getInputReprompt("Enter the month:", MIN_MONTH, MAX_MONTH);
switch (month) {
case 1: max_day = 31; break;
case 2: max_day = 29; break;
case 3: max_day = 31; break;
case 4: max_day = 30; break;
case 5: max_day = 31; break;
case 6: max_day = 30; break;
case 7: max_day = 31; break;
case 8: max_day = 31; break;
case 9: max_day = 30; break;
case 10: max_day = 31; break;
case 11: max_day = 30; break;
case 12: max_day = 31; break;
default:cout << "Error, max day set to 31."; break;
}
day=	getInputReprompt("Enter the day:", MIN_DAY, max_day);
year=	getInputReprompt("Enter the year:", MIN_YEAR,MAX_YEAR);
	return setDate(year, month, day);
}


/*Amy's input validating function for integer within a range. Continues reprompting until input is acceptable.
int getInputReprompt(std::string, int, int);
*/
int getInputReprompt(std::string promptMessage, int minRange, int maxRange) {
	int input;
	bool isInvalidInput;
	std::string invalidMessage = "Error: Enter an integer between " + std::to_string(minRange) + " and " + std::to_string(maxRange) + ". ";

	do {
		std::cout << promptMessage;
		std::cin >> input;
		if (isInvalidInput = std::cin.fail()) //invalid input 
		{
			std::cout << "Input Type " << invalidMessage;
			isInvalidInput = true;
		}
		if (input<minRange || input>maxRange) //outside range
		{
			std::cout << "Outside Range " << invalidMessage;
			isInvalidInput = true;
		}
		if (isInvalidInput) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
	} while (isInvalidInput);
	return input;
}

/*Amy's input validating function for double over the min. Continues reprompting until input is acceptable.
int getInputReprompt(std::string, double);
*/
double getInputReprompt(std::string promptMessage, double minRange) {
	double input;
	bool isInvalidInput;
	std::string invalidMessage = "Error: Enter an amount greater than " + std::to_string(minRange)+ ". ";

	do {
		std::cout << promptMessage;
		std::cin >> input;
		if (isInvalidInput = std::cin.fail()) //invalid input 
		{
			std::cout << "Input Type " << invalidMessage;
			isInvalidInput = true;
		}
		if (input<minRange ) //outside range
		{
			std::cout << "Outside Range " << invalidMessage;
			isInvalidInput = true;
		}
		if (isInvalidInput) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
	} while (isInvalidInput);
	return input;
}




/////////////////////////////////////////
///for testing or not sure if needed........
///////////////////////////////////////////

void days()
{
	time_t rawtime;
	struct tm* timeinfo;
	int year, month, day;
	const char* weekday[] = { "Sunday", "Monday",
							   "Tuesday", "Wednesday",
							   "Thursday", "Friday", "Saturday" };

	/* prompt user for date */
	printf("Enter year: "); fflush(stdout); scanf("%d", &year);
	printf("Enter month: "); fflush(stdout); scanf("%d", &month);
	printf("Enter day: "); fflush(stdout); scanf("%d", &day);

	timeinfo = setDate(year, month, day);

	/* call mktime: timeinfo->tm_wday will be set */


	printf("That day is a %s.\n", weekday[timeinfo->tm_wday]);
	int moreDays = 60;

	addDays(timeinfo, moreDays);

	printf("%x more days is a %s:\n", moreDays, weekday[timeinfo->tm_wday]);
	std::cout << displayDate(timeinfo);

}
/*may not be needed if not using time_t as a key in any map...
tm* userInputDate(time_t& date_t) {
	int month, day, year = 0;
	day = getInputReprompt("Enter the month:", 1, 12);
	month = getInputReprompt("Enter the day:", 1, 31);
	year = getInputReprompt("Enter the year:", 1900, 3000);

	return setDate(year, month, day, date_t);
}
*/