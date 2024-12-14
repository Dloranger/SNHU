/***************************************************
*
*  Date: [2024-DEC-13]
*  Author: [D. Loranger]
*
*
*  Title: Week 7 Assignment #3 - Corner Grocer sales reports
*  File Description: Class CornerGrocer cpp file
***************************************************/

#ifndef CornerGrocer_H_
#define CornerGrocer_H_
#include "CornerGrocer.h"
#endif // CornerGrocer_H_
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


int CornerGrocer::showItemCount(string item) const {
	/******************************************************
	* -REQUIREMENT INPUT
	* Menu Option One:
	* 1. Prompt a user to input the item, or word, they wish to look for.
	* 2. Return a numeric value for the frequency of the specic word.
	*
	******************************************************/
	for (int i = 0; i < itemList.size();++i)
	{
		if (item == itemList[i]) {
			//item found, use the existing vector position
			cout << "item: \"" << itemList[i] << "\" found, sales: " << itemCount[i] << endl;
			return 0;
		}
		//handle item not found after full sweep
		if (i == (itemList.size() - 1)) {
			cout << "Item: " << item << " not found in todays sales list" << endl;
			return 1;
		}

	}
}
int CornerGrocer::showItemList() const {
	/******************************************************
	* -REQUIREMENT INPUT
	* Menu Option Two:
	* Print the list with numbers that represent the frequency of all items purchased.
	* The screen output should include every item (represented by a word) paired with
	* the number of times that item appears in the input file, 
	* CS210_Project_Three_Input_File.txt. For example, the file might read as follows:
	*		Potatoes 4
	*		Pumpkins 5
	*		Onions 3
	*
	******************************************************/

	for (int i = 0; i < itemList.size();++i)
	{
		cout << "item: \"" << itemList[i] << "\" sales: " << itemCount[i] << endl;
	}
	return 0;
}
int CornerGrocer::showItemChart() const {
	/******************************************************
* -REQUIREMENT INPUT
* Menu Option Three:
* 1. Print the same frequency information for all the items in the form of a histogram.
* 2. Then print the name, followed by asterisks or another special character to represent
* the numeric amount. The number of asterisks should equal the frequency read from the
* CS210_Project_Three_Input_File.txt file. For example, if the file includes 4 potatoes,
* 5 pumpkins, and 3 onions, then your text-based histogram may appear as represented below.
* However, you can alter the appearance or color of the histogram in any way you choose:
*
*       Potatoes ****
*       Pumpkins *****
*       Onions ***
*
******************************************************/
	for (int i = 0; i < itemList.size();++i)
	{
		int width = 15 - itemList[i].length();
		//print the item name
		cout << itemList[i];
		//pad the text a bit to align the charts
		for (int j = 0; j < width;++j) {
			cout << " ";
		}
		cout << "|";
		//Show a + for each sale set above 50
		for (int j = 0;j < itemCount[i] / 50;++j) {
			cout << "+";
		}
		//Show a * for each sale below increments of 50
		for (int j = 0;j < itemCount[i] % 50;++j) {
			cout << "*";
		}
		cout << endl;

	}
	for (int j = 0;j < 15;++j) {
		cout << " ";
	}
	for (int j = 0;j < 50;++j) {
		cout << "-";
	}
	cout << endl;
	cout << "\"+\" = 50 units" << endl;
	cout << "\"*\" = 1 unit" << endl;
	return 0;
}
void CornerGrocer::writeDatFile(string t_datFile) {

	/******************************************************
	* -REQUIREMENT INPUT
	* Data File Creation:
	* Create a data file, with the naming convention frequency.dat, for backing up your accumulated data.
	* The frequency.dat file should include every item (represented by a word) paired with the number of
	* times that item appears in the input file.
	*
	* This output file is created in the beginning of the program without user intervenon and is for
	* backup purposes. For assistance with writing files, see secons 7.1, "File Input," and 7.3, "File
	* Output," in zyBooks.
	*
	******************************************************/
	ofstream writeFS;
	writeFS.open(t_datFile);
	if (!writeFS.is_open()) {
		cout << "ERROR: Could not open output file " << t_datFile << endl;

	}
	else {
		cout << "Output file " << t_datFile << " successfully opened" << endl;
	}

	for (int i = 0;i < itemList.size();++i) {
		writeFS << itemList[i] << " " << itemCount[i] << endl;
	}
	// Close the file immediately, we are done writing to it.
	writeFS.close();
}

int CornerGrocer::readDailyFile(string t_dailyFile, string t_datFile) {
	fstream readFS;

	//make sure we can open the file successfully
	readFS.open(t_dailyFile);
	if (!readFS.is_open()) {
		cout << "Could not open input file " << t_dailyFile << endl;
		return 1; // 1 indicates error
	}
	else {
		cout << "Input file " << t_dailyFile << " successfully opened" << endl;
	}

	string strInFromFile = "badInput";  // default input to detect errors
	// Use a while loop together with the getline() function to read the inFile line by line
	getline(readFS, strInFromFile);
	itemList.push_back(strInFromFile);
	itemCount.push_back(1);
	while (getline(readFS, strInFromFile)) {
		try {
			//  It is assumed that give this is generated from an automated tool, the formatting
			// and capitalization will be consistent for all items, so values are spelling and
			// case sensitive.  Cheese != cheese

		// search for existing entry in the list of products
			for (int i = 0; i < itemList.size();++i)
			{
				if (strInFromFile == itemList[i]) {
					//item found, use the existing vector position
					itemCount[i] = itemCount[i] + 1; //increment the counter
					break;
				}
				if (i == itemList.size() - 1) {
					itemList.push_back(strInFromFile); //item not found, push to the back
					itemCount.push_back(1); //set the counter
					break;
				}
			}
		}
		catch (...) {
			cout << "Something went wrong here" << endl;;
		}
		strInFromFile = "badInput";  //reset dummy value to know something is wrong if the next read goes astray
	}
	cout << " IMPORTING DATA DONE!" << endl;
	// Close the file immediately, we are done reading from it.
	readFS.close();
	writeDatFile(t_datFile);
	return 0;
}
