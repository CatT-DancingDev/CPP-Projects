//========================================================================//
// Catherine Trujillo
// CSC 161-C00
// 9/18/19
//
// Program 11
// Description: Program to define and implement classes for dateType, calendarType, extDateType, and dayType
//=============================================================================//
#include "calendarType.h"
#include "dayType.h"
#include "extDateType.h"
#include "dateType.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{

	calendarType calendar1(9, 9, 2019);
	dateType date1;
	extDateType ext1;

	int month;
	int day;
	int year;
	int daysAdded;
	string firstOfMonth;
	



	//Operations on Calendar1//
	cout << "The date of Calendar 1 is ";
	calendar1.printDate();
	cout << endl << endl;

	cout << "What day does the first of this month fall on? Please capitalize first letter of day." << endl;
	cin >> firstOfMonth;
	calendar1.printMonthlycalendar(firstOfMonth, 9, 9);

	if (calendar1.isLeapYear())
		cout << calendar1.getYear() << " is a leap year." << endl;
	else
		cout << calendar1.getYear() << " is not a leap year." << endl;
	cout << "***********************" << endl << endl;
	


	//Operations on date1
		//set date by user input
	cout << "Please enter the numerical month of Date 1 (1 - 12)" << endl;
	cin >> month;

	cout << "Please enter the date" << endl;
	cin >> day;

	cout << "Please enter the year" << endl;
	cin >> year;

	date1.setMonth(month);
	date1.setDay(day);
	date1.setYear(year);

	//Print info 
	cout << "Date: "; 
	date1.printDate();
	cout << endl << "Days passed: " << date1.daysPassed() << endl;
	cout << "Days remaining: " << date1.daysRemaining() << endl;
	cout << "There are " << date1.daysInMonth() << " days this month." << endl;

	if (date1.isLeapYear())
		cout << date1.getYear() << " is a leap year." << endl;
	else
		cout << date1.getYear() << " is not a leap year." << endl;
		cout << "***********************" << endl << endl;

	// Change date of date1

	cout << "How many days would you like to add to the current date?" << endl;
	cin >> daysAdded;
	date1.setNewDate(daysAdded);

	//Print Info
	cout << "Date: ";
	date1.printDate();
	cout << endl << "Days passed: " << date1.daysPassed() << endl;
	cout << "Days remaining: " << date1.daysRemaining() << endl;
	cout << "There are " << date1.daysInMonth() << " days this month." << endl;

	if (date1.isLeapYear())
		cout << date1.getYear() << " is a leap year." << endl;
	else
		cout << date1.getYear() << " is not a leap year." << endl;
		cout << "***********************" << endl << endl;

	//Operations on ext1

	ext1.setDate(5, 16, 1984);

	cout << "The date of ext1 is ";
	ext1.printDateNumeric();
	cout << endl;

	cout << "It can also be written as ";
	ext1.printDateString();

	cout << "The month and year are ";
	ext1.printMonthYearString();

	cout << "The numeric month " << ext1.getExtMonth() << " is called " << ext1.translateMonth() << endl;


	



	system("pause");
	return 0;

}
