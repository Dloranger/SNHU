/*
 * Clock app
 *
 *  Date: [2024-Nov-09]
 *  Author: [D. Loranger]
 *
 *
 * Title: Clocks Flowchart
*
* START Program
* Get User Input for Initial Time
* LOOP
* Display Menu (Process)
* IF Add Hour? (Decision)
*     Add Hour (Process)
* Display Time (Process)
* IF Add Minute? (Decision)
*     Add Minute (Process)
* Display Time (Process)
* IF Add Second? (Decision)
*     Add Second (Process)
* Display Time (Process)
* IF EXIT? (Decision)
*     Exit (Process)
* END LOOP
* END Program
*
 */

#include <iostream>
#include <string>     // Supports use of "string" data type
using namespace std;
#include <vector>
#include <windows.h>  //used to get the window size


// Globals for time keeping
int seconds =0;
int minutes = 0;
int hours = 0;

string twoDigitString(unsigned int n) {
    string strNum = to_string(n);
    //format as 2 digits
    if (strNum.size() == 1) {
        strNum = "0" + strNum;
    }
    return strNum;

}
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string time12DispFormat = "HH:MM:SS $ M";

    // update the time24DispFormat with actual time values
    int hour_fix = h % 12;
    if (hour_fix == 0) { hour_fix = 12; }
    if (h >= 12) { 
        time12DispFormat = time12DispFormat.replace(time12DispFormat.find("$"), 1, "P"); 
    }
    else {
            time12DispFormat = time12DispFormat.replace(time12DispFormat.find("$"), 1, "A");
    }
    time12DispFormat = time12DispFormat.replace(time12DispFormat.find("HH"), 2, twoDigitString(hour_fix));
    time12DispFormat = time12DispFormat.replace(time12DispFormat.find("MM"), 2, twoDigitString(m));
    time12DispFormat = time12DispFormat.replace(time12DispFormat.find("SS"), 2, twoDigitString(s));
    return time12DispFormat;
}
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    string time24DispFormat = "HH:MM:SS";

    // update the time24DispFormat with actual time values
    time24DispFormat = time24DispFormat.replace(time24DispFormat.find("HH"), 2, twoDigitString(h));
    time24DispFormat = time24DispFormat.replace(time24DispFormat.find("MM"), 2, twoDigitString(m));
    time24DispFormat = time24DispFormat.replace(time24DispFormat.find("SS"), 2, twoDigitString(s));
    return time24DispFormat;
}
void AddTimeHours() {
    //updates global int hours 
    hours++;
    if (hours >= 24) {
        hours = 0;
    }
}
void AddTimeMinutes() {
    //updates global int minutes
    minutes++;
    if (minutes >= 60) {
        minutes = 0;
        AddTimeHours();
    }
}
void AddTimeSeconds() {
    //updates global int seconds 
    seconds++;
    if (seconds >= 60) { 
        seconds = 0; 
        AddTimeMinutes();
    }
}
string nCharString(size_t n, char c) {
    if (n <= 0) {
        return ""; 
    }
    else {
        return string(n, c);
    }
}
void TimeInit() {
    bool timeValid = false;
    while (timeValid == false) {
        std::cout << "Please enter the current time as HH MM SS using 24 hour time format" << endl;
        while (!(cin >> hours >> minutes >> seconds)) {//this will be true if an error occurs. It could be while( cin.fail() )
                                                       //but then you'd have to add the actual input
            string str;
            cin.clear();//you need to clear the flags before input
            getline(cin, str);//read what was written. Since you probably don't need this, look into cin.ignore()
            std::cout << str << " is not a number\n" << endl;

            std::cout << "Please re-enter the current time as HH MM SS using 24 hour time format" << endl;
        } //CIN data type check
        //validate the entries
        if ((hours >= 0) && (hours < 24) &&
            (minutes >= 0) && (minutes < 60) &&
            (seconds >= 0) && (seconds < 60)) {
            timeValid = true;
        } // time validated
        else {
            cout << "ERROR - Invalid time entered - Please try again" << endl;
        }
    }
}
void GetConsoleSize(int& columns, int& rows) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
int printMenu() {
    const int menuWidth = 26;        //used to define menu character width
    int columns=80;
    int rows = 40;

    vector<string> menuOption= {"","1- Add One Hour","",
                                   "2- Add One Minute","",
                                   "3- Add One Second","",
                                   "4- Exit Program","" };
    GetConsoleSize(columns, rows);
    //confirm width is sufficient for proper display
    if (columns < (menuWidth)) {
        std::cout << " ERROR - Console width is too small to display properly" << endl;
        return -1;
    }
    //confirm height is sufficient for proper display
    if (rows < menuOption.size()) {
        std::cout << " ERROR - Console height is too small to display properly" << endl;
        return -1;
    }

    //checks have passed, show the menu!
    std::cout << endl;  // just to be sure we start on a clean row
    int startPoint = columns/2 - (menuWidth / 2); //helps to center the menu
    menuOption[0] = nCharString(startPoint, ' ') + "**"                 + nCharString((menuWidth - (menuOption[0]).length()-2), '*') + nCharString(1, '*');
    menuOption[1] = nCharString(startPoint, ' ') + "* " + menuOption[1] + nCharString((menuWidth - (menuOption[1]).length()-2), ' ') + nCharString(1, '*');
    menuOption[2] = nCharString(startPoint, ' ') + "  "                 + nCharString((menuWidth - (menuOption[2]).length()-2), ' ') + nCharString(1, ' ');
    menuOption[3] = nCharString(startPoint, ' ') + "* " + menuOption[3] + nCharString((menuWidth - (menuOption[3]).length()-2), ' ') + nCharString(1, '*');
    menuOption[4] = nCharString(startPoint, ' ') + "  "                 + nCharString((menuWidth - (menuOption[4]).length()-2), ' ') + nCharString(1, ' ');
    menuOption[5] = nCharString(startPoint, ' ') + "* " + menuOption[5] + nCharString((menuWidth - (menuOption[5]).length()-2), ' ') + nCharString(1, '*');
    menuOption[6] = nCharString(startPoint, ' ') + "  "                 + nCharString((menuWidth - (menuOption[6]).length()-2), ' ') + nCharString(1, ' ');
    menuOption[7] = nCharString(startPoint, ' ') + "* " + menuOption[7] + nCharString((menuWidth - (menuOption[7]).length()-2), ' ') + nCharString(1, '*');
    menuOption[8] = nCharString(startPoint, ' ') + "**"                 + nCharString((menuWidth - (menuOption[8]).length()-2), '*') + nCharString(1, '*');
    
   for (int i = 0; i < menuOption.size(); ++i) {
        std::cout << menuOption[i] << endl;
    }    
    return 0;
}
int GetUserMenuSelection() {
    bool selectionValid = false;
    int selection;
   
    while (selectionValid == false) {
      printMenu();
      while (!(cin >> selection)) {//this will be true if an error occurs. It could be while( cin.fail() )
                                                       //but then you'd have to add the actual input
        string str;
        cin.clear();//you need to clear the flags before input
        getline(cin, str);//read what was written. Since you probably don't need this, look into cin.ignore()
        std::cout << str << " is not a number\n" << endl;

        std::cout << "Please re-enter the selection using a number" << endl;
        printMenu();
      } //CIN data type check

      //user has entered a number, decide if its valid
    
    
      switch (selection) {
      case 1: {
          AddTimeHours();
          selectionValid = true;
          break; 
      }
        case 2: {
            AddTimeMinutes();
            selectionValid = true;
            break;
        }
        case 3: {
            AddTimeSeconds();
            selectionValid = true;
            break;
        }
        case 4: {
            selectionValid = true;
            return -1;
            break;
        }
        default: {
          std::cout << "ERROR - Invalid menu selection, please try again" << endl;
          //DisplayMenu();
          break;
         } //default

      }//switch (selection)


    } //while (selectionValid == false) {
    return 0;
}
int DisplayClocks() {
    const int time24DispWidth = 26;  // from the sample in the requirements
    const int time12DispWidth = 26;  // from the sample in the requirements
    const int clocksCenterPad = 6;   // unable to confirm, visual estimate

    int columns = 80;
    int rows = 40;
    GetConsoleSize(columns, rows);

    //confirm width is sufficient for proper display
    if (columns < (time24DispWidth + time12DispWidth + clocksCenterPad)) {
        std::cout << " ERROR - Console width is too small to display properly" << endl;
        return -1;
    }
    //confirm height is sufficient for proper display
    if (rows < 6) {
        std::cout << " ERROR - Console height is too small to display properly" << endl;
        return -1;
    }

    // display sizes have passed checks.

    std::cout << endl;  // just to be sure we start on a clean row
    int startPoint = columns / 2 - (clocksCenterPad / 2) - (time24DispWidth + time12DispWidth)/2; //helps to center the menu
    //string padLeft = "";
    //string banner12, banner24,centerPad = "";

    //display the banner row
    //padLeft   = nCharString(startPoint-1, ' ');                 //pad left setup
    //banner12  = nCharString(time12DispWidth, '*');              // top and bottom char banner
    //banner24  = nCharString(time24DispWidth, '*');              // top and bottom char banner
    //centerPad = nCharString(clocksCenterPad, ' ');              // space between the clocks

    /**********************************************************************
    *
    *
    *     Display opening format Banner
    *
    *
    **********************************************************************/

    /******************* first row is asterisk banners********************/
    std::cout << nCharString(startPoint - 1, ' ') << nCharString(time24DispWidth, '*') << nCharString(clocksCenterPad, ' ') << nCharString(time12DispWidth, '*') << endl;
   
    
    /******************* SECOND row is format declarations****************/
    const string timeFormat12 = "12-Hour Clock";
    const string timeFormat24 = "24-Hour Clock";
    //calculate the clock format padding
    int timeFormat12Padding = ((time12DispWidth - timeFormat12.size()) / 2) - 1;  //center the text
    int timeFormat24Padding = ((time24DispWidth - timeFormat24.size()) / 2) - 1;  //center the text


    // DESIGN NOTE: the following block of code could be moved to a function, but left here as it helps 
    // with sequential flow readability without needing to jump around in the code during development

    // prepare the 12 hour time format text for display
    string timeFormat12String = "*";
    timeFormat12String += nCharString(timeFormat12Padding, ' ');  // pad text left
    timeFormat12String += timeFormat12;  // insert the format declaration string
    timeFormat12String += nCharString(timeFormat12Padding + ((time12DispWidth - timeFormat12.size()) % 2), ' '); // pad right
    timeFormat12String += "*";

    // prepare the 24 hour time format text for display
    string timeFormat24String = "*";
    timeFormat24String += nCharString(timeFormat24Padding, ' ');  // pad text left
    timeFormat24String += timeFormat24;  // insert the format declaration string
    timeFormat24String += nCharString(timeFormat24Padding + ((time24DispWidth - timeFormat24.size()) % 2), ' '); // pad right
    timeFormat24String += "*";

    // display the formatting row
    std::cout << nCharString(startPoint - 1, ' ') << timeFormat12String << nCharString(clocksCenterPad, ' ') << timeFormat24String <<endl;



    /********************************************************************** 
    *
    *
    *     prepare the 12 hour time format text for display 
    *
    *
    **********************************************************************/
    //format as 2 digits
    string hours12Str = twoDigitString(hours % 12);

    string time12String = "*";
    //calculate the padding for pretty printing
    timeFormat12Padding = ((time12DispWidth - formatTime12(hours,minutes,seconds).size()-1) / 2);
    //left pad the time
    time12String += nCharString(timeFormat12Padding + ((time12DispWidth - timeFormat12.size()-1) % 2), ' '); 
    // add the formatted time string
    time12String += formatTime12(hours, minutes, seconds);
    // right pad the time
    time12String += nCharString(timeFormat12Padding + ((time12DispWidth - timeFormat12.size() - 1) % 2), ' ');
    time12String += "*";

    /**********************************************************************
    *
    *
    *     prepare the 24 hour time format text for display
    *
    *
    **********************************************************************/
    string time24String = "*"; 

    //calculate the padding for pretty printing
    timeFormat24Padding = ((time24DispWidth - formatTime24(hours, minutes, seconds).size() - 1) / 2);
    //left pad the time
    time24String += nCharString(timeFormat24Padding + ((time24DispWidth - timeFormat24.size() - 1) % 2), ' ');
    // add the formatted time string
    time24String += formatTime24(hours, minutes, seconds);
    // right pad the time
    time24String += nCharString(timeFormat24Padding + ((time24DispWidth - timeFormat24.size() - 1) % 2), ' ');
    time24String += "*";

    /**********************************************************************
    *
    *
    *     Display the formatted time
    *
    *
    **********************************************************************/

    /******************* THIRD row is formatted time**********************/
    std::cout << nCharString(startPoint - 1, ' ') << time12String << nCharString(clocksCenterPad, ' ') << time24String<< endl;

    
    /**********************************************************************
    *
    *
    *     Display closing format Banner
    *
    *
    **********************************************************************/

    /******************* FOURTH row is asterisk banners*******************/
    std::cout << nCharString(startPoint - 1, ' ') << nCharString(time24DispWidth, '*') << nCharString(clocksCenterPad, ' ') << nCharString(time12DispWidth, '*') << endl <<endl<<endl;

    return 0;
}



//void main()
int main() // changed type to int per compiler warning
{
    // init, get the current time
    TimeInit();
    DisplayClocks();
    // time has been entered successfully
    while (GetUserMenuSelection() != -1) {
        DisplayClocks();
    }
}

