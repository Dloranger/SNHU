// Project2_Loranger.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Author: Daniel Loranger
// Date: 2025-Apr-14
// 
// Description:  This program is written to fulfill a customer's request for a program that will read in a
// series of courses and their prerequisites, and then output the courses with prerequisites in a pre-defined format.
// In addition to showing single courses, the program will also show the all courses in alphanumerical order when requested.
// 
// The user interface is specified to be a console menu, with a simplified user interface menu in simple text format.
// 
// Special requirements when reading in the initial course list, if a course includes pre-requisites that are not listed
// in the catalog file, the import should abort to prevent invalid listings from being shown.
//
// Example menu structure with invalid menu choice
// Welcome to the course planner.
// 1. Load Data Structure.
// 2. Print Course List.
// 3. Print Course.
// 9. Exit
// What would you like to do ? 8
// 8 is not a valid option. <- response
// 
// Example menu structure with a valid menu choice output
// 1. Load Data Structure.
// 2. Print Course List.
// 3. Print Course.
// 9. Exit
// What would you like to do ? 2
// Here is a sample schedule :
// CSCI100, Introduction to Computer Science
// CSCI101, Introduction to Programming in C++
// CSCI200, Data Structures
// CSCI301, Advanced Programming in C++
// CSCI300, Introduction to Algorithms
// CSCI350, Operating Systems
// CSCI400, Large Software Development
// MATH201, Discrete Mathematics
//
// Example single course search output
// 1. Load Data Structure.
// 2. Print Course List.
// 3. Print Course.
// 9. Exit
// What would you like to do ? 3
// What course do you want to know about ? csci400
// CSCI400, Large Software Development
// Prerequisites : CSCI301, CSCI350
//
// Exit menu text
// 1. Load Data Structure.
// 2. Print Course List.
// 3. Print Course.
// 9. Exit
// What would you like to do ? 9
// Thank you for using the course planner!
// 
// 
// Coding standards are not specified other that following best practices
// CamelCase naming will be used in this project
//



#include <iostream>

#include <string>
/*
* Show the user menu and validate the entry against the available options
*/
int showMenu() {
	//keep the context local for std
	using std::cout;
	using std::getchar;
	using std::cin;
	using std::endl;
	using std::string;

	while (1) { // stay here until a valid option is chosen

		// display the supported list of available options
		cout << "1. Load Data Structure." << endl;
		cout << "2. Print Course List." << endl;
		cout << "3. Print Course." << endl;
		cout << "9. Exit" << endl;
		cout << "What would you like to do ? ";

		// using a simple switch structure to only accept the allowed options
		string userInput;
		cin >> userInput;
		if (userInput.empty()) { cout << "entry was empty" <<endl; }
		else {
			switch (char(userInput[0])) { // only use the first char entered
			case 0x31: //"1. Load Data Structure."
			{
				break;
			}
			case 0x32: //"2. Print Course List."
			{
				break;
			}
			case 0x33: //"3. Print Course."
			{
				break;
			}
			case 0x39: //"9. Exit" 
			{
				// behavior: Close the program with a courteous message
				// Checking: expected output has been checked against the requirements

				cout << "Thank you for using the course planner!" << endl;
				exit(0);
				break;
			}
			default:
			{
				// user entered something invalid
				// behavior: display an error and show the menu again
				cout << userInput << " is not a valid option." << endl << endl;
			}

			}//switch close
		} // not an empty getline()
	} //while loop
}

int main()
{
	showMenu();
}

