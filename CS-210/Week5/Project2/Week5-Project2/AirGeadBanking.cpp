#ifndef AirGeadBanking_H_
#define AirGeadBanking_H_
#include "AirGeadBanking.h"
#endif // AirGeadBanking_H_
//using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>


/***********************************************
*
*  PUBLIC
*
***********************************************/

int AirGeadBanking::RequestUserInputs() {
	double initialDeposit = 0;
	double intervalDeposit = 0;
	double annualInterestRate = 0;
	int numYears = 0;
	cout << "*********************************" << endl;
	cout << "********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: $";
	cin >> initialDeposit;
	if (setOpeningAmount(initialDeposit)) {
		cout << "ERROR  - Entry not accepted" << endl;
		return 1;
	}
	cout << "Monthly Deposit: $";
	cin >> intervalDeposit;
	if (setDepositedAmount(intervalDeposit)) {
		cout << "ERROR  - Entry not accepted" << endl;
		return 1;
	}
	cout << "Annual Interest rate: %";
	cin >> annualInterestRate;
	if (setAnnualInterest(annualInterestRate)) {
		cout << "ERROR  - Entry not accepted" << endl;
		return 1;
	}
	cout << "Number of Years: ";
	cin >> numYears;
	if (setNumOfYears(numYears)) {
		cout << "ERROR  - Entry not accepted" << endl;
		return 1;
	}
	//pause for user acknowledgement
	cin.get();
	cout << "Press any key to continue . . ." << endl;
	cin.get();  // pause for user interactions
}
void AirGeadBanking::DisplayReports() {
	Total.clear();		// empty the vector to reset computations
	Interest.clear();	// empty the vector to reset computations
	displayReportsBanner(false);  // show non recurring deposit results
	calcGrowth(Total, Interest, false);  //calc with no recurring deposits
	displayReportsComputations(Total, Interest, false);
	Total.clear();		// empty the vector to reset computations
	Interest.clear();	// empty the vector to reset computations
	cout << endl << endl << endl;
	displayReportsBanner(true);  // show non recurring deposit results
	calcGrowth(Total, Interest, true); // calc with recurring deposits
	displayReportsComputations(Total, Interest, true);
	
	//pause for user acknowledgement
	cout << "Press any key to continue . . ." << endl;
	cin.get();  // pause for user interactions
}

/***********************************************
*  
*  PRIVATE
* 
***********************************************/

void   AirGeadBanking::displayReportsBanner(bool t_intervalDeposit) {
	/********************************************
	* DisplayReports()
	* double vector NoDeposit,YesDeposit;
	* string vector SummaryReport;
	* CalcNoDeposits();
	* Display Summary report;
	* --- replace regions of the text based on vector contents size;
	* CalcYesDeposits();
	* Display Summary report;
	* --- replace regions of the text based on vector contents size;
	*/

	vector<double> NoDeposit, YesDeposit;
	vector<double> NoInterest, YesInterest;
	// last line repeats based on the number of years used
	//#DEPOSIT# gets replaced with either "With" or "Without" based on option chosen
	
	calcGrowth(NoDeposit, NoInterest, false);
	calcGrowth(YesDeposit, YesInterest, true);
	//display the banner except the last line
	for (int i = 0; i < SUMMARYREPORT.size() - 1;++i) {
		string line = SUMMARYREPORT[i];
		//test for string to require banner text substitutions
		if (!t_intervalDeposit && line.find("#DEPOSIT#")!= string::npos) {
			line.replace(line.find("#DEPOSIT#"), 9, "Without");
		}
		else if (t_intervalDeposit && line.find("#DEPOSIT#") != string::npos) {
			line.replace(line.find("#DEPOSIT#"), 9, "With");
		}
		cout << line << endl;
	}
	
}
void   AirGeadBanking::displayReportsComputations(vector<double>& t_total, vector<double>& t_interest, bool t_intervalDeposit) {
	//display the computed data
	for (int i = 1; i < t_total.size();++i) {
		string line = SUMMARYREPORT[SUMMARYREPORT.size() - 1];
		//handle substitutions
		// Year Numbers
		line.replace(
			line.find("#") - (std::to_string(i).length()) + 1, //start
			(std::to_string(i).length()), //length to left, keep right alignment
			std::to_string(i)//string to replace with
		);
		// Year End Balance

		//format balance to be 2 decimals
		string balance = "$" + std::to_string(std::round(t_total[i] * 100.0) / 100.0);
		balance = balance.substr(0, balance.find('.') + 3);
		line.replace(
			line.find("BAL") - balance.length() + 3, //start
			(balance.length()), //length to left, keep right alignment
			balance //string to replace with
		);

		// Year end Interest
		//format Interest to be 2 decimals
		string interest = "$" + std::to_string(std::round(t_interest[i] * 100.0) / 100.0);
		interest = interest.substr(0, interest.find('.') + 3);
		line.replace(
			(line.find("INT")) - interest.length() + 3, //start
			(interest.length()), //length to left, keep right alignment
			interest //string to replace with
		);

		//send to console
		cout << line << endl;

		// make row groups for easier readability, using summary report banner row
		// for consistency and always the right length for size matching
		if (i > 1 && ((i % 2) == 0)) {
			cout << SUMMARYREPORT[3] << endl;
		}
	}
}
void   AirGeadBanking::calcGrowth(vector<double>& t_total, vector<double>& t_interest, bool t_monthlyDeposit) {
	
	//initialze start point
	int intervalsPerYear = 12; // compounds monthly
	t_total.push_back(getOpeningAmount());  //interval 0 is the opening deposit
	t_interest.push_back(0); //interval 0 can't have generated any interest yet
	double deposit = 0.00; // initialize monthly deposit to 0
	if (t_monthlyDeposit) { deposit = getDepositedAmount();} //if monthlyDeposit, change to monthly deposit amount
	
	//calculate intervals accumulations
	for (int j = 1;j <= getNumOfYears();++j) {
		double sumInterest = 0;
		double sumTotal = t_total[t_total.size()-1];
		//compute n interval cycles, accumulating 
		for (int i = 1;i <= intervalsPerYear;++i) {  //calculate yearly accumulations
			/******************************************************************
			* interval Compounding equation (from requirements doc)
			* (Opening Amount + Deposited Amount)* ((Interest Rate / 100) / 12)
			******************************************************************/

			double calcInterest = ((sumTotal + deposit) * (getAnnualInterest() / 100.00 / intervalsPerYear)); // calc interest
			sumInterest += calcInterest;  // accumulate the interval interest
			sumTotal += deposit + calcInterest;  // add the interval deposit + interest
		}
		t_interest.push_back(sumInterest);  //write interval accumulation
		t_total.push_back(sumTotal);  //write interval total 
	}
}
int    AirGeadBanking::setOpeningAmount(double t_openingAmount) {
	//negative deposit doesn't make sense. 
	if ((int(t_openingAmount * 100)) > 0) {
		m_openingAmount = t_openingAmount;
		return 0;
	}
	else {
		return 1;
	}
}
double AirGeadBanking::getOpeningAmount(void) const {
	return m_openingAmount;
}
int    AirGeadBanking::setDepositedAmount(double t_deposit) {
	//negative deposit doesn't make sense. 
	if (t_deposit >= 0) {
		m_depositedAmount = t_deposit;
		return 0;
	}
	else {
		return 1;
	}
}
double AirGeadBanking::getDepositedAmount(void) const {
	return m_depositedAmount;
}
int    AirGeadBanking::setAnnualInterest(double t_interest) {
	//negative interest doesn't make sense. 
	if (t_interest>=0) {
		m_annualInterest = t_interest;
		return 0;
	}
	else {
		return 1;
	}
}
double AirGeadBanking::getAnnualInterest(void) const {
	return m_annualInterest;
}
int    AirGeadBanking::setNumOfYears(int t_years) {
	if (t_years>0) {
		m_numOfYears = t_years;
		return 0;
	}
	else { 
		return 1; 
	}
}
int    AirGeadBanking::getNumOfYears(void) const {
	return m_numOfYears;
}
