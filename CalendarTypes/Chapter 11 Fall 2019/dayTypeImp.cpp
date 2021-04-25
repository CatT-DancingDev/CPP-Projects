//========================================================================//
// Catherine Trujillo
// CSC 161-C00
// 9/18/19
//
// Program 11
// Description: Program to define and implement classes for dateType, calendarType, extDateType, and dayType
//=============================================================================//
#include"dayType.h"
#include<string>
#include<iostream>
using namespace std;

// +++++++ SETTER +++++++ //
void dayType::setDay(string d)
{
	day = d;
}

// ++++++++++ Output function ++++++++++++ //
void dayType::printDay() const
{
	cout << day;
}

// +++++++++++ Getter +++++++++++++++++//
string dayType::getDay() const
{
	return day;
}

// ++++++++++++ Operation Functions +++++++++++++++//
string dayType::getNextDay() const
{
	if (day == "Sunday")
		return "Monday";
	else if (day == "Monday")
		return "Tuesday";
	else if (day == "Tuesday")
		return "Wednesday";
	else if (day == "Wednesday")
		return "Thursday";
	else if (day == "Thursday")
		return "Friday";
	else if (day == "Friday")
		return "Saturday";
	else if (day == "Saturday")
		return "Sunday";
}
string dayType::getNextDay(string d) const
{
	if (d == "Sunday")
		return "Monday";
	else if (d == "Monday")
		return "Tuesday";
	else if (d == "Tuesday")
		return "Wednesday";
	else if (d == "Wednesday")
		return "Thursday";
	else if (d == "Thursday")
		return "Friday";
	else if (d == "Friday")
		return "Saturday";
	else if (d == "Saturday")
		return "Sunday";
}

string dayType::getPreviousDay() const
{
	if (day == "Sunday")
		return "Saturday";
	else if (day == "Monday")
		return "Sunday";
	else if (day == "Tuesday")
		return "Monday";
	else if (day == "Wednesday")
		return "Tuesday";
	else if (day == "Thursday")
		return "Wednesday";
	else if (day == "Friday")
		return "Thursday";
	else if (day == "Saturday")
		return "Friday";
}

string dayType::getPreviousDay(string d) const
{
	if (d == "Sunday")
		return "Saturday";
	else if (d == "Monday")
		return "Sunday";
	else if (d == "Tuesday")
		return "Monday";
	else if (d == "Wednesday")
		return "Tuesday";
	else if (d == "Thursday")
		return "Wednesday";
	else if (d == "Friday")
		return "Thursday";
	else if (d == "Saturday")
		return "Friday";

}

string dayType::dayPlusNoOfDays(int noOfDays) const
{
	string newDay;

	if (noOfDays % 7 == 0)
		newDay = day;
	else if ((noOfDays - 1) % 7 == 0)
		newDay = getNextDay(day);
	else if ((noOfDays + 1) % 7 == 0)
		newDay = getPreviousDay(day);
	else if ((noOfDays - 2) % 7 == 0)
	{
		newDay = getNextDay(day);
		newDay = getNextDay(newDay);
	}
	else if ((noOfDays - 3) % 7 == 0)
	{
		newDay = getNextDay(day);
		newDay = getNextDay(newDay);
		newDay = getNextDay(newDay);

	}

	else if ((noOfDays + 2) % 7 == 0)
	{
		newDay = getPreviousDay(day);
		newDay = getPreviousDay(newDay);
	}

	else if ((noOfDays + 3) % 7 == 0)
	{
		newDay = getPreviousDay(day);
		newDay = getPreviousDay(newDay);
		newDay = getPreviousDay(newDay);
	}

	return newDay;
}

// ++++++++++++ Constructors ++++++++++++++++++//
dayType::dayType()
{
	day = "";
}
dayType::dayType(string d)
{
	day = d;
}