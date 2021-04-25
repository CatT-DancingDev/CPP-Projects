//==============================================================================================//
// Name:		Cat Truillo
// Date:		10/21/2020
// Course:		CSC 129
// Section:		240
// Project:		Sum of Too Big Numbers
//
// Description:	Learn to work with c-strings, aka character arrays. Use character arrays to add 
//				together numbers that are too large to store as an int. User will input numbers 
//				that are too large to store as int. The program will read the input as a chracter 
//				array. The job of the secure coder is to ensure that only input of correct size and 
//				data-type are accepted into the program, thereby mitigating common input 
//				vulnerability found in i/o intefaces, namely buffer overflow, index out-of-bounds,
//				and integer overflow. The program will then reverse the order of character arrays,
//				convert the characters to integers, then add them together and reverse the order of
//				the int array to get the correct answer.
//================================================================================================//
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <array>

//+++++++++++++++++ FUNCTION PROTOTYPES ++++++++++++++++++++++//

void setString(char *string, int size);
void reverseString(char *string);
void printString(char *string);
void printSumStrings(char *string1, char *string2, int *sum);

//++++++++++++++++ MAIN FUNCTION +++++++++++++++++++++++++++++//

int main() {

	//+++++++ DATA DECLARATION ++++++++++++//
	const int SIZE = 21;

	char str1[SIZE];
	char str2[SIZE];
	int sum[SIZE - 1];

	//+++++++ PROCESS +++++++++++++++++++++//

	setString(str1, SIZE);						// Get and confirm validated C-String from user
	std::cout << "First number: ";
	printString(str1);

	reverseString(str1);						// Reverse and confirm the first C-string
	std::cout << "String 1 in reverse: ";
	printString(str1);

	setString(str2, SIZE);				       // Get and confirm validated C-String from user
	std::cout << "Second number: ";
	printString(str2);

	reverseString(str2);					   // Reverse and confirm the first C-string
	std::cout << "String 2 in reverse: ";
	printString(str2);

	if (strlen(str1) < strlen(str2)) {		  // Place larger C-string in first string postion 
		std::swap(str1, str2);
	}

	int i = strlen(str2);					 // Replace the difference in digits with 0
	while (i < strlen(str1)) {
		str2[i] = '0';
		i++;
	}

	// +++++++ RESULTS +++++++++++++++++//

	std::cout << "The sum of String 1 and String 2 is: ";	// Calculate and output the sum of String 1 and String 2
	printSumStrings(str1, str2, sum);
	std::cout << std::endl;

	system("pause");
	return 0;
}// END MAIN

//++++++++++++++++++++ FUNCTION DEFINITIONS +++++++++++++++++++++++++++++++++++++//
//===============================================================================//
// Function:	setString(char *string, int size)
// Return:		void
// Params:		char *string   ->  Referenece to an already existing string
//				int size       ->  The maximum allowed size of the input string
//
// Purpose:		Reads and validates user input to populate an existing C-String with
//				digits only, not to exceed size size.
//
// Pre:			C-string of size size exists, either populated or unpopulated.
//
// Post:		C-string is cleared and re-populated with the validated user input
//================================================================================//
void setString(char *str, int size) {
	bool valid = false;		// Set to true if validation requirements have been met
	int ch;



	// Ask user for correct input. If input is invalid give an appropriate prompt, 
	// and return to top of loop
	while (!valid) {

		int i = 0;
		int chars_read = 0;

		// Ensure string is set to null
		for (int i = 0; i < strlen(str); i++) {
			str[i] = '\0';
		}

		// Ask for input
		std::cout << "Please enter a number with 20 or fewer digits." << std::endl;

		// Use getChar to store a maximum of 21 chars before continuing. 
		while (((ch = getchar()) != '\n') && ch != EOF) {
			if (i < size - 1) {
				str[i++] = (unsigned char)ch;
			}
			chars_read++;
		}
		// If the number of chars read exceeds 20, loop back to top.
		if (chars_read > i) {
			valid = false;
			std::cout << "More than 20 characters detected. ";
			continue;
		}
		// Set final index to null char 
		str[i] = '\0';

		// Assign loop condition to true
		valid = true;

		// If there are non-numeric characters, loop back to top
		for (int i = 0; i < strlen(str); i++) {
			if (!isdigit(str[i])) {
				valid = false;
				std::cout << "Non-numeric character detected. ";
				break;
			}
		}
	}
}
//===============================================================================//
// Function:	reverseString(char *string)
// Return:		void
// Params:		char *string   ->  Referenece to an already existing string
//				
// Purpose:		Reverses the order of a C-String
//
// Pre:			C-string exists either populated or unpopulated.
//
// Post:		Elements in C-String have been stored in reverse order
//================================================================================//
void reverseString(char *string) {
	int i = 0;                          // Counter from beginning of string
	int j = strlen(string) - 1;         // Counter from end of string
	int temp = 0;                       // Temporarily stores value during swap


	// Swap the array characters from the outside-in
	while (i < j) {
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
		i++;
		j--;
	}
}
//===============================================================================//
// Function:	printString(char *string);
// Return:		void
// Params:		char *string   ->  Referenece to an already existing string
//
// Purpose:		Prints the elements of a C-string to the console log				
//
// Pre:			C-string exists, either populated or unpopulated.
//
// Post:		C-string is unchanged. Elements have been printed to console log
//================================================================================//
void printString(char *string) {
	for (int i = 0; i < strlen(string); i++) {
		std::cout << string[i];
	}
	std::cout << std::endl;
}

//===============================================================================//
// Function:	printSumStrings(char *string1, char *string2)
// Return:		void
// Params:		char *string1   ->  Reference to an already existing string
//				char *string2   ->  Reference to an already existing string
//
// Purpose:		Prints the sum of two large numbers stored as C-Strings.				
//
// Pre:			Two C-string exist, either populated or unpopulated. An int array
//				exists, either populated or un-populated.
//
// Post:		Both C-strings remain unchanged. Int array sum is populated with
//				the digits of the resulting sum of the two C-strings. The sum is 
//				then printed from the array in reverse, so that the highest exponents 
//				are in the furthest left position, and the ones place is furthest 
//				right.
//================================================================================//
void printSumStrings(char *string1, char *string2, int *sum) {

	int dig1;		// Holds conversion from char to int
	int dig2;		// Holds conversion from char to int

	int total = 0;
	int carry = 0;

	// Ensure that the int array is set to 0
	for (int i = 0; i < sizeof(sum); i++) {
		sum[i] = 0;
	}

	// Convert each char to int, perform addition, calculate the carry, store the ones place in int array
	for (int i = 0; i < strlen(string1); i++) {
		dig1 = string1[i] - '0';
		dig2 = string2[i] - '0';
		total = dig1 + dig2 + carry;
		carry = total / 10;
		sum[i] = total % 10;
	}

	// If there is a carry after all digits have been processed, add the implied carry amount (carry * 10)
	// to the final index in the int array
	if (carry > 0) {
		carry *= 10;
		sum[strlen(string1) - 1] += carry;
	}

	// Print the int array from back (highest exponent) to front (ones place)
	for (int i = strlen(string1) - 1; i >= 0; i--) {
		std::cout << sum[i];
	}
}





