/*
 * Calculator.cpp
 *
 *  Date: [2024-Nov-09]
 *  Author: [D. Loranger]
 *
 */


#include <iostream>
#include <string>     // Supports use of "string" data type
using namespace std;

//void main()
int main() // changed type to int per compiler warning
{
	//char statement[100];  unused item
	//int op1, op2;
	double op1, op2;   // updated as work instructions state int or double types to be supported
	char operation;
	//char answer = "Y"
	char answer = 'Y';  // changed to single quote for type char for == testing, added missing semicolon

	//while (answer == 'y')
	while (answer == 'Y' || answer == 'y')  // updated to accept either UC or LC response based on requirements
	{
		//cout << "Enter expression" << endl;  // Expanded verbosity to the user of expected inputs
		cout << "Enter expression in the form:  ### - ###, numbers must be of type integer or double" << endl;
		cout << "Valid mathematical operations are +,-,*,/" << endl;
		//cin >> op2 >> operation >> op1;
		//cin >> op1 >> operation >> op2;  //fixed order of inputs to ensure proper operation sequence
		
		//This above cin was modified as follows based on debugging where a user entered an alpha char instead of a number
	    //https://cplusplus.com/forum/beginner/48345/
		while (!(cin >> op1 >> operation >> op2)) {//this will be true if an error occurs. It could be while( cin.fail() )
					   //but then you'd have to add the actual input
			string str;
			cin.clear();//you need to clear the flags before input
			getline(cin, str);//read what was written. Since you probably don't need this, look into cin.ignore()
			cout << str << " is not a number\n" <<endl;

			cout << "Enter expression in the form:  ### - ###, numbers must be of type integer or double" << endl;
			cout << "Valid mathematical operations are +,-,*,/" << endl;
		}
				
		// validate operation requested (new code)
		if (!((operation == '+') || (operation == '-') || (operation == '*') || (operation == '/'))) {
			cout << "ERROR: invalid operation entered, please retry" << endl;
				continue;  // skip the rest of this loop to restart with equiation entry
		}

		// inputs validated, time to do so math!!
		else {

			//if (operation == "+");  // Semicolon is not appropriate here
			//cout << op1 << " + " << op2 >> " = " << op1 + op2 << endl;   // fixed chevron directions as one was output oriented, added curly braces
			//if (operation == '-');  // Semicolon is not appropriate here
			//cout >> op1 << " - " << op2 << " = " << op1 - op2 << endl;  // fixed chevron directions as one was input oriented, added curly braces
			//if (operation == '*') 
			//cout << op1 << " / " << op2 << " = " << op1 * op2 << endl   // printed operation mismatch "/" vs "*", added curly braces, missing semicolon
			//if (operation == '/')
			//cout << op1 << " * " << op2 << " = " << op1 / op2 << endl;  // printed operation mismatch "*" vs "/", added curly braces

			// while the below if tree violates whitespace formatting standards, it is formatted such to enhance readability for consistency;
			     if (operation == '+') { cout << op1 << " + " << op2 << " = " << op1 + op2 << endl; }
			else if (operation == '-') { cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; }
			else if (operation == '*') { cout << op1 << " * " << op2 << " = " << op1 * op2 << endl; }
			else if (operation == '/') { cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; }
		}
			cout << "Do you wish to evaluate another expression? " << endl;
			cin >> answer;
			
			// validate the user input to ensure a valid action is chosen
			while (!(answer == 'y' || answer == 'Y' || answer == 'n' || answer == 'N')) {
				cout << "Invalid response! please choose Y or N only" << endl;
				cin >> answer;
			}
			if (answer == 'n' || answer == 'N') 
			{ 
				//add required print statement
				cout << "Program Finished" << endl;
				return(0); 
			}
	} // end while
} // end main

