//========================================================================//
// Catherine Trujillo
// CSC 161-C00
// 9/18/19
//
// Program 11
// Description: Program to define and implement classes for dateType, calendarType, extDateType, and dayType
//=============================================================================//
#pragma once
#include <string>

using namespace std;
class dayType 
{
public:

	void setDay(string d);
	// Function to set the value of day
	// Postcondition: The Value of Day is set according to parameters

	void printDay() const;
	// Function to output the value of day in String Format
	// Postcondition: Ouput to console the value of day

	string getDay() const;
	// Function to return the value of day
	// Postcondition: returns the string value of day
	string getNextDay() const;
	// Function to calculate the next day based on value of Day
	// Postcondition: If day equals Sunday return Monday
	//                If day equals Monday return Tuesday
	//                If day equals Tuesday return Wednesday
	//                If day equals Wednesday return Thursday
	//                If day equals Thursday return Friday
	//                If day equals Friday return Saturday
	//                If day equals Saturday, return Sunday

	string getNextDay(string d) const;

	// Function to calculate the next day based on value of parameter
	// Postcondition: If d equals Sunday return Monday
	//                If d equals Monday return Tuesday
	//                If d equals Tuesday return Wednesday
	//                If d equals Wednesday return Thursday
	//                If d equals Thursday return Friday
	//                If d equals Friday return Saturday
	//                If d equals Saturday, return Sunday

	string getPreviousDay() const;
	// Function to calculate the previous day based on value of Day
	// Postcondition: If day equals Sunday return Saturday
	//                If day equals Monday return Sunday
	//                If day equals Tuesday return Monday
	//                If day equals Wednesday return Tuesday
	//                If day equals Thursday return Wednesday
	//                If day equals Friday return Thursday
	//                If day equals Saturday, return Friday

	string getPreviousDay(string d) const;
	// Function to calculate the previous day based on value of parameter
	// Postcondition: If d equals Sunday return Saturday
	//                If d equals Monday return Sunday
	//                If d equals Tuesday return Monday
	//                If d equals Wednesday return Tuesday
	//                If d equals Thursday return Wednesday
	//                If d equals Friday return Thursday
	//                If d equals Saturday, return Friday

	string dayPlusNoOfDays(int noOfDays) const;
	// Function to calculate the new date based on adding a number of days to current day
	// Postcondition: Returns the value of a day based on adding a current number of days to the current day

	dayType();
	// Default Constructor

	dayType(string d);
	// Constructor with paramters
	// Postcondition: member varaible day is set according to parameter

private:
	string day;
	friend class calendarType;

};
