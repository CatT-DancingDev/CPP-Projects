//========================================================================//
// Catherine Trujillo
// CSC 161-C00
// 9/18/19
//
// Program 11
// Description: Program to define and implement classes for dateType, calendarType, extDateType, and dayType
//=============================================================================//
#pragma once
#include "dateType.h"
#include <string>
#include <iostream>

using namespace std;

class extDateType : public dateType
{
public: 
	int getExtDay() const;
	// Function to return the day
	// Postcondition: value of dDay

	int getExtMonth() const;
	// Function to return the month
	// Postcondition: value of dmonth
	
	int getExtYear() const;
	// Function to return the year
	// Postcondition: value of dYear

	string translateMonth() const;
	// Function to return the string form of dMonth
	// Postcondition: If dMonth equals 1 return January
	//				  If dMonth equals 2 return Februrary
	//				  If dMonth equals 3 return March
	//				  If dMOnth equals 4 return April
	//                If dMonth equals 5 return May
	//                If dMonth equals 6 return June
	//                If dMonth equals 7 return July
	//                If dMonth equals 8 return August
	//                If dMonth equals 9 return September
	//                If dMonth equals 10 return October
	//                If dMonth equals 11 return November
	//                If dMonth equals 12 return December 

	void printDateNumeric() const;
	// Function to output the properties of extDate in numeric form
	// Postcondition: Output to console the properties of date in the form xx-xx-xxxx

	void printDateString()const;
	// Function to output the properties of extDate in string form
	// Postcondition: Output to console the properties of extDate in the form Januray 1, 1900
	
	void printMonthYearString() const;
	// Function to output only the Month and Year of extDate
	// Postcondition: Output to console the month and year in string format
	
	extDateType();
	// Default Constructor

	extDateType(int month, int day, int year);
	// Constructor with Parameters
	// Postcondition: The member variables are set according to the parameters


	string monthString;

	friend class calendarType;
};
