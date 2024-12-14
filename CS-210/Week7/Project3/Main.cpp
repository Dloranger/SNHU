/***************************************************
*
*  Date: [2024-DEC-13]
*  Author: [D. Loranger]
*
*
*  Title: Week 7 Assignment #3 - Corner Grocer sales reports
*  File Description: Class CornerGrocer main() file
* 
* Comments: The "guidelines" for this activity are poorly written
* with the use of 'should' instead of 'shall'.  Given the technical
* definition of 'should' all uses are interpretted as 'shall' instead,
* to implement the intent of the customer from the input document,
* but any issues implementing a requirement using this 'should' language
* could be argued as optional based on the language used.
* 
***************************************************/

#ifndef CornerGrocer_H_
#define CornerGrocer_H_
#include "CornerGrocer.h"
#endif // CornerGrocer_H_
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

const string inFile = "../CS210_Project_Three_Input_File.txt";
const string outFile = "../frequency.dat";


int userMenu(CornerGrocer Grocer) {
	// menu list defined in the customer input guidelines document
	// actual language is captured in the class implementations of the
	// respective functions.  Do not rearrange/change without clarification
	// from the customer.
	cout << endl << endl << endl;
	cout << "*********************************************" << endl;
	cout << " Please choose a menu item option to proceed" << endl;
	cout << " * 1 - Show frequency of a specific item" << endl;
	cout << " * 2 - Show frequencies of all items" << endl;
	cout << " * 3 - Show frequencies in graphical view" << endl;
	cout << " * 4 - Exit" << endl;
	cout << "*********************************************" << endl;
	int selection;
	cin >> selection;

	switch (selection) {
	case (1): { //" * 1 - Show frequency of a specific item"
		cout << "Option 1 selected" << endl;
		cout << "Enter name of item to find (case sensitive)" << endl;
		cin >> ws;  // flush input buffer
		
		string item;
		getline(cin, item);
		Grocer.showItemCount(item);
		return 0;
		break;
	}
	case (2): { //" * 2 - Show frequencies of all items"
		cout << "Option 2 selected - " << endl;
		Grocer.showItemList();
		return 0;
		break;
	}
	case (3): { //" * 3 - Show frequencies in graphical view"
		cout << "Option 3 selected - " << endl;
		Grocer.showItemChart();
		return 0;
		break;
	}
	case (4): { // " * 4 - Exit"
		cout << "Option 4 selected - exiting NOW!" << endl;
		exit(0);
		return  1;
		break;
	}
	default: {
		cout << "Unknown selection, please try again" << endl;
		return 0; 
	}
	}// switch

}

int main() {
	
	CornerGrocer Grocer;
	// one time task to initialize the data from input file
	// once imported, the data is automatically formatted
	// and sent to the outfile
	Grocer.readDailyFile(inFile, outFile);

	// interact with the user.
	while (true) {
		userMenu(Grocer);
	}
}