//============================================================================
// Name        : BinarySearchTree.cpp
// Author      : Daniel Loranger
// Version     : 1.0
// Copyright   : Copyright � 2023 SNHU COCE
// Description : Lab 5-2 Binary Search Tree
//============================================================================

#include <iostream>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

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

// Internal structure for tree node
struct Node {
	Bid bid;
	Node* left;
	Node* right;

	// default constructor
	Node() {
		left = nullptr;
		right = nullptr;
	}

	// initialize with a bid
	Node(Bid aBid) :
		Node() {
		bid = aBid;
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

	void addNode(Node* node, Bid bid);
	void inOrder(Node* node);
	void postOrder(Node* node);
	void preOrder(Node* node);
	void clearNodes(Node*& cur); //reference on pointer
	Node* removeNode(Node* node, string bidId);

public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	void InOrder();
	void PostOrder();
	void PreOrder();
	void Insert(Bid bid);
	void Remove(string bidId);
	Bid Search(string bidId);
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
BinarySearchTree::~BinarySearchTree() {
	//FixMe (2)
	// recurse from root deleting every node
	clearNodes(root);
}


/*
* DL - Recursion code from
* DL - https ://stackoverflow.com/questions/32296437/recursively-delete-every-nodes-in-binary-tree
*
* DL - This function will delete all nodes in the tree recursively
* DL - and set the root to null
*/

void BinarySearchTree::clearNodes(Node*& cur) //reference on pointer
{
	if (cur == NULL)
	{
		return;
	}

	clearNodes(cur->left);
	clearNodes(cur->right);

	delete cur;
	cur = NULL; //neccessary
}
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
void BinarySearchTree::PostOrder() {
	// FixMe (4a): Post order root
	// postOrder root
	postOrder(root);
}

/**
 * Traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder() {
	// FixMe (5a): Pre order root
	// preOrder root
	preOrder(root);
}



/**
 * Insert a bid
 */
void BinarySearchTree::Insert(Bid bid) {
	// FIXME (6a) Implement inserting a bid into the tree
	// if root equarl to null ptr
	  // root is equal to new node bid
	if (root == nullptr) {
		root = new Node(bid);
	}
	// else
	  // add Node root and bid
	else {
		addNode(root, bid);
	}
}

/**
 * Remove a bid
 */
void BinarySearchTree::Remove(string bidId) {
	// FIXME (7a) Implement removing a bid from the tree
	// remove node root bidID
	removeNode(root, bidId); //remove node root bidID
}

/**
 * Search for a bid
 */
Bid BinarySearchTree::Search(string bidId) {
	// FIXME (8) Implement searching the tree for a bid
	// set current node equal to root
	Node* currentNode = root;
	// keep looping downwards until bottom reached or matching bidId found
	while (currentNode != nullptr) {
		// if match found, return current bid
		if (currentNode->bid.bidId == bidId) {
			return currentNode->bid;
		}
		// if bid is smaller than current node then traverse left
		// else larger so traverse right
		else if (bidId < currentNode->bid.bidId) {
			currentNode = currentNode->left;
		}
		else {
			currentNode = currentNode->right;
		}
	}
	Bid bid;
	return bid;
}

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
void BinarySearchTree::addNode(Node* node, Bid bid) {
	// FIXME (6b) Implement inserting a bid into the tree
	// if node is larger then add to left
	if (node->bid.bidId > bid.bidId) {
		// if no left node
		if (node->left == nullptr) {
			// this node becomes left
			node->left = new Node(bid);
		}
		else {// else recurse down the left node
			addNode(node->left, bid);
		}
	}


	// else // node is smaller then add to right
	else {
		// // if no right node
		if (node->right == nullptr) {
			node->right = new Node(bid);// this node becomes right
		}
		else {//else
			// recurse down the right node
			addNode(node->right, bid);
		}
	}
}


void BinarySearchTree::inOrder(Node* node) {
	// FixMe (3b): Pre order root
	//if node is not equal to null ptr
	if (node != nullptr) {
		//InOrder not left
		inOrder(node->left);
		//output bidID, title, amount, fund
		std::cout << node->bid.bidId << ", " << node->bid.title << ", " << node->bid.amount << ", " << node->bid.fund << endl;
		//InOrder right
		inOrder(node->right);
	}
}
void BinarySearchTree::postOrder(Node* node) {
	// FixMe (4b): Pre order root
	//if node is not equal to null ptr
	if (node != nullptr) {
		//postOrder left
		//postOrder right
		postOrder(node->left);
		postOrder(node->right);

		//output bidID, title, amount, fund
		std::cout << node->bid.bidId << ", " << node->bid.title << ", " << node->bid.amount << ", " << node->bid.fund << endl;
	}
}

void BinarySearchTree::preOrder(Node* node) {
	// FixMe (5b): Pre order root
	//if node is not equal to null ptr
	if (node != nullptr) {
		//output bidID, title, amount, fund
		std::cout << node->bid.bidId << ", " << node->bid.title << ", " << node->bid.amount << ", " << node->bid.fund << endl;
		//postOrder left
		postOrder(node->left);
		//postOrder right      
		postOrder(node->right);
	}
}

/**
 * Remove a bid from some node (recursive)
 */
Node* BinarySearchTree::removeNode(Node* node, string bidId) {
	// parent node has no children
	if (node == nullptr) {
		return node;
	}
	// Recurse down the left subtree (node smaller than bid)
	if (bidId < node->bid.bidId) {
		node->left = removeNode(node->left, bidId);
	}
	// Recurse down the right subtree (node bigger than bid)
	else if (bidId > node->bid.bidId) {
		node->right = removeNode(node->right, bidId);
	}
	// bid is neither bigger nor smaller, must be a match
	else {
		// Leaf node with no child branches
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
		}
		// One child branch to the left
		else if (node->left != nullptr && node->right == nullptr) {
			Node* temp = node; // Temporary node pointer
			node = node->left; // Set the node to the left child
			delete temp;
		}
		// One child branch to the right
		else if (node->right != nullptr && node->left == nullptr) {
			Node* temp = node; // Temporary node pointer
			node = node->right; // Set the node to the right child
			delete temp;
		}
		// node has two child branches
		else {
			Node* temp = node->right;  // Temporary node pointer
			// Find the smallest node in the right subtree
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			// Copy the data from the smallest node to the current node
			node->bid = temp->bid;
			// Remove the smallest node from the right subtree
			node->right = removeNode(node->right, temp->bid.bidId);
		}
	}
	return node;
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
	std::cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | "
		<< bid.fund << endl;
	return;
}

/**
 * Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
void loadBids(string csvPath, BinarySearchTree* bst) {
	std::cout << "Loading CSV file " << csvPath << endl;

	// initialize the CSV Parser using the given path
	csv::Parser file = csv::Parser(csvPath);

	// read and display header row - optional
	vector<string> header = file.getHeader();
	for (auto const& c : header) {
		std::cout << c << " | ";
	}
	std::cout << "" << endl;

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
			bst->Insert(bid);
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

	// Define a binary search tree to hold all bids
	BinarySearchTree* bst;
	bst = new BinarySearchTree();
	Bid bid;

	int choice = 0;
	while (choice != 9) {
		std::cout << "Menu:" << endl;
		std::cout << "  1. Load Bids" << endl;
		std::cout << "  2. Display All Bids" << endl;
		std::cout << "  3. Find Bid" << endl;
		std::cout << "  4. Remove Bid" << endl;
		std::cout << "  9. Exit" << endl;
		std::cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {

		case 1:

			// Initialize a timer variable before loading bids
			ticks = clock();

			// Complete the method call to load the bids
			loadBids(csvPath, bst);

			//cout << bst->Size() << " bids read" << endl;

			// Calculate elapsed time and display result
			ticks = clock() - ticks; // current clock ticks minus starting clock ticks
			std::cout << "time: " << ticks << " clock ticks" << endl;
			std::cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
			break;

		case 2:
			bst->InOrder();
			break;

		case 3:
			ticks = clock();

			bid = bst->Search(bidKey);

			ticks = clock() - ticks; // current clock ticks minus starting clock ticks

			if (!bid.bidId.empty()) {
				displayBid(bid);
			}
			else {
				std::cout << "Bid Id " << bidKey << " not found." << endl;
			}

			std::cout << "time: " << ticks << " clock ticks" << endl;
			std::cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

			break;

		case 4:
			bst->Remove(bidKey);
			break;
		}
	}

	std::cout << "Good bye." << endl;

	return 0;
}
