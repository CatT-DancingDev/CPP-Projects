//========================================================================//
// Catherine Trujillo
// CSC 161-C00
// 9/18/19
//
// Program 11
// Description: Program to define and implement classes for dateType, calendarType, extDateType, and dayType
//=============================================================================//
#include "dayType.h"
#include "extDateType.h"
#include "calendarType.h"
#include "dateType.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// +++++++ Getters +++++++++++//
int calendarType::getYear() const
{
	return dYear;
}
// ++++++++++ Operation functions ++++++++++++++++++ //

void calendarType::printMonthlycalendar(string d, int m, int y) const
{
	string month;
	int daysInMonth;

	// Determine String format of Month and days in Month based on numeric value of dMonth
	switch (m)
	{
	case 1:
		month = "JANUARY";
		daysInMonth = 31;
		break;

	case 2:
		month = "FEBRUARY";
		if (dateType::isLeapYear(y))
			daysInMonth = 29;
		else
			daysInMonth = 28;
		break;

	case 3:
		month = "MARCH";
		daysInMonth = 31;
		break;

	case 4:
		month = "APRIL";
		daysInMonth = 30;
		break;

	case 5:
		month = "MAY";
		daysInMonth = 31;
		break;

	case 6:
		month = "JUNE";
		daysInMonth = 30;
		break;

	case 7:
		month = "JULY";
		daysInMonth = 31;
		break;

	case 8:
		month = "AUGUST";
		daysInMonth = 31;
		break;

	case 9:
		month = "SEPTEMBER";
		daysInMonth = 30;
		break;

	case 10:
		month = "OCTOBER";
		daysInMonth = 31;
		break;

	case 11:
		month = "NOVEMBER";
		daysInMonth = 30;
		break;

	case 12:
		month = "DECEMBER";
		daysInMonth = 31;
		break;

	default:
		break;
	}

	// two dimensional array to print calendar dates accroding to first day of month 
	int calendar[5][7];
	int row;
	int col;


	if (d == "Sunday")


		for (int counter = 1; counter <= daysInMonth; )
		{
			for (row = 0; row < 5; row++)
				for (col = 0; col <= 6; col++)
				{
					calendar[row][col] = counter;
					counter++;
				}
		}
	else if (d == "Monday")
		for (int counter = 0; counter <= daysInMonth; )
		{
			for (row = 0; row < 5; row++)
				for (col = 0; col <= 6; col++)
				{
					calendar[row][col] = counter;
					counter++;
				}
		}
	else if (d == "Tuesday")
	{
		int r = 0;
		int i = 1;
		calendar[r][0] = 0;
		calendar[r][1] = 0;
		for (col = 2; col <= 6; col++)
		{
			calendar[r][col] = i;
			i++;
		}
		for (int counter = i; counter <= daysInMonth; )
		{
			for (row = 1; row < 5; row++)
				for (col = 0; col <= 6; col++)
				{
					calendar[row][col] = counter;
					counter++;
				}
		}
	}

	else if (d == "Wednesday")
	{
		int r = 0;
		int i = 1;

		calendar[r][0] = 0;
		calendar[r][1] = 0;
		calendar[r][2] = 0;
		
		for (col = 3; col <= 6; col++)
		{
			calendar[r][col] = i;
			i++;
		}
		for (int counter = i; counter <= daysInMonth; )
		{
			for (row = 1; row < 5; row++)
				for (col = 0; col <= 6; col++)
				{
					calendar[row][col] = counter;
					counter++;
				}
		}

	}

	else if (d == "Thursday")
	{
		int r = 0;
		int i = 1;

		calendar[r][0] = 0;
		calendar[r][1] = 0;
		calendar[r][2] = 0;
		calendar[r][3] = 0;
		for (col = 4; col <= 6; col++)
		{
			calendar[r][col] = i;
			i++;
		}
		for (int counter = i; counter <= daysInMonth; )
		{
			for (row = 1; row < 5; row++)
				for (col = 0; col <= 6; col++)
				{
					calendar[row][col] = counter;
					counter++;
				}
		}

	}

	else if (d == "Friday")
	{
		int r = 0;
		int i = 1;

		calendar[r][0] = 0;
		calendar[r][1] = 0;
		calendar[r][2] = 0;
		calendar[r][3] = 0;
		calendar[r][4] = 0;
		for (col = 5; col <= 6; col++)
		{
			calendar[r][col] = i;
			i++;
		}
		for (int counter = i; counter <= daysInMonth; )
		{
			for (row = 1; row < 5; row++)
				for (col = 0; col <= 6; col++)
				{
					calendar[row][col] = counter;
					counter++;
				}
		}

	}

	else if (d == "Saturday")
	{
		int r = 0;
		int i = 1;

		calendar[r][0] = 0;
		calendar[r][1] = 0; 
		calendar[r][2] = 0;
		calendar[r][3] = 0; 
		calendar[r][4] = 0;
		calendar[r][5] = 0;
		for (col = 6; col <= 6; col++)
		{
			calendar[r][col] = i;
			i++;
		}
		for (int counter = i; counter <= daysInMonth; )
		{
			for (row = 1; row < 5; row++)
				for (col = 0; col <= 6; col++)
				{
					calendar[row][col] = counter;
					counter++;
				}
		}

	}

	// Calendar output 			


	cout << month << " " << y << endl;
	cout << setw(6) << "Sun " << setw(6) << "Mon " << setw(6) << "Tue " << setw(6) << "Wed " << setw(6) << "Thu " << setw(6) << "Fri " << setw(6) << "Sat" << endl;
	for (row = 0; row < 5; row++)
	{
		for (col = 0; col <= 6; col++)
		{
			if (calendar[row][col] == 0 || calendar[row][col] > daysInMonth)
				cout << setw(6) << "   ";
			else
			cout << setw(5) << calendar[row][col] << " ";
		}
		cout << endl;
	}



}
// +++++++++++ Constructors ++++++++++++++ //
calendarType::calendarType()
{
	dDay = 1;
	dMonth = 1;
	dYear = 1;
}

calendarType::calendarType(int m, int d, int y):
	dateType(m, d, y)
{
	
}



