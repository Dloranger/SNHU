#ifndef AirGeadBanking_H_
#define AirGeadBanking_H_
#include "AirGeadBanking.h"
#endif // AirGeadBanking_H_
#include <string>
#include <iostream>
using namespace std;

bool userMenu(void) {
	char selection;
	cout << "*************************************" << endl;
	cout << "1) Run calculations" << endl;
	cout << "9) exit" << endl;
	cout << "*************************************" << endl;
	cin >> selection;
	switch (selection) {
	case '1': { //user requested to run calculations
		auto User = AirGeadBanking();
		User.RequestUserInputs();
		User.DisplayReports();
		return true;
		break;
	}
	case '9': { //user requested to exit
		return false;
		break;
	}
	default: //unknown input
		return true;
		break;
	}
}

int main() {
	while (userMenu()) {	
	}
}