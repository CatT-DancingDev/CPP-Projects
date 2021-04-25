// Author:			Catherine Trujillo
// Course/Section:	CSC 129-470
// Date:			09/20/2020
//					10/04/2020 - Program amended to include new components as provided in the assignment instructions.
//					11/01/2020 - Program amended to address compliant code requirements AND corrections from prior grading submission 
//					11/08/2020 - Program amended to add requirements from option 1 in updated assignment, as well as bonus functions
// 
// Program:			Compliant Password Derivation
// 
// Description:		This program reads password input from a local file, and determines the shortest possible passcode using a directed graph, and 
//					counting directed edges to determine the position of each digit. Shortest possible implies that only digits in the file are used,
//					and each digit is only used once. Program has been updated to add the following security measures: 
//							- Use .at(pos) rather than [pos] for all std::strings and 1-dimensional std::arrays.
//							- I did not use string::iterator in original version, nor updated version.
//							- Added the following functions:
//									bool isPasswordOK(std::string password);
//									bool meetsCharTypeRequirements(std::string password);
//									bool isCodeOK(std::string, int length);
//							- Made corrections from prior submission Assignment #3
//
// Solution:		The shortest possible password of unknown length is 73162890.
//====================================================================================================================================================//				
#include <iostream>
#include <fstream>
#include <string>
#include <array>

// FUNCTION PROTOTYPES
bool isPasswordOK(std::string password);
bool meetsCharTypeRequirements(std::string password);
bool isCodeOK(std::string, int length);
bool codeInPasscode(std::string passcode, std::string code);  // BONUS FUNCTION

// MAIN FUNCTION 
int main() {

//+++++++++++ VARAIBLE AND CONSTANT DECLARATIONS ++++++++++++++++++++++++++++++//
	const int SIZE = 10;	    // Size of digits 0-9
	const int MAXCODELENGTH = 3;// Size of input code returned from getline()

	std::string str = "";		// String to read input from file
	int edgeCount = 0;

	int rightDigit = 0;			// Stores 3rd digit from each input
	int midDigit = 0;			// Stores 2nd digit
	int leftDigit = 0;			// Stores 1st digit

	int passwordLength = 0;		// Used to track the length of the shortest possible password		

	std::ifstream file;			// File read variable
	std::ofstream outFile;		// File writer variable
	
	std::string password = "";  // Password to enter the file read
	bool passwordOK = false;	// If password meets requirements, assign true
	int numTries = 0;			// Track number of authentication attempts
	int triesRemaining = 0;		// Track number of attempts remaining
	const int TRIESALLOWED = 3;


// ++++++++++++++++++++ DECLARE AND INITIALIZE ARRAY DEFAULT VALUES ++++++++++++++++++++++++++++ //

	std::array<bool, SIZE> possibleDigits;			// Digits that show up in file will be marked true
	std::array<int, SIZE> finalPassword;			// Stores digits of final password
	std::array<std::array<int, SIZE>, SIZE> edges;	// 2-d array of directed edges for all digits 0-9
		
	// Initialize all adjacency matrix locations to zero
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			edges[i][j] = 0;

	// Initialize all possibleDigits to false
	for (int i = 0; i < SIZE; ++i)
		possibleDigits.at(i) = false;
	
	// Initialize finalPassword to all 0
	for (int i = 0; i < SIZE; ++i)
		finalPassword.at(i) = 0;

// ++++++++++++++++  CHECK USER PASSWORD TO ACCESS DECODER ++++++++++++++++++++++//

	// Welcome message
	std::cout << "Welcome to the password decoder app!" << std::endl;

	// Ask for password until valid password has been entered
	while (passwordOK == false) {
		std::cout << "\nTo gain access to the decoder please enter your access code. \n" <<
			"    Access code must: \n" <<
			"        - be 18-20 characters long.\n" <<
			"        - include upper and lowercase letters, numbers, and symbols." << std::endl;

		std::cin >> password;
		
		// If password accepted, proceed to read file, else return to top of loop. Alert user when either branch is taken.
		if (isPasswordOK(password)) {
			std::cout << "\nAccess Code Validated. Proceeding with password decoder.\n" << std::endl;
			passwordOK = true;
		}
		else {
			if (numTries == 2) {
				std::cout << "Maximum attempts reached. Exiting program with code 3." << std::endl;
				system("pause");
				return 3;
			}
			else {
				++numTries;
				triesRemaining = TRIESALLOWED - numTries;
				std::cout << "Please try again. " << triesRemaining << " attempts remaining." <<  std::endl;
			}
		}
	}

	//++++++++++++++++++ READ AND PROCESS FILE DATA +++++++++++++++++++++++++++++//

	// Open input file
	file.open("p079_keylog.txt");

	if (!file)		// check the file opened ok 
	{
		std::cout << "Error opening file for reading. Exiting with return value 1. \n";
		system("pause");
		return 1;   // exit program with 1 to indicate read error
	}

	// Read input from file and store in appropriate arrays
	while (!file.eof())
	{
		// read lines one-by-one until empty line
		getline(file, str);  // read the line from file
		if (file.fail())    // if failbit present, discontinue read.
			break;
		
		// Check if code input meets requirements as defined in isCodeOK(std::string, int).
		if (!isCodeOK(str, MAXCODELENGTH)) {
			std::cout << "Error - Exiting with return value 2." << std::endl;
			system("pause");
			return 2;   // Exit with 2 to indicate codeAttempt error
		}

		// Convert ASCII char to int. Char digits '0' - '9' begin at decimal value 48. 
		// Subtracting char '0' is the same as subtracting int 48, and will return the correct decimal value.
		rightDigit = (str.at(2) - '0');
		midDigit = (str.at(1) - '0');
		leftDigit = (str.at(0) - '0');
 
		// The rightmost digit will have a directed edge to each of the two numbers preceding it. 
		// The mid digit will have one directed edge to the number preceeding it.
		// The leftmost digit will have no directed edges, as no numbers precede it. 
		edges[rightDigit][midDigit] = 1;
		edges[midDigit][leftDigit] = 1;
		edges[rightDigit][leftDigit] = 1;

		// Mark possible digits - if the digit is present in the input line, and not yet marked true, mark it true.
		for (int i = 0; i < str.length(); ++i)
			if (possibleDigits.at(str.at(i) - '0') == false)
				possibleDigits.at(str.at(i) - '0') = true;
	}
	file.close();

	// +++++++++++++++ DETERMINE FINAL PASSWORD +++++++++++++++++++++++//

	// Count directed edges for each digit 0 - 9
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			if (edges[i][j] == 1)
				edgeCount++;
		}

		// An edgecount of 0 means either: 1) digit is a possible first in sequence or 2) not in the sequence at all. 
		// If said digit is false in the possibleDigits list, continue to next digit
		if (edgeCount == 0) {
			if (possibleDigits.at(i) == false)
				continue;
		}

		// If current digit is true in possibleDigits list, assign it to index corresponding with its edgeCount in finalPassword array.
		finalPassword.at(edgeCount) = i;
		
		// Update password length
		passwordLength++;
		
		// Reset edgeCount
		edgeCount = 0;
	}

	//+++++++++++++++++ OUTPUT RESULTS +++++++++++++++++++++++++++//

	// Print Shortest Possible Password
	std::cout << "The shortest possible password of unknown length is: ";
	for (int i = 0; i < passwordLength; ++i)
	std::cout << finalPassword.at(i);
	std::cout << std::endl;


	//+++++++++++++++++++++ BONUS EXTRA CREDIT VALIDATE USER INPUT CODE ATTEMPT AND ADD TO FILE +++++++++++//

	std::string codeAttempt = "";		// Assigned from user input
	std::string passCode = "";			// String conversion of finalPassword
	bool valid = false;

	// Convert finalPassword to string
	for (int i = 0; i < passwordLength; ++i) {
		std::string temp = std::to_string(finalPassword.at(i));
		passCode.append(temp);	
	}
	// Ask for valid input of codeAttempt
	while (!valid) {
		std::cout << "Please enter any 3 digit from your password in the correct order" << std::endl;
		std::cin >> codeAttempt;

		// Check if code meets criteria
		if (isCodeOK(codeAttempt, MAXCODELENGTH) == true) {
			valid = true;		// Exit loop
		}
		else {
			codeAttempt = "";	// Reset codeAttempt
		}
	}

	// If validated input code is in the passcode, add the code attempt to the file 
	if (codeInPasscode(passCode, codeAttempt) == true) {

		std::string  fileName = "p079_keylog.txt";

		// Open output file
		outFile.open(fileName, std::ios_base::app);

		if (!outFile || outFile.fail())	{		// check the file opened ok 
			std::cout << "Error opening file for writing. Exiting with return value 1. \n";
			system("pause");
			return 1;			// exit program with 1 to indicate file opening error
		}

		// Write code to file
			outFile << codeAttempt << "\n";
			std::cout << "File append successful" << std::endl;
		
		// Close file
		outFile.flush();
		outFile.close();
	}
	system("pause");
	return 0;
} // END MAIN()

//+++++++++++++++++++++++++++++++++++++++ FUNCTION DEFINITIONS +++++++++++++++++++++++++++++++++++++++++++++++++//


//==============================================================================================================//
// Function:		isPasswordOK(std::string password)
// Return Type:		bool
// Params:			password   ->  string variable to store user input authorization code 
// Purpose:			Asks user for authorization code. Determine if code meets the following requirements:
//							- Between 18-20 characters
//							- Includes numbers, letters, and symbols
//							- Includes upper and lower case letters
// Calls:			meetsCharTypeRequirements(std::string)
// Return:			If all requirements are met, return true; else return false
//=============================================================================================================//
bool isPasswordOK(std::string password) {

	//  Check if password is 18-20 chars in length and meets all requirements
	if (password.length() >= 18 && password.length()  <= 20) {
		if (meetsCharTypeRequirements(password)) {
			return true;		// Both length and charType requirements have been met
		} else {
			return false;       // Length requirement met, charType Requirement not met
		}
	} else {
		std::cout << "\nInput code not between 18-20 characters in length." << std::endl;
		return false;			// Length requirement not met
	}
} // end isPasswordOk(std::string)

//==============================================================================================================//
// Function:		meetsCharTypeRequirements(std::string password)
// Return Type:		bool
// Params:			password   ->  string variable to store user input authorization code 
// Purpose:			Checks if password includes numbers, letters, and symbols
// Return:			If password contains digits, alphabetic characters and symbols, return true; else return false
//=============================================================================================================//
bool meetsCharTypeRequirements(std::string password) {

	// Password Requirement Trackers
	bool hasDigit = false;		
	bool hasSymbol = false;
	bool hasUpper = false;
	bool hasLower = false;
	
	// Process string 
	char currentChar = ' ';

	for (int i = 0; i < password.length(); ++i) {

		// get current char
		currentChar = char(password.at(i));

		// Check if char is digit
		if (isdigit(currentChar)) {
			hasDigit = true;
		}
		// Check if char is symbol
		else if (ispunct(currentChar)) {
			hasSymbol = true;
		}
		// Check if char is lowercase letter using ASCII char to dec value
		else if (currentChar >= 97 && currentChar <= 122 ) {
			hasLower = true;
		} 
		// Check if char is uppercase letter using ASCII char to dec value
		else if (currentChar >= 65 && currentChar <= 90) {
			hasUpper = true;
		}
		// Contains invalid characters
		else {
			std::cout << "\nInput code contains invalid charcters or spaces." << std::endl;
			return false;
		}
		// If all requirements met, return true
		if (hasDigit == true && hasUpper == true && hasLower == true && hasSymbol == true) {
			return true;
		}
	} // end for-loop

	// If string has been processed and one or more requirements not met, alert and advise user; return false
	std::cout << "\nInput code does not meet the following requirements:" << std::endl;

	if (hasDigit == false)
		std::cout << "    - Does not contain a number" << std::endl;
	if (hasUpper == false)
		std::cout << "    - Does not contain uppercase letter" << std::endl;
	if (hasLower == false)
		std::cout << "    - Does not contain lowercase letter" << std::endl;
	if (hasSymbol == false)
		std::cout << "    - Does not contain a symbol" << std::endl;
	return false;	
}//END meetsCharTypeRequirements(std::string password)

//==============================================================================================================//
// Function:		isCodeOK(std::string str, int length)
// Return Type:		bool
//
// Params:			std::string str	->  string to be checked
//					int length		->  required length to pass check
//					std::array<int, 100> &array  ->  array to check for duplicates
//
// Purpose:			Checks if a string is of the desired length, whether it is all digits, and whether it has 
//					already been checked.
//
// Return:			If code contains only digits, is equal to the required length, and not a duplicate, return  
//					true; else return false.
//=============================================================================================================//
bool isCodeOK(std::string str, int length) {

	char char1;
	char char2;
	char char3;


	// Check str length against int length parameter
	if (str.length() != length) {
		std::cout << "Incorrect length of input line." << std::endl;
		return false;
	}
	// Check if str is all digits
	for (int i = 0; i < str.length(); ++i) {
		if (!isdigit(str.at(i))) {
			std::cout << "Non-numeric character detected." << std::endl;
			return false;
		}
	}
	// Check for duplicates
	char1 = str.at(0);
	char2 = str.at(1);
	char3 = str.at(2);

	if (char1 == char2 || char1 == char3 || char2 == char3) {
		std::cout << "Duplicate digits detected." << std::endl;
		return false;
	}
	return true;	
}
//==============================================================================================================//
// Function:		 codeInPasscode(std::string passcode, std::string code)
// Return Type:		bool
//
// Params:			std::string passcode	-> check if code in passcode
//					std::string code		-> check if code in passcode
//
// Purpose:			Checks to see if a smaller code is in the larger code in correct order
//
// Return:			If code is in the correct order in passcode, return true; else return false.
//=============================================================================================================//			
bool codeInPasscode(std::string passcode, std::string code) {

	bool firstDigitInPasscode = false;		// True when first digit in code matches a digit in passcode 
	bool secondDigitInPasscode = false;		//	^^ Same, but for second digit in code
	bool thirdDigitInPasscode = false;		//  ^^ Same, but for third digit in code

	int codeIndex = 0;
	int passcodeIndex = 0;

	// Check if each digit from code is in the correct order in passcode
	while (passcodeIndex < passcode.length() && codeIndex < code.length()) {
		
		// Process each digit of passcode. 
		if (code.at(codeIndex) == passcode.at(passcodeIndex)) {

			// If the current digit from code matches the current digit from passcode, validate the corresponding bool variable, and increment codeIndex 
			switch (codeIndex) {
			case 0:
				firstDigitInPasscode = true;
				std::cout << "First digit in code" << std::endl;
				break;
			case 1:
				secondDigitInPasscode = true;
				std::cout << "second digit in code" << std::endl;
				break;
			case 2: 
				thirdDigitInPasscode = true;
				std::cout << "Third digit in code" << std::endl;
				break;
			}
			++codeIndex;	// only increment codeIndex if match has been found
		}
		++passcodeIndex;	// increment passcodeIndex after every comparison
	}
	
	// If all digits are in passcode, return true, else false 
	if (firstDigitInPasscode == true && secondDigitInPasscode == true && thirdDigitInPasscode == true){
		std::cout << "Valid password attempt. Your code is in the passcode." << std::endl;
		return true;
	} else {
		std::cout << "Invalid password attempt." << std::endl;
		return false;
	}
}// codeInPasscode(std::string passcode, std::string code)