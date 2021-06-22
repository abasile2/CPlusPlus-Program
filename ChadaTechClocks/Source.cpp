#include <iostream>
#include <iomanip> // gets setw() and setfill() function
using namespace std;

void DisplayTime(int hour1, int hour2, int minute, int second) { // function to use to display time

	// creates the top border
	cout << setw(27) << setfill('*') << " ";
	cout << "    ";
	cout << setw(27) << setfill('*') << " " << endl;

	// displays the time format above the clock
	cout << "*     " << "12-Hour Clock" << "      *";
	cout << "     ";
	cout << "*     " << "24-Hour Clock" << "      *" << endl;

	// this is the 12 hour time format using the first parameter
	cout << "*      " << setw(2) << setfill('0') << hour1 << ":";
	cout << setw(2) << setfill('0') << minute << ":";
	cout << setw(2) << setfill('0') << second << " PM       *";
	cout << "     ";

	// this is the 24 hour time format using the second parameter
	cout << "*       " << setw(2) << setfill('0') << hour2 << ":";
	cout << setw(2) << setfill('0') << minute << ":";
	cout << setw(2) << setfill('0') << second << "         *" << endl;

	// bottom border
	cout << setw(27) << setfill('*') << " ";
	cout << "    ";
	cout << setw(27) << setfill('*') << " " << endl;
}

void ClearScreen() { // clears the screen
	system("CLS");
}

void DisplayMenu(int menuNumber) { // function to display menu when user inputs 'y' for yes

	// used and declared variables to create fake time below
	int newHour12 = 3;
	int newHour24 = 15;
	int newMinute = 22;
	int newSecond = 1;

	int newTime = 0;
	int newTime12 = 0;
	int newTime24 = 0;

	// attempt to get user input number and have each add 1 for hour, minute, or second
	// 1 to add an hour
	if (menuNumber == 1) {
		newTime12 = newHour12 + 1; // 1 to add an hour
		newTime24 = newHour24 + 1;

		if (newTime12 > 12) { // rolls over from 12 to 1
			newTime12 = 1;
		}

		if (newTime24 > 23) { // rolls over from 23 to 0
			newTime24 = 0;
		}

		DisplayTime(newTime12, newTime24, newMinute, newSecond);
		cout << endl;
	}

	// 2 to add a minute
	else if (menuNumber == 2) {
		newTime = newMinute + 1;

		if (newTime > 59) { // rolls over from 59 to 0
			newTime = 0;
		}

		DisplayTime(newHour12, newHour24, newTime, newSecond);
		cout << endl;
	}

	// 3 to add a second
	else if (menuNumber == 3) {
		newTime = newSecond + 1;

		if (newTime > 59) { // rolls over from 59 to 0
			newTime = 0;
		}

		DisplayTime(newHour12, newHour24, newMinute, newTime);
		cout << endl;
	}

	// 4 to exit program
	else if (menuNumber == 4) {
	}

	cout << endl; // newline for readability
}

void main() {
	// used and declared variables below to create the original time before the adjustment
	int displayHH12 = 3;
	int displayHH24 = 15;
	int displayMM = 22;
	int displaySS = 1;

	DisplayTime(displayHH12, displayHH24, displayMM, displaySS); // display time in 12 hour format
	cout << endl << endl;

	char displayMenu = 'y';

	// get user input if needed but not for this assignment

	if (displayMenu == 'y') { // automatic yes because displayMenu matches the char above
		int selectNum = 0;

		// below creates a border and the menu
		cout << setw(27) << setfill('*') << " " << endl;
		cout << "* 1 - Add One Hour       *" << endl << endl;
		cout << "* 2 - Add One Minute     *" << endl << endl;
		cout << "* 3 - Add One Second     *" << endl << endl;
		cout << "* 4 - Exit Program       *" << endl;
		cout << setw(27) << setfill('*') << " " << endl << endl;

		cin >> selectNum;

		DisplayMenu(selectNum); // attempt to receive function to change the time
	}

	system("Pause"); // this gives the program time to wait before clearing the screen
	ClearScreen();
}