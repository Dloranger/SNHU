/***************************************************
*
*  Date: [2024-DEC-13]
*  Author: [D. Loranger]
*
*
*  Title: Week 7 Assignment #3 - Corner Grocer sales reports
*  File Description: Class CornerGrocer h file
***************************************************/
#pragma once
#include <fstream>
#include <vector>
using namespace std;
class CornerGrocer
{
public:
	int readDailyFile(string t_dailyFile, string t_datFile);
	int showItemCount(string item) const;
	int showItemList() const;
	int showItemChart() const;


private: 
	void writeDatFile(string DatFile);

	vector <int> itemCount;
	vector<string> itemList;
};
