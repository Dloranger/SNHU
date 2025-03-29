//============================================================================
// Name        : LinkedList.cpp
// Author      : Daniel Loranger
// Version     : 1.0
// Copyright   : Copyright © 2023 SNHU COCE
// Description : Lab 3-2 Lists and Searching
//============================================================================

#include <algorithm>
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

void displayBid(Bid bid);

//============================================================================
// Linked-List class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a linked-list.
 */
class LinkedList {

private:
    //Internal structure for list entries, housekeeping variables
    struct Node {
        Bid bid;
        Node *next;

        // default constructor
        Node() {
            next = nullptr;
        }

        // initialize with a bid
        Node(Bid aBid) {
            bid = aBid;
            next = nullptr;
        }
    };

    Node* head;
    Node* tail;
    int size = 0;

public:
    LinkedList();
    virtual ~LinkedList();
    void Append(Bid bid);
    void Prepend(Bid bid);
    void PrintList() const;
    void Remove(string bidId);
    Bid Search(string bidId) const;
    int Size()const;
};

/**
 * Default constructor 
 * DL - create an empty unidirectional linked list with null
 * DL - head and tail nodes.
 */
LinkedList::LinkedList() {
    // FIXME (1): Initialize housekeeping variables
    //set head and tail equal to nullptr
    head = nullptr;
    tail = nullptr;

} 

/**
 * Destructor
 */
LinkedList::~LinkedList() {
    // start at the head
    Node* current = head;
    Node* temp;

    // loop over each node, detach from list then delete
    while (current != nullptr) {
        temp = current; // hang on to current node
        current = current->next; // make current the next node
        delete temp; // delete the orphan node
    }
}

/**
 * Append a new bid to the end of the list 
 * DL - special corner case block added
 * DL - for when the list is empty to start with as additional settings need to
 * DL - be setup.
 */
void LinkedList::Append(Bid bid) {
    // FIXME (2): Implement append logic
    //Create new node based on the input paramter of 'bid'
    Node* newNode = new Node(bid);
    //DL - if there is nothing at the head, we can safely assume the list is empty
    //DL -  so we need to initialize both the head and the tail pointers to show
    //DL -  that the list is not empty anylonger.
    if (head == nullptr) {
        // new node becomes the head and the tail
        head = newNode;
        tail = newNode;
    }
    //DL - the existing list is not empty, so we only need to append the new bid
    //DL -  to the back of the list, and update the tail pointer.
    else {
        // make current tail node point to the new node
        tail->next = newNode;
        // and tail pointes to the new node
        tail = newNode;
     }
    //DL - increase size count to account for adding the new item to the tail
    size++;
}

/**
 * Prepend a new bid to the start of the list
 * DL - If the list is not empty, we can update the head pointer
 * DL - to point to our new node, and point the next of the new node
 * DL - to the previous head.
 */
void LinkedList::Prepend(Bid bid) {
    // FIXME (3): Implement prepend logic
    // Create new node
    Node* newNode = new Node(bid);
    // if there is already something at the head...
    if (tail != nullptr) {
        // new node points to current head as its next node
        newNode->next = head;
        // head now becomes the new node
        head = newNode;
        //DL - increase size count to account for adding the new item to the head
        size++;
    }
    //DL - tail is empty, so we assume the list is empty, to prevent redundant code
    //DL - we will reuse the Append function to add the new node to an empty list.
    else {
        Append(bid);
    }
  
}

/**
 * Simple output of all bids in the list
 * DL - Updated the function declaration to include 'const' as this function
 * DL - is not allowed to update any variables, only display existing data
 */
void LinkedList::PrintList() const {
    // FIXME (4): Implement print logic
    // start at the head
    //DL - create new pointer named currentNode to keep track of where we are
    //DL - this is basically like a cursor in a text editor, just helps to keep
    //DL - track of the current location.
    Node* currentNode = head;
   
    // while loop over each node looking for a match
    //DL - head is empty, nothing to print, return immediately.
    if (head == nullptr) {
        return;
    }
    // head is not empty, spin up a while node and itterate 1-by 1
    while (currentNode != nullptr) {
        //output current bidID, title, amount and fund
        //DL - The desplayBid is a pre-existing function found below in the test
        //DL - functions, but given the usage, it should be brought into the class
        displayBid(currentNode->bid);
        //set current equal to next
        currentNode = currentNode->next;
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
void LinkedList::Remove(string bidId) {
    // FIXME (5): Implement remove logic
    
    //DL - handle empty list, nothing to be done here
    if (head == nullptr) {
        return;
    }
    //DL - handle empty bidID quickly for efficiency
    else if (bidId == "") {
        return;
    }
    
    // DL - special case if matching node is the head
    else if (bidId == head->bid.bidId) {
 
        //DL - check for head to be the same as the tail.  If they are the same
        //DL - the result will be an empty list so need to reset all values.
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
            //DL - reset the size to zero just in case there is an accounting error
            size=0;
        }
        //DL - head not same as the tail, the list has 2+ nodes
        else {
            //DL -  make head point to the next node in the list
            head = head->next;
            //DL - decrease size count
            size--;
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
        Node* currentNode = head;
        //DL -  while loop over each node looking for a match
        //DL - Using the currentNode as our pointer, we actually need to look ahead
        //DL - one position, as if we find a match, we need to update the current node
        //DL - to be able to skip the found match.
        while ((currentNode->next ->bid.bidId != bidId)) {
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
        //DL - we can just update the tail pointer
        if (currentNode->next == tail)
        {
            //Dl - this node becomes the tail as we cant jump to a null value
            currentNode->next = nullptr;
            tail = currentNode;
        }
        //DL - not at the tail, we can jump.  We updated the current nodes next pointer to 
        //DL - skip the next node and instead point to the next nodes successor node.
        else {
            currentNode->next = currentNode->next->next;
        }
    }
}

/**
 * Search for the specified bidId
 *
 * @param bidId The bid id to search for
 * DL - Updated the function declaration to include 'const' as this function
 * DL - is not allowed to update any variables, only display existing data
 */
Bid LinkedList::Search(string bidId) const {
    // FIXME (6): Implement search logic

    //DL - create new pointer named currentNode to keep track of where we are
    //DL - this is basically like a cursor in a text editor, just helps to keep
    //DL - track of the current location.
    Node * currentNode = head;
    
    // start at the head of the list
    currentNode = head;
    //DL -  keep searching until end reached with while loop (current != nullptr)
    while (currentNode != nullptr) {
        //DL -  if the current node matches, return current bid
        if (currentNode->bid.bidId == bidId) {
            return currentNode->bid;
        }
        //DL -  else current node is equal to next node
        else {
            currentNode = currentNode->next;
        }
    }

    //(the next two statements will only execute if search item is not found)
    //create new empty bid
    Bid emptyBid;
    //return empty bid 
    return emptyBid;
}

/**
 * Returns the current size (number of elements) in the list
 */
int LinkedList::Size() const {
    return size;
}

//============================================================================
// Static methods used for testing
//============================================================================

/**
 * Display the bid information
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount
         << " | " << bid.fund << endl;
    return;
}

/**
 * Prompt user for bid information
 *
 * @return Bid struct containing the bid info
 */
Bid getBid() {
    Bid bid;

    cout << "Enter Id: ";
    cin.ignore();
    getline(cin, bid.bidId);

    cout << "Enter title: ";
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * Load a CSV file containing bids into a LinkedList
 *
 * @return a LinkedList containing all the bids read
 */
void loadBids(string csvPath, LinkedList *list) {
    cout << "Loading CSV file " << csvPath << endl;

    // initialize the CSV Parser
    csv::Parser file = csv::Parser(csvPath);

    try {
        // loop to read rows of a CSV file
        for (int i = 0; i < file.rowCount(); i++) {

            // initialize a bid using data from current row (i)
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << bid.bidId << ": " << bid.title << " | " << bid.fund << " | " << bid.amount << endl;

            // add this bid to the end
            list->Append(bid);
        }
    } catch (csv::Error &e) {
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
 *
 * @param arg[1] path to CSV file to load from (optional)
 * @param arg[2] the bid Id to use when searching the list (optional)
 */
int main(int argc, char* argv[]) {

    // process command line arguments
    string csvPath, bidKey;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        bidKey = "98109";
        break;
    case 3:
        csvPath = argv[1];
        bidKey = argv[2];
        break;
    default:
        csvPath = "eBid_Monthly_Sales.csv";
        bidKey = "98109";
    }

    clock_t ticks;

    LinkedList bidList;

    Bid bid;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter a Bid" << endl;
        cout << "  2. Load Bids" << endl;
        cout << "  3. Display All Bids" << endl;
        cout << "  4. Find Bid" << endl;
        cout << "  5. Remove Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bid = getBid();
            bidList.Append(bid);
            displayBid(bid);

            break;

        case 2:
            ticks = clock();

            loadBids(csvPath, &bidList);

            cout << bidList.Size() << " bids read" << endl;

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " milliseconds" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 3:
            bidList.PrintList();

            break;

        case 4:
            ticks = clock();

            bid = bidList.Search(bidKey);

            ticks = clock() - ticks; // current clock ticks minus starting clock ticks

            if (!bid.bidId.empty()) {
                displayBid(bid);
            } else {
            	cout << "Bid Id " << bidKey << " not found." << endl;
            }

            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 5:
            bidList.Remove(bidKey);

            break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
