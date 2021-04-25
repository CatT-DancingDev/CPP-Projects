//========================================================================//
// Catherine Trujillo
// CSC 161-C00
// 9/18/19
//
// Program 11
// Description: Program to define and implement classes for dateType, calendarType, extDateType, and dayType
//=============================================================================//#include "dateType.h"
#include"dateType.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;


//++++++++ Date Setters +++++++//
void dateType::setDate(int month, int day, int year)
{	
	// Check to see if date is valid

	//month
	if (month >= 1 && month <= 12) 
		dMonth = month;
	
	//day
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 && day >= 1 && day <= 31)
		dDay = day;
	else if (month == 2 && day >= 1 && day <= 29)
		dDay = day;
	else if (month == 4 || month == 6 || month == 9 || month == 11 && day >= 1 && day <= 30)
		dDay = day;
	
	//year
	if (year > 0)
	dYear = year;
}

void dateType::setMonth(int month)
{
	if (month >= 1 && month <= 12)
		dMonth = month;
}

void dateType::setYear(int year)
{
	if (year > 0)
		dYear = year;
}
void dateType::setDay(int day)
{
	if (dMonth == 1 || dMonth == 3 || dMonth == 5 || dMonth == 7 || dMonth == 8 || dMonth == 10 || dMonth == 12 && day >= 1 && day <= 31)
		dDay = day;
	else if (dMonth == 2 && day >= 1 && day <= 29)
		dDay = day;
	else if (dMonth == 4 || dMonth == 6 || dMonth == 9 || dMonth == 11 && day >= 1 && day <= 30)
		dDay = day;
}

//+++++++++++++ Date Getters ++++++++++++++++++++++++// 

int dateType::getDay() const
{
	return dDay;
}

int dateType::getMonth() const
{
	return dMonth;
}

int dateType::getYear() const
{
	return dYear;
}
//++++++++++++ OutPut Function ++++++++++++++++++++//
void dateType::printDate() const
{
	cout << dMonth << "-" << dDay << "-" << dYear << endl;
}


//+++++ Miscellaneous Functions ++++++//
bool dateType::isLeapYear() const
{
	if (dYear % 4 == 0 && dYear % 100 == 0 && dYear % 400 == 0)
		return true;
	else if (dYear % 4 == 0 && dYear % 100 != 0)
		return true;
	else
		return false;
}

bool dateType::isLeapYear(int year) const
{
	if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
		return true;
	else if (year % 4 == 0 && year % 100 != 0)
		return true;
	else
		return false;
}

int dateType::daysInMonth() const
{
	if (dMonth == 1 || dMonth == 3 || dMonth == 5 || dMonth == 7 || dMonth == 8 || dMonth == 10 || dMonth == 12)
		return 31;
	else if (dMonth == 4 || dMonth == 6 || dMonth == 9 || dMonth == 11)
		return 30;
	else if (dMonth == 2 && isLeapYear())
		return 29;
	else if (dMonth == 2 && !isLeapYear())
		return 28;
	else
		return 0;
}

int dateType::daysPassed() const
{
	int daysTotal = 0;

	// Determine days passed in full months

	if (dMonth == 1)
		daysTotal = 0;
	else if (dMonth == 2)
		daysTotal = 31;
	else if (dMonth == 3)
	{
		if (isLeapYear())
			daysTotal = 60;
		else
			daysTotal = 59;
	}

	else if (dMonth == 4)
	{
		if (isLeapYear())
			daysTotal = 91;
		else
			daysTotal = 90;
	}

	else if (dMonth == 5)
	{
		if (isLeapYear())
			daysTotal = 121;
		else
			daysTotal = 120;
	}
	else if (dMonth == 6)
	{
		if (isLeapYear())
			daysTotal = 152;
		else
			daysTotal = 151;
	}
	else if (dMonth == 7)
	{
		if (isLeapYear())
			daysTotal = 182;
		else
			daysTotal = 181;
	}
	else if (dMonth == 8)
	{
		if (isLeapYear())
			daysTotal = 213;
		else
			daysTotal = 212;
	}
	else if (dMonth == 9)
	{
		if (isLeapYear())
			daysTotal = 244;
		else
			daysTotal = 243;
	}
	else if (dMonth == 10)
	{
		if (isLeapYear())
			daysTotal = 274;
		else
			daysTotal = 273;
	}
	else if (dMonth == 11)
	{
		if (isLeapYear())
			daysTotal = 305;
		else
			daysTotal = 304;
	}
	else if (dMonth == 12)
	{
		if (isLeapYear())
			daysTotal = 335;
		else
			daysTotal = 334;
	}
	
	return (daysTotal + dDay);

}

int dateType::daysRemaining() const
{
	if (isLeapYear())
		return (366 - daysPassed());
	else
		return (365 - daysPassed());
}

void dateType::setNewDate(int daysAdded)
{
	const int yearLength = 365;
	const int leapYearLength = 366;

	int newDateNum = 0;
	int newDateNumReduced = 0;

	int newMonth = 0;
	int newDay = 0;
	int newYear = 0;

	newDateNum = dateType::daysPassed() + daysAdded;
	newDateNumReduced = newDateNum;

	// determine year

	if (!isLeapYear() && newDateNum <= yearLength)
		newYear = dYear;
	else if (isLeapYear() && newDateNum <= leapYearLength)
		newYear = dYear;
	else
		newYear = dYear + static_cast<int>(newDateNum / (yearLength + .25));

	
	// reduce newDateNum for month and date calculations
	while (newDateNumReduced > yearLength)
	{
		newDateNumReduced = newDateNumReduced - yearLength;
	}


	// calculate month

	if (isLeapYear(newYear))
	{
		if (newDateNumReduced >= 1 && newDateNumReduced <= 31)
		{
			newMonth = 1;
			newDay = newDateNumReduced;
		}
		else if (newDateNumReduced >= 32 && newDateNumReduced <= 60)
		{
			newMonth = 2;
			newDay = newDateNumReduced - 31;
		}
		else if (newDateNumReduced >= 61 && newDateNumReduced <= 91)
		{
			newMonth = 3;
			newDay = newDateNumReduced - 60;
		}
		else if (newDateNumReduced >= 92 && newDateNumReduced <= 121)
			
		{
			newMonth = 4;
			newDay = newDateNumReduced - 91;
		}

		else if (newDateNumReduced >= 122 && newDateNumReduced <= 152)
		{
			newMonth = 5;
			newDay = newDateNumReduced - 121;
		}
		else if (newDateNumReduced >= 153 && newDateNumReduced <= 182)
		{
			newMonth = 6;
			newDay = newDateNumReduced - 152;
		}
		else if (newDateNumReduced >= 183 && newDateNumReduced <= 213)
		{
			newMonth = 7;
			newDay = newDateNumReduced - 182;
		}
		else if (newDateNumReduced >= 214 && newDateNumReduced <= 244)
		{
			newMonth = 8;
			newDay = newDateNumReduced - 213;
		}
		else if (newDateNumReduced >= 245 && newDateNumReduced <= 274)
		{
			newMonth = 9;
			newDay = newDateNumReduced - 244;
		}
		else if (newDateNumReduced >= 275 && newDateNumReduced <= 305)
		{
			newMonth = 10;
			newDay = newDateNumReduced - 274;
		}
		else if (newDateNumReduced >= 306 && newDateNumReduced <= 335)
		{
			newMonth = 11;
			newDay = newDateNumReduced - 305;
		}
		else if (newDateNumReduced >= 336 && newDateNumReduced <= 366)
		{
			newMonth = 12;
			newDay = newDateNumReduced - 335;
		}
	}

	else
	{
		if (newDateNumReduced >= 1 && newDateNumReduced <= 31)
		{
			newMonth = 1;
			newDay = newDateNumReduced;
		}
		else if (newDateNumReduced >= 32 && newDateNumReduced <= 59)
		{
			newMonth = 2;
			newDay = newDateNumReduced - 31;
		}
		else if (newDateNumReduced >= 60 && newDateNumReduced <= 90)
		{
			newMonth = 3;
			newDay = newDateNumReduced - 59;
		}
		else if (newDateNumReduced >= 91 && newDateNumReduced <= 120)
		{
			newMonth = 4;
			newDay = newDateNumReduced - 90;
		}
		else if (newDateNumReduced >= 121 && newDateNumReduced <= 151)
		{
			newMonth = 5;
			newDay = newDateNumReduced - 120;
		}
		else if (newDateNumReduced >= 152 && newDateNumReduced <= 181)
		{
			newMonth = 6;
			newDay = newDateNumReduced - 151;
		}
		else if (newDateNumReduced >= 182 && newDateNumReduced <= 212)
		{
			newMonth = 7;
			newDay = newDateNumReduced - 181;
		}
		else if (newDateNumReduced >= 213 && newDateNumReduced <= 243)
		{
			newMonth = 8;
			newDay = newDateNumReduced - 212;
		}
		else if (newDateNumReduced >= 244 && newDateNumReduced <= 273)
		{
			newMonth = 9;
			newDay = newDateNumReduced - 243;
		}
		else if (newDateNumReduced >= 274 && newDateNumReduced <= 304)
		{
			newMonth = 10;
			newDay = newDateNumReduced - 273;
		}
		else if (newDateNumReduced >= 305 && newDateNumReduced <= 334)
		{
			newMonth = 11;
			newDay = newDateNumReduced - 304;
		}
		else if (newDateNumReduced >= 335 && newDateNumReduced <= 365)
		{
			newMonth = 12;
			newDay = newDateNumReduced - 334;
		}
	}
	// Assign new values to member variables
	dMonth = newMonth;
	dDay = newDay;
	dYear = newYear;

}

	//Constructor with Parameters
dateType::dateType(int month, int day, int year)
{
	//Check to see if date is valid

	//month
	if (month >= 1 && month <= 12)
		dMonth = month;
	
	//day
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 && day >= 1 && day <= 31)
		dDay = day;
	else if (month == 2 && day >= 1 && day <= 28)
		dDay = day;
	else if (month == 4 || month == 6 || month == 9 || month == 11 && day >= 1 && day <= 30)
		dDay = day;
	
	//year
	if (year > 0)
		dYear = year;
}