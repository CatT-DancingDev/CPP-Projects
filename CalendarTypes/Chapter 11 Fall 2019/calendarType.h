//========================================================================//
// Catherine Trujillo
// CSC 161-C00
// 9/18/19
//
// Program 11
// Description: Program to define and implement classes for dateType, calendarType, extDateType, and dayType
//=============================================================================//
#pragma once
#include "dayType.h"
#include "extDateType.h"
#include "dateType.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class calendarType: public dateType

{

public:

	int getYear() const;
	// Function to get current year
	// Postcondition: returns value of year

	void printMonthlycalendar(string d, int m, int y) const;
	// Function to print calendar for given month based on the day that the first of the month lands on, a given month, and a given year
	// Postcondition: Outputs formatted calendar with month, year, and correct number of days in month


	calendarType();
	// default constructor
	calendarType(int m, int d, int y);
	// Constructor with paramters
	// Sets members dDay, dMonth and dYear according to paramters of parent class dateType
	

	dayType firstDayOfMonth;
	extDateType date;


};


