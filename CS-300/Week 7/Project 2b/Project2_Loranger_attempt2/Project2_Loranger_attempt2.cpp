//============================================================================
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
// This program is written in C++
//
//============================================================================


#include <fstream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold course information
struct Course {
	string courseID; // unique identifier
	string title;
	string preRequisits;
};

// Internal structure for tree node
struct Node {
	Course course;
	Node* left;
	Node* right;

	// default constructor
	Node() {
		left = nullptr;
		right = nullptr;
	}

	// initialize with a course
	Node(Course aCourse) :
		Node() {
		course = aCourse;
	}
};

//============================================================================
// Binary Search Tree class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a binary search tree
 */
class BinarySearchTree {

private:
	Node* root;

	void addNode(Node* node, Course course);
	void inOrder(Node* node);
	//void postOrder(Node* node);
	//void preOrder(Node* node);
	void clearNodes(Node*& cur); //reference on pointer
	//Node* removeNode(Node* node, string courseID);

public:
	BinarySearchTree();
	//virtual ~BinarySearchTree();
	void InOrder();
	//void PostOrder();
	//void PreOrder();
	void Insert(Course course);
	//void Remove(string courseID);
	Course Search(string courseID);
};

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
	// FixMe (1): initialize housekeeping variables
	//root is equal to nullptr
	root = nullptr;
}

/**
 * Destructor
 */
 //BinarySearchTree::~BinarySearchTree() {
 //	//FixMe (2)
 //	// recurse from root deleting every node
 //	clearNodes(root);
 //}


 /*
 * DL - Recursion code from
 * DL - https ://stackoverflow.com/questions/32296437/recursively-delete-every-nodes-in-binary-tree
 *
 * DL - This function will delete all nodes in the tree recursively
 * DL - and set the root to null
 */

 //void BinarySearchTree::clearNodes(Node*& cur) //reference on pointer
 //{
 //	if (cur == NULL)
 //	{
 //		return;
 //	}
 //
 //	clearNodes(cur->left);
 //	clearNodes(cur->right);
 //
 //	delete cur;
 //	cur = NULL; //neccessary
 //}
 /**
  * Traverse the tree in order
  */
void BinarySearchTree::InOrder() {
	// FixMe (3a): In order root
	// call inOrder fuction and pass root 
	inOrder(root);
}

/**
 * Traverse the tree in post-order
 */
 //void BinarySearchTree::PostOrder() {
 //	// FixMe (4a): Post order root
 //	// postOrder root
 //	postOrder(root);
 //}

 /**
  * Traverse the tree in pre-order
  */
  //void BinarySearchTree::PreOrder() {
  //	// FixMe (5a): Pre order root
  //	// preOrder root
  //	preOrder(root);
  //}


  /**
   * Add a course to some node (recursive)
   *
   * @param node Current node in tree
   * @param course Course to be added
   */
void BinarySearchTree::addNode(Node* node, Course course) {
	// FIXME (6b) Implement inserting a course into the tree
	// if node is larger then add to left
	if (node->course.courseID > course.courseID) {
		// if no left node
		if (node->left == nullptr) {
			// this node becomes left
			node->left = new Node(course);
		}
		else {// else recurse down the left node
			addNode(node->left, course);
		}
	}


	// else // node is smaller then add to right
	else {
		// // if no right node
		if (node->right == nullptr) {
			node->right = new Node(course);// this node becomes right
		}
		else {//else
			// recurse down the right node
			addNode(node->right, course);
		}
	}
}



/**
 * Insert a course
 */
void BinarySearchTree::Insert(Course course) {
	// FIXME (6a) Implement inserting a course into the tree
	// if root equarl to null ptr
	  // root is equal to new node course
	if (root == nullptr) {
		root = new Node(course);
	}
	// else
	  // add Node root and course
	else {
		addNode(root, course);
	}
}

/**
 * Remove a course
 */
 //void BinarySearchTree::Remove(string courseID) {
 //	// FIXME (7a) Implement removing a course from the tree
 //	// remove node root courseID
 //	removeNode(root, courseID); //remove node root courseID
 //}

 /**
  * Search for a course
  */
Course BinarySearchTree::Search(string courseID) {

	// convert the courseID to upper case, we need to be consistent
	// in the use of cases to ensure searching works under any input 
	// condition in either the course list input or user search
	// request entry format.
	string courseIDUpper = "";
	for (int x = 0; x < courseID.size(); x++)
		courseIDUpper += (toupper(courseID[x]));

	// set current node equal to root
	Node* currentNode = root;
	// keep looping downwards until bottom reached or matching courseID found
	while (currentNode != nullptr) {
		// if match found, return current course
		if (currentNode->course.courseID == courseIDUpper) {
			return currentNode->course;
		}
		// if course is smaller than current node then traverse left
		// else larger so traverse right
		else if (courseIDUpper < currentNode->course.courseID) {
			currentNode = currentNode->left;
		}
		else {
			currentNode = currentNode->right;
		}
	}
	Course course;
	return course;
}



/**
 * Display the course information to the console (std::out)
 *
 * @param course struct containing the course info
 */
void displayCourse(Course course) {
	// What course do you want to know about ? csci400
	// CSCI400, Large Software Development
	// Prerequisites : CSCI301, CSCI350
	cout << course.courseID << ", " << course.title << endl;
	cout << "Prerequisites : " << course.preRequisits << endl;
}


/**
 * Traverse the tree in order
 */
void BinarySearchTree::inOrder(Node* node) {
	// FixMe (3b): Pre order root
	//if node is not equal to null ptr
	if (node != nullptr) {
		//InOrder not left
		inOrder(node->left);
		displayCourse(node->course);
		//InOrder right
		inOrder(node->right);
	}
}
//void BinarySearchTree::postOrder(Node* node) {
//	// FixMe (4b): Pre order root
//	//if node is not equal to null ptr
//	if (node != nullptr) {
//		//postOrder left
//		//postOrder right
//		postOrder(node->left);
//		postOrder(node->right);
//
//		//output courseID, title, amount, fund
//		std::cout << node->course.courseID << ", " << node->course.title << ", " << node->course.amount << ", " << node->course.fund << endl;
//	}
//}

//void BinarySearchTree::preOrder(Node* node) {
//	// FixMe (5b): Pre order root
//	//if node is not equal to null ptr
//	if (node != nullptr) {
//		//output courseID, title, amount, fund
//		std::cout << node->course.courseID << ", " << node->course.title << ", " << node->course.amount << ", " << node->course.fund << endl;
//		//postOrder left
//		postOrder(node->left);
//		//postOrder right      
//		postOrder(node->right);
//	}
//}

/**
 * Remove a course from some node (recursive)
 */
 //Node* BinarySearchTree::removeNode(Node* node, string courseID) {
 //	// parent node has no children
 //	if (node == nullptr) {
 //		return node;
 //	}
 //	// Recurse down the left subtree (node smaller than course)
 //	if (courseID < node->course.courseID) {
 //		node->left = removeNode(node->left, courseID);
 //	}
 //	// Recurse down the right subtree (node bigger than course)
 //	else if (courseID > node->course.courseID) {
 //		node->right = removeNode(node->right, courseID);
 //	}
 //	// course is neither bigger nor smaller, must be a match
 //	else {
 //		// Leaf node with no child branches
 //		if (node->left == nullptr && node->right == nullptr) {
 //			delete node;
 //			node = nullptr;
 //		}
 //		// One child branch to the left
 //		else if (node->left != nullptr && node->right == nullptr) {
 //			Node* temp = node; // Temporary node pointer
 //			node = node->left; // Set the node to the left child
 //			delete temp;
 //		}
 //		// One child branch to the right
 //		else if (node->right != nullptr && node->left == nullptr) {
 //			Node* temp = node; // Temporary node pointer
 //			node = node->right; // Set the node to the right child
 //			delete temp;
 //		}
 //		// node has two child branches
 //		else {
 //			Node* temp = node->right;  // Temporary node pointer
 //			// Find the smallest node in the right subtree
 //			while (temp->left != nullptr) {
 //				temp = temp->left;
 //			}
 //			// Copy the data from the smallest node to the current node
 //			node->course = temp->course;
 //			// Remove the smallest node from the right subtree
 //			node->right = removeNode(node->right, temp->course.courseID);
 //		}
 //	}
 //	return node;
 //}


/*
* helper function that removes all spaces from a string
*/
// Function to remove all spaces from a given string 
string removeSpaces(string str)
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

/**
 * Load a CSV file containing courses into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the courses read
 */
void loadCourses(string csvPath, BinarySearchTree* bst) {

	std::cout << "Loading CSV file " << csvPath << endl;
	// to fullfill the requirement of reading in the course list from a file
		// a pre-req must always be found in the file, 
		// so first must generate a list of the courses contained in the list to check against

	string fileText;
	ifstream MyReadFile(csvPath);

	// empty list 
	vector<string> courseIds;
	while (getline(MyReadFile, fileText)) {
		//extract the course ID from the file, convert to caps for searching later
		string id = removeSpaces(fileText.substr(0, fileText.find(',')));//extract the course ID from the file line
		string idUpper = "";

		// convert characters to caps
		for (int x = 0; x < id.size(); x++)
			idUpper += (toupper(id[x]));

		string courseID = removeSpaces(idUpper); // remove spaces just in case there are any

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


	// now that we have a list of courses to check against, we can begin inporting the courses into
	// the BST for use later
	ifstream MyReadFile2(csvPath);
	//process the entire file

	//it is assumed there is no headers included in the data file

	while (getline(MyReadFile2, fileText)) {
		Course newCourse;

		//make sure the course ID name is full caps to ensure search will work properly
		string id = fileText.substr(0, fileText.find(','));//extract the course ID from the file line
		string idUpper = "";
		for (int x = 0; x < id.size(); x++)
			idUpper += (toupper(id[x]));

		newCourse.courseID = removeSpaces(idUpper);  // remove spaces just in case there are any

		fileText.erase(0, fileText.find(',') + 1); // remove the course ID from the string

		newCourse.title = fileText.substr(0, fileText.find(','));//extract the title from the file 
		fileText.erase(0, fileText.find(',') + 1); // remove the course name from the string

		// get the last printable character of the string of prereqs, it should be a comma, 
		// but may not be based on the example input formats provided
		// the very last character is a newline, so we need to ignore that and look for the last
		// printable character before it
		int last = fileText.length() - 1; //size of the string minus the newline
		if (fileText.substr(last, 1) != ",") {
			// add the missing comma for proper operation
			fileText += ",'";
		}

		//cycle thru all the listed prereqs in the line
		while (fileText.find(',') != string::npos) {

			string preReq = fileText.substr(0, fileText.find(','));//extract the next pre-requisite from the file
			fileText.erase(0, fileText.find(',') + 1); // remove the pre-requisite from the string

			//check if the pre-requisite is in the list of courses

			if (preReq == "") { //handle empty req list
				// nothing to do, so we can skip the following checks and insert directly
				//bst->Insert(newCourse); // will be done at the end of the sequence
				break;  // jump out to the while loop which should not continue again
			}

			// preReq input was not empty, so newcourse.preReq' should contain prereq when we are done here
			int i = 0;
			for (i = 0; i < courseIds.size(); ++i) {
				if (preReq == courseIds[i]) {
					// if the pre-requisite is in the list, add it to the pre req courses list
					newCourse.preRequisits = newCourse.preRequisits + preReq + ", ";
					//break;
				}

			}

			//check the newCourse.preRequisits text for the preReq data
			string checkString = newCourse.preRequisits;
			if (checkString.find(preReq) == string::npos) {
				std::cout << "The following course was not found in the list: " << preReq << endl;
				std::cout << "aborting import of courses " << endl;
				std::exit(1);
			}

		}


		// all course prerequisite items have been checked, if we made it this far they must have all been found.
		// now we can add the course


		bst->Insert(newCourse); // add the course to the BST
	}

}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
	str.erase(remove(str.begin(), str.end(), ch), str.end());
	return atof(str.c_str());
}







/**
 * The one and only main() method
 */
int main(int argc, char* argv[]) {

	// process command line arguments
	string csvPath, courseKey;
	switch (argc) {
	case 2:
		csvPath = argv[1];
		break;
	case 3:
		csvPath = argv[1];
		break;
	default:
		csvPath = "CS 300 ABCU_Advising_Program_Input.csv";
	}

	// Define a timer variable
	clock_t ticks;

	// Define a binary search tree to hold all courses
	BinarySearchTree* bst;
	bst = new BinarySearchTree();
	Course course;

	int choice = 0;
	while (choice != 9) {
		// display the supported list of available options
		cout << endl << endl;
		cout << "1. Load Data Structure." << endl;
		cout << "2. Print Course List." << endl;
		cout << "3. Print Course." << endl;
		cout << "9. Exit" << endl;
		cout << "What would you like to do ? ";
		cin >> choice;

		switch (choice) {

		case 1:
		{

			// Initialize a timer variable before loading courses
			ticks = clock();

			// Complete the method call to load the courses
			loadCourses(csvPath, bst);

			//cout << bst->Size() << " courses read" << endl;

			// Calculate elapsed time and display result
			ticks = clock() - ticks; // current clock ticks minus starting clock ticks
			std::cout << "time: " << ticks << " clock ticks" << endl;
			std::cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			break;
		}// case 1

		case 2:
		{
			cout << endl; // just for readability on the screen
			bst->InOrder();
			break;
		} // case 2
		case 3: {
			ticks = clock();

			// What course do you want to know about ? csci400
			cout << "What course do you want to know about ? ";
			string courseID;
			//getline(cin, usr_str);
			cin.clear();
			cin.ignore();
			getline(cin,courseID);
			//courseID += "\n";

			// convert the courseID to upper case, we need to be consistent
			// in the use of cases to ensure searching works under any input 
			// condition in either the course list input or user search
			// request entry format.
			string courseIDUpper = "";
			for (int x = 0; x < courseID.size(); x++)
				courseIDUpper += (toupper(courseID[x]));

			// remove any errant spaces the user might have included
			// Function to remove all spaces from a given string 
			courseIDUpper = removeSpaces(courseIDUpper);
			

			// id is converted to upper case formatted inside the search function
			// we can pass it directly
			course = bst->Search(courseIDUpper);

			ticks = clock() - ticks; // current clock ticks minus starting clock ticks

			if (!course.courseID.empty()) {
				displayCourse(course);
			}
			else {
				std::cout << "Course Id " << courseIDUpper << " not found." << endl;
			}

			cout << "time: " << ticks << " clock ticks" << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

			break;
		} // case 3
		}
	}

	// behavior: Close the program with a courteous message

	cout << "Thank you for using the course planner!" << endl;
	exit(0);

}
