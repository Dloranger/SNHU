#pragma once
using namespace std;
#include <vector>
#include <string>


class AirGeadBanking
{
public:
	int RequestUserInputs();
	void DisplayReports(void);
	

private:
	double m_openingAmount=0;
	double m_depositedAmount=0;
	double m_annualInterest=0;
	int m_numOfYears=0;

	const vector<string> SUMMARYREPORT =
	{
		"       Balance and Interest #DEPOSIT# Additional Monthly Deposits         ",
		"========================================================================",
		"  Year            Year End Balance    Year End Earned Interest          ",
		"------------------------------------------------------------------------",
		"     #                         BAL                         INT          "
	};

	vector <double> Total;
	vector <double> Interest;


	void   calcGrowth(vector<double> &t_total, vector<double>& t_interest, bool t_intervalDeposit);
	int    setOpeningAmount(double t_openingAmount);
	double getOpeningAmount(void) const;
	int    setDepositedAmount(double t_deposit);
	double getDepositedAmount(void) const;
	int    setAnnualInterest(double t_interest);
	double getAnnualInterest(void) const;
	int    setNumOfYears(int t_years);
	int    getNumOfYears(void) const;
	void   displayReportsBanner(bool t_intervalDeposit);
	void   displayReportsComputations(vector<double>& t_total, vector<double>& t_interest, bool t_intervalDeposit);
};

