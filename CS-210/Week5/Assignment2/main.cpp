/*
 *
 *  Date: [2024-Nov-27]
 *  Author: [D. Loranger]
 *
 *
 *  Title: FtoC temperature conversion with files
 */

#include <iostream>
#include <fstream>
#include <string>     // Supports use of "string" data type
using namespace std;
#include <vector>

const string InputFileName = "../FahrenheitTemperature.txt";
const string OutputFileName = "../CelsiusTemperature.txt";






int main() 
{
    /***************************************************************
    * 
    * Read inputs from the text file
    * 
    ***************************************************************/
    fstream readFS; 
    
    //make sure we can open the file successfully
    readFS.open(InputFileName);
    if (!readFS.is_open()) {
        cout << "Could not open input file " << InputFileName << endl;
        return 1; // 1 indicates error
    }
    else {
        cout << "Input file " << InputFileName << " successfully opened" << endl;
    }

    // file must have opened successfully
    vector <int> TemperaturesF;  // vector for holding the incoming temp data
    vector <string> Cities;      // vector for holding the incoming city name
    string strInFromFile = "ABCD 123456789";  // dummy value to know something is wrong if the read goes astray

    // Use a while loop together with the getline() function to read the inFile line by line
    while (getline(readFS, strInFromFile)) {
        
        // City name is handled as a string, so even if a number is present, it will get handled as a string.
        // This might be desirable to distinguish multiple cities with the same name so it is treated as a 
        // valid option, no error checking on city name will be done.
        //       
        // Temperature is more critical as it gets converted to an int, need to validate it before using.
                
        try {
            TemperaturesF.push_back(stoi(strInFromFile.substr(strInFromFile.find(' ') + 1)));   // convert string to int
            Cities.push_back(strInFromFile.substr(0, strInFromFile.find(' ')));                 // capture the city name
        }
        catch (...) {
            // we don't know that removing the field from the outfile might break something entirely down stream
            // so it is chosen to keep the contents 1:1 but we provide an impossibly (below absolute zero) cold temperature.
            // This allows all other cities to work as normal for say an automated forcast display, where a weatherman
            // could see the erant data in real-time or during prep and make the needed corrections without breaking the 
            // overall workflow.

            cout << "ERROR - City:" << strInFromFile.substr(0, strInFromFile.find(' ')) << " has a bad temperature value" << endl;
            Cities.push_back(strInFromFile.substr(0, strInFromFile.find(' ')));                 // capture the city name
            TemperaturesF.push_back(-9999);  // impossibly cold value
        }
        strInFromFile = "ABCD 123456789";  //reset dummy value to know something is wrong if the next read goes astray
    }
    // Close the file immediately, we are done reading from it.
    readFS.close();



    /***************************************************************
    * 
    * Convert F to C and write back out to file
    * 
    ***************************************************************/
    ofstream writeFS;
    //make sure we can open the file successfully
    writeFS.open(OutputFileName);
    if (!writeFS.is_open()) {
        cout << "Could not open output file " << OutputFileName << endl;
        return 1; // 1 indicates error
    }
    else {
        cout << "Output file " << OutputFileName << " successfully opened" << endl;
    }
    // write the data to file with temperature conversion done inline for simplicity
    for (int i = 0;i < Cities.size();++i) {
        writeFS << Cities[i] << " " << ((TemperaturesF[i] - 32) * 5 / 9) << endl;
    }
    // Close the file immediately, we are done writing to it.
    writeFS.close();

    return 0;
}
