//========================================================================//
// Catherine Trujillo
// CSC 161-C00
// 9/18/19
//
// Program 11
// Description: Program to define and implement classes for dateType, calendarType, extDateType, and dayType
//=============================================================================//
#pragma once
class dateType
{
public:
	void setDate(int month, int day, int year);
		// Function to set the date.
		// If the date is valid, the member variable dMonth, dDay, and dYear are set according to the parameters.
		// Postcondition: if the date is valid, dMonth = month, dDay = day, dYear = year
	void setMonth(int month);
		// Function to set month
		// If the month is valid, the member variable dMonth is set according to the paramter
		// Post condition if the month is valid, the Member variable dMonth = month

	void setDay(int day);
		// Function to set day
		// If the month is valid, the member variable dDay is set according to the paramter
		// Post condition if the day is valid, the Member variable dDay = day

	void setYear(int year);
		// Function to set year
		// If the year is valid, the member variable dYear is set according to the paramter
		// Post condition if the year is valid, the Member variable dYear = Year

	int getDay() const;
		// Function to return the day.
		// Postcondition: The value of day is returned

	int getMonth() const;
		// Function to return the month.
		// Postcondition: The value of month is returned

	int getYear() const;
		// Function to return the year.
		// Postcondition: The value of year is returned

	void printDate() const;
		// Function to output the date in the form mm-dd-yyyy.

	int daysInMonth() const;
		// Function to return the number of days in the given month
		// Postcondition: returns number of days in given month
		//				  If dMonth == 1, 3, 5, 7, 8, 10, or 12
		//					return 31
		//                Else if dMonth == 4, 6, 9, or 11
		//					return 30
		//				  Else if dMonth == 2 && isLeapYear()
		//					return 29
		//				  Else if dMonth == 2 && not isLeapYear()
		//					return 28

	bool isLeapYear() const;
		// Function to check if dYear is a leap year
		// Postcondition: If dYear is divisible by 4, 100, and 400 or dYear is divisible by 4 and not 100
		//                isLeapYear returns true,
		//				  Else, isLeapYear returns false
	bool isLeapYear(int year) const;
		//Function to check if parameter is defined as leap year
	int daysPassed() const;
		// Function to return the number of days passed in current year
		// Postcondition: returns number of days passed in current year
	int daysRemaining() const;
		// Function to return the number of days remaining in the year
		// Postcondition: if isLeapYear == true, return 366 - daysPassed()
		//                if isLeapYear == false, return 365 - daysPassed()
	void setNewDate(int daysAdded);
		// Function to return the new date based on adding a number of days
		// Postcondition return the new date based on adding a number of days


	
	dateType(int month = 1, int day = 1, int year = 1900);
		// Constructor to set the date
		// The member variables dMonth, dDay, and dYear are set according to the parameters.
		// Post condition: dMonth = month, dDay = day, dYear= year;
		//                 If no values are specified, the default values are used to initialize the member variables.

protected:
	int dMonth;
	int dDay;
	int dYear;
};
