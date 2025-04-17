//============================================================================
// Name        : HashTable.cpp
// Author      : Daniel Loranger
// Version     : 1.0
// Copyright   : Copyright © 2023 SNHU COCE
// Description : Lab 4-2 Hash Table
//============================================================================

#include <algorithm>
#include <climits>
#include <iostream>
#include <string> // atoi
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

const unsigned int DEFAULT_SIZE = 179;

// forward declarations
double strToDouble(string str, char ch);

// define a structure to hold bid information
struct Bid {
	string bidId; // unique identifier
	string title;
	string fund;
	double amount;
	Bid() {
		amount = 0.0;
	}
};

//============================================================================
// Hash Table class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a hash table with chaining.
 */class HashTable {


private:
	// Define structures to hold bids
	struct Node {
		Bid bid;
		unsigned int key;
		Node* next;

		// default constructor
		Node() {
			key = UINT_MAX;
			next = nullptr;
		}

		// initialize with a bid
		Node(Bid aBid) : Node() {
			bid = aBid;
		}

		// initialize with a bid and a key
		Node(Bid aBid, unsigned int aKey) : Node(aBid) {
			key = aKey;
		}
	};

	vector<Node> nodes;

	unsigned int tableSize = DEFAULT_SIZE;

	unsigned int hash(int key);

public:
	HashTable();
	HashTable(unsigned int size);
	virtual ~HashTable();
	void Insert(Bid bid);
	void PrintAll();
	void Remove(string bidId);
	Bid Search(string bidId);
	size_t Size();
};

/**
 * Default constructor
 */
HashTable::HashTable() {
	// FIXME (1): Initialize the structures used to hold bids

	// Initalize node structure by resizing tableSize
	//DL - use the default table size as established via DEFAULT_SIZE variable.
	//DL - this will create a vector of nodes with a size of 179 unless DEFUALT SIZE is changed.
	nodes.resize(tableSize);
}

/**
 * Constructor for specifying size of the table
 * Use to improve efficiency of hashing algorithm
 * by reducing collisions without wasting memory.
 */
HashTable::HashTable(unsigned int size) {
	// invoke local tableSize to size with this->
	//DL - update the table size variable to the size passed in
	this->tableSize = size;
	// resize nodes size
	//DL - resize the nodes vector to the size passed in
	nodes.resize(size);
}


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
 * Calculate the hash value of a given key.
 * Note that key is specifically defined as
 * unsigned int to prevent undefined results
 * of a negative list index.
 *
 * @param key The key to hash
 * @return The calculated hash
 */
unsigned int HashTable::hash(int key) {
	// FIXME (3): Implement logic to calculate a hash value

	//DL - Use the key and modulo table size to calculate the hash value
	// return key tableSize
	return key % tableSize;
}

/**
 * Insert a bid
 *
 * @param bid The bid to insert
 */
void HashTable::Insert(Bid bid) {
	// FIXME (4): Implement logic to insert a bid
	// create the key for the given bid
	//DL - create a key for the bid using the hash function
	//DL - use the atoi function to convert the bidID string type to an integer
	unsigned int key = hash(atoi(bid.bidId.c_str()));

	// retrieve node using key
	//DL - Search for the node using the key, using UINT_MAX to indicate no entry found
	//DL if there is a match to UINT_MAX, the node is empty, so we can reassign the node
	if (nodes.at(key).key == UINT_MAX) {
		// if no entry found for the key
		// assign this node to the key position
		//DL - create a new node based on the bid input and the key we just created
		nodes.at(key) = Node(bid, key);

	}
	else {
		//DL - this is a collision, so we need to find the next open node in the list
		//DL - start at the default key position
		Node* cursor = &nodes.at(key);

		//DL - loop through the list until we find the end
		//DL - scan the list to find the last position
		while (cursor->next != NULL) {
			cursor = cursor->next;
		}
		//DL - We found the end of the list, so add the new node to the end
		//DL - the new node automatically sets the next pointer to null
		cursor->next = new Node(bid, key);
	}
}

/**
 * Print all bids
 */
void HashTable::PrintAll() {
	// FIXME (5): Implement logic to print all bids
	// for node begin to end iterate
	for (int i = 0; i < tableSize; i++) {
		//   if key not equal to UINT_MAx
		Node cursor = nodes.at(i);
		if (cursor.key != UINT_MAX) {
			//DL - prescribed output format below, first output the key, then the bidID, title, amount, and fund
			//DL - Exact layout is interpretted by inspection of sample which is poorly formatted in a word document using word wrap
			//
			//DL - for collisions (multiple items), omit the prefix "Key ", but print all additional contents
			//Key 2: 98094 | Credenza | 57 | General Fund
			//2: 98273 > | Nike Tennis Shoes Size : 11.5 | 84 | Enterprise
			//DL first instance print the prefix 1x
			cout << "Key ";


			// output key, bidID, title, amount and fund 
			cout << cursor.key << ": "
				<< cursor.bid.bidId << " | "
				<< cursor.bid.title << " | "
				<< cursor.bid.amount << " | "
				<< cursor.bid.fund << endl;
			//DL - itterate thru the list of nodes remaining

			// while node not equal to nullptr
			while (cursor.next != nullptr) {
				//DL - increment the cursor to the next node
				// node is equal to next iter
				cursor = *cursor.next;
				// output key, bidID, title, amount and fund
				cout << cursor.key << ": "
					<< cursor.bid.bidId << " | "
					<< cursor.bid.title << " | "
					<< cursor.bid.amount << " | "
					<< cursor.bid.fund << endl;
			}
		}
	}
}


/**
 * Remove a specified bid
 *
 * @param bidId The bid id to remove from the list
 * DL - The position of the bid is unknown, it could be first, last
 * DL - somewhere in the middle, or missing entirely.  The list could be
 * DL - empty, single node, or a longer list.  We need to account
 * DL - for all possible outcomes seperately as the impacts will vary in
 * DL - each scenario.
 */
void HashTable::Remove(string bidId) {

	//DL - handle empty bidID quickly for efficiency
	if (bidId == "") {
		return;
	}
	//DL - Establish a cursor at the head of the list
	Node* cursor = & nodes.at(hash(stoi(bidId)));
	//DL - special case if matching node is the head
	if (bidId == cursor->bid.bidId) {
		//DL - check for head to be the last entry
		if (cursor->next == nullptr) {
			//reset the bucket
			cursor = new Node();
		}
		//DL - head not same as the tail, the list has 2+ nodes
		else {
			//DL -  make head point to the next node in the list
			cursor = cursor->next;
		}
		//return
		return;
	}
	//DL - node is not the head, need to search through the list until we find it
	//DL - but it may not exist.
	else
	{
		// start at the head
		//DL - create new pointer named currentNode to keep track of where we are
		//DL - this is basically like a cursor in a text editor, just helps to keep
		//DL - track of the current location.
		Node* currentNode = &nodes.at(hash(stoi(bidId)));
		//DL -  while loop over each node looking for a match
		//DL - Using the currentNode as our pointer, we actually need to look ahead
		//DL - one position, as if we find a match, we need to update the current node
		//DL - to be able to skip the found match.
		while ((currentNode->next->bid.bidId != bidId)) {
			//DL - Not a match so far,
			//DL - have we reached the end of the list?  We need to look ahead
			//DL - 2 positions here as updating could create an out of bounds condition
			if (currentNode->next->next == nullptr) {
				return;
			}
			//DL - We are not at the end of the list, update cursor and continue searching
			else {
				currentNode = currentNode->next;
			}
		}

		//DL -  we must have found a match since the while loop terminated without returning.
		//DL -  keep in mind we are looking ahead for the match so we can update our current 
		//DL -  nodes next pointer.

		//DL - handle tail is the match condition, we can't skip ahead in this condition, so 
		//DL - we can just update the node values to default
		if (currentNode->next == nullptr)
		{
			currentNode->bid = Node().bid;  //reset the bid to default
			currentNode->key = Node().key;	//reset the key to default
			currentNode->next = Node().next; //reset the next pointer to default
		}
		//DL - not at the tail, we can jump.  We updated the current nodes next pointer to 
		//DL - skip the next node and instead point to the next nodes successor node.  This might be null
		//DL - but we are not concerned with that here.
		else {
			currentNode->next = currentNode->next->next;
		}
	}
}

/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 */
Bid HashTable::Search(string bidId) {
	Bid bid;

	// FIXME (7): Implement logic to search for and return a bid

	// create the key for the given bid
	// if entry found for the key
		 //return node bid

	// if no entry found for the key
	  // return bid
	// while node not equal to nullptr
		// if the current node matches, return it
		//node is equal to next node

	return bid;
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
	cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
		<< bid.fund << endl;
	return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, HashTable* hashTable) {
	cout << "Loading CSV file " << csvPath << endl;

	// initialize the CSV Parser using the given path
	csv::Parser file = csv::Parser(csvPath);

	// read and display header row - optional
	vector<string> header = file.getHeader();
	for (auto const& c : header) {
		cout << c << " | ";
	}
	cout << "" << endl;

	try {
		// loop to read rows of a CSV file
		for (unsigned int i = 0; i < file.rowCount(); i++) {

			// Create a data structure and add to the collection of bids
			Bid bid;
			bid.bidId = file[i][1];
			bid.title = file[i][0];
			bid.fund = file[i][8];
			bid.amount = strToDouble(file[i][4], '$');

			//cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

			// push this bid to the end
			hashTable->Insert(bid);
		}
	}
	catch (csv::Error& e) {
		std::cerr << e.what() << std::endl;
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
	string csvPath, bidKey;
	switch (argc) {
	case 2:
		csvPath = argv[1];
		bidKey = "98223";
		break;
	case 3:
		csvPath = argv[1];
		bidKey = argv[2];
		break;
	default:
		csvPath = "eBid_Monthly_Sales.csv";
		bidKey = "98223";
	}

	// Define a timer variable
	clock_t ticks;

	// Define a hash table to hold all the bids
	HashTable* bidTable;

	Bid bid;
	bidTable = new HashTable();

	int choice = 0;
	while (choice != 9) {
		cout << "Menu:" << endl;
		cout << "  1. Load Bids" << endl;
		cout << "  2. Display All Bids" << endl;
		cout << "  3. Find Bid" << endl;
		cout << "  4. Remove Bid" << endl;
		cout << "  9. Exit" << endl;
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {

		case 1:

			// Initialize a timer variable before loading bids
			ticks = clock();

			// Complete the method call to load the bids
			loadBids(csvPath, bidTable);

			// Calculate elapsed time and display result
			ticks = clock() - ticks; // current clock ticks minus starting clock ticks
			cout << "time: " << ticks << " clock ticks" << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			break;

		case 2:
			bidTable->PrintAll();
			break;

		case 3:
			ticks = clock();

			bid = bidTable->Search(bidKey);

			ticks = clock() - ticks; // current clock ticks minus starting clock ticks

			if (!bid.bidId.empty()) {
				displayBid(bid);
			}
			else {
				cout << "Bid Id " << bidKey << " not found." << endl;
			}

			cout << "time: " << ticks << " clock ticks" << endl;
			cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			break;

		case 4:
			bidTable->Remove(bidKey);
			break;
		}
	}

	cout << "Good bye." << endl;

	return 0;
}
