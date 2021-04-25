//========================================================================//
// Catherine Trujillo
// CSC 161-C00
// 9/18/19
//
// Program 11
// Description: Program to define and implement classes for dateType, calendarType, extDateType, and dayType
//=============================================================================//
#include "dateType.h"
#include "extDateType.h"
#include <iostream>
#include <string>

using namespace std;

//++++++++++ extDate Getters +++++++++++++++//

int extDateType::getExtDay() const
{
	return dDay;
}

int extDateType::getExtMonth() const
{
	return dMonth;
}

int extDateType::getExtYear() const
{
	return dYear;
}

// ++++++ Operations and Output functions ++++++++//
string extDateType::translateMonth() const
{
	string month;

	switch (getExtMonth())
	{
	case 1:
		month = "January";
		break;
	case 2:
		month = "February";
		break;
	case 3:
		month = "March";
		break;
	case 4:
		month = "April";
		break;
	case 5:
		month = "May";
		break;
	case 6:
		month = "June";
		break;
	case 7:
		month = "July";
		break;
	case 8:
		month = "August";
		break;
	case 9:
		month = "September";
		break;
	case 10:
		month = "October";
		break;
	case 11:
		month = "November";
		break;
	case 12:
		month = "December";
		break;
	default:
		break;
	}
	return month;
}

void extDateType::printDateNumeric() const
{
	cout << dMonth << "-" << dDay << "-" << dYear << endl;
}

void extDateType::printDateString() const
{
	cout << translateMonth() << " " << dDay << ", " << dYear << endl;
}

void extDateType::printMonthYearString() const
{
	cout << translateMonth() << " " << dYear << endl;
}

//++++++++++++++++++ Constructors +++++++++++++++++//

extDateType::extDateType() 
{
	dMonth = 1;
	dDay = 1;
	dYear = 1;
}
extDateType::extDateType(int month, int day, int year)
	: dateType(month, day, year)
{
	monthString = translateMonth();
}









