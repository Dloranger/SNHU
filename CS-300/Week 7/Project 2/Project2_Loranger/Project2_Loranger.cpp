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

// This program is written in C++

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//#include <stdio.h>  // so we can read command line arguments
using namespace std;


//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

string csvPath;




//define the hash table for importing the courses
//Courses are a maximum of 7 characters long 
const unsigned int DEFAULT_SIZE = INT32_MAX; // default size of the hash table


// define a structure to hold course information
struct Course {
	string courseID; // unique identifier
	string title;
	string preReqList;
};














//============================================================================
// Hash Table class definition
//============================================================================

class HashTable {
private:

	Course course;


	struct Node {
		Course course;
		unsigned int key;
		Node* next;

		// default constructor
		Node() {
			key = UINT_MAX;
			next = nullptr;
		}
		// initialize with a Course
		Node(Course aCourse) : Node() {
			course = aCourse;
		}

		// initialize with a course and a key
		Node(Course aCourse, unsigned int aKey) : Node(aCourse) {
			key = aKey;
		}
	};

	vector<Node> nodes;
	unsigned int tableSize = DEFAULT_SIZE;

	unsigned int hash(Course course);

public:
	HashTable();
	HashTable( int size);
	virtual ~HashTable();
	void Insert(Course course);
	void showCourse(string courseId);
	void PrintAll();
};

/**
 * Destructor
 */
HashTable::~HashTable() {
	// FIXME (2): Implement logic to free storage when class is destroyed

	// erase nodes beginning
	//DL - erase the nodes vector beginning to unload the memory
	nodes.erase(nodes.begin());
}

/**
 * Print all Courses
 */
void HashTable::PrintAll() {
	for (int i = 0; i < tableSize; i++) {
		//   if key not equal to UINT_MAX
		Node cursor = nodes.at(i);
		if (cursor.key != UINT_MAX) {

			// What course do you want to know about ? csci400
			// CSCI400, Large Software Development
			// Prerequisites : CSCI301, CSCI350
			cout << cursor.course.courseID << ", "
				<< cursor.course.title << endl;
			cout << "Prerequisites : " << cursor.course.preReqList << endl;
		}
	}
}

/**
 * Search for the specified courseId
 *
 * @param courseId The course id to search for
 */
void HashTable::showCourse(string courseId) {

}

unsigned int HashTable::hash(Course course) {
	//DL - Use the key and modulo table size to calculate the hash value
	// return key tableSize
	int hash = (std::hash<std::string>{}(course.courseID)) % 100;
	return hash;
}

/**
 * Constructor for specifying size of the table
 * Use to improve efficiency of hashing algorithm
 * by reducing collisions without wasting memory.
 */
HashTable::HashTable(int size) {
	// invoke local tableSize to size with this->
	//DL - update the table size variable to the size passed in
	this->tableSize = size;
	// resize nodes size
	//DL - resize the nodes vector to the size passed in
	nodes.resize(size);
}

/**
 * Insert a course
 *
 * @param course The course to insert
 */
void HashTable::Insert(Course course) {

	string keyStr = course.courseID;
	int key[] = { keyStr[0], keyStr[1], keyStr[2], keyStr[3], keyStr[4], keyStr[5], keyStr[6]};

	int key2 = 0;
	for (int i = 0; i < keyStr.length(); i++) {
		key2 = (key2 <<8) + (key[i]);

		cout << "key2: " << to_string(key2) << endl;
	} 

	int target = key2;
	
//unsigned int key = std::hash(course.courseID.c_str,10);

	// retrieve node using key
	//DL - Search for the node using the key, using UINT_MAX to indicate no entry found
	//DL if there is a match to UINT_MAX, the node is empty, so we can reassign the node
	if (nodes.at(target).key == INT_MAX) {
		// if no entry found for the key
		// assign this node to the key position
		//DL - create a new node based on the course input and the key we just created
		nodes.at(target) = Node(course, target);

	}
	else {
		//DL - this is a collision, so we need to find the next open node in the list
		//DL - start at the default key position
		Node* cursor = &nodes.at(target);

		//DL - loop through the list until we find the end
		//DL - scan the list to find the last position
		while (cursor->next != NULL) {
			cursor = cursor->next;
		}
		//DL - We found the end of the list, so add the new node to the end
		//DL - the new node automatically sets the next pointer to null
		cursor->next = new Node(course, target);
	}
}


//forward declare the function to load the course data
void loadFromFile(string loadFile, HashTable* courseTable);


/*
* Show the user menu and validate the entry against the available options
*/
int showMenu(HashTable* courseTable) {
	//keep the context local for std


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
		if (userInput.empty()) { cout << "entry was empty" << endl; }
		else {
			switch (char(userInput[0])) { // only use the first char entered

			case 0x31: //"1. Load Data Structure."
			{
				loadFromFile(csvPath, courseTable);
				break;
			}
			case 0x32: //"2. Print Course List."
			{
				courseTable->PrintAll();
				break;
			}
			case 0x33: //"3. Print Course."
			{
				cout << "What course do you want to know about ? ";
				cin >> userInput;

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


/*
*  Read in the csv data from file
*/
void loadFromFile(string loadFile, HashTable* courseTable) {
	// to fullfill the requirement of reading in the course list from a file
	// a pre-req must always be found in the file, 
	// so first must generate a list of the courses contained in the list to check against

	string fileText;
	ifstream MyReadFile(loadFile);
	// empty array 
	vector<string> courseIds;
	while (getline(MyReadFile, fileText)) {
		//extract the course ID from the file
		string courseID = fileText.substr(0, fileText.find(','));

		// check if the course ID is not already in the list
		int i = 0;
		for (i = 0; i < courseIds.size(); i++) {
			if (courseID == courseIds[i]) {
				// if the course ID is already in the list, skip it
				break;
			}
		}
		//add the course ID to the list if necessary
		if (i == courseIds.size()) {
			// if the course ID is not in the list, add it
			courseIds.push_back(courseID);
		}
		else {
			// if the course ID is already in the list, skip it
			continue;
		}

	}
	MyReadFile.close();

	//debugging output to show the list of found course IDs

	/*
	cout << "The following courses were found in the file:" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < courseIds.size(); i++) {
		cout << courseIds[i] << endl;
	}
	*/

	// now we know the total list of included courses so we can start importing
	// the data into the program for use
	ifstream MyReadFile2(loadFile);
	while (getline(MyReadFile2, fileText)) {
		Course newCourse;
		//extract the course ID from the file
		newCourse.courseID = fileText.substr(0, fileText.find(','));
		fileText.erase(0, fileText.find(',') + 1); // remove the course ID from the string
		//extract the title from the file 
		newCourse.title = fileText.substr(0, fileText.find(','));
		fileText.erase(0, fileText.find(',') + 1); // remove the course name from the string


		while (fileText.find(',') != string::npos) {
			//extract the pre-requisite from the file
			string preReq = fileText.substr(0, fileText.find(','));
			fileText.erase(0, fileText.find(',') + 1); // remove the pre-requisite from the string
			//check if the pre-requisite is in the list of courses
			int i = 0;
			for (i = 0; i < courseIds.size();) {
				if (preReq == courseIds[i]) {
					// if the pre-requisite is in the list, add it to the courses list
					newCourse.preReqList += preReq + ", ";
					break;
				}
				//increment the iterator, at the end of the loop, i will be equal to the size of the courseIds vector
				++i;
				// if i is equal to the size of the courseIds vector, it means that the pre-requisite is not in the list
				if ((i == courseIds.size()) && (preReq != "")) {
					cout << "The following course was not found in the list: " << preReq << endl;
					cout << "aborting import of courses " << endl;
					exit(1);
				}
			}



			


			// all course prerequisite items have been checked, if we made it this far they must have all been found.
			// now we can add the course to the hash table


			courseTable->Insert(newCourse); //DL - add the course to the hash table

		}



	}
	MyReadFile2.close();
}


int main(int argc, char* argv[])
{

	// process command line argument (filename)

	switch (argc) {
	case 2:
		csvPath = argv[1];
		break;

	default:
		csvPath = "CS 300 ABCU_Advising_Program_Input.csv";
	}


	// Define a hash table to hold all the courses
	HashTable* courseTable;

	//Course course;
	courseTable = new HashTable(DEFAULT_SIZE);

	showMenu(courseTable);
}

