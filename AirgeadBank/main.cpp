#include <iostream>
#include <string>
#include <iomanip>
#include "AirgeadBank.h"
using namespace std;

int main() {
	BankApp test1; // class

	// variables to hold user input
	double initialAmount; 
	double monthlyAmount;
	double rateInterest;
	int amtYears;

	// tried to create a border
	cout << setw(35) << setfill('-') << " " << endl;
	cout << setw(21) << setfill('-') << "Data Input";
	cout << setw(14) << setfill('-') << " " << endl;

	cout << "Initial Investment Amount: ";
	cin >> initialAmount; // get user input
	cout << "Monthly Deposit: ";
	cin >> monthlyAmount; // get user input
	cout << "Annual Interest: ";
	cin >> rateInterest; // get user input
	cout << "Number of Years: ";
	cin >> amtYears; // get user input
	cout << setw(35) << setfill('-') << " " << endl;

	// attempted to get user input for each one of these to apply to other functions
	test1.SetInitialAmt(initialAmount);
	test1.SetMonthlyAmt(monthlyAmount);
	test1.SetInterest(rateInterest);
	test1.SetYear(amtYears);

	system("Pause"); // "press any key to continue..."
	cout << endl << endl << endl;

	cout << setw(50) << setfill('-') << " " << endl;
	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "Year   Year End Balance   Year End Earned Interest" << endl;
	cout << endl;

	int years = test1.GetYear(); // tried to get user input for the amount of years through setter

	test1.PrintYear(years); // attempted to get the number for each year
	// user input from setter in parameter
	test1.CalculateYearEndBalance(test1.GetInitialAmt(), test1.GetInterest(), 0); // to get year end balance without monthly deposit
	test1.CalculateYearEndInterest(test1.GetInitialAmt(), test1.GetInterest(), 0); // to get year end interest without monthly depost
	system("Pause"); // it kept exiting out before it gets to this point and I am not sure why

	cout << endl << endl << endl;
	cout << setw(50) << setfill('-') << " " << endl;
	cout << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "Year   Year End Balance   Year End Earned Interest" << endl;
	cout << endl;

	test1.PrintYear(years);
	test1.CalculateYearEndBalance(test1.GetInitialAmt(), test1.GetInterest(), test1.GetMonthlyAmt()); // year end balance with monthly deposit
	test1.CalculateYearEndInterest(test1.GetInitialAmt(), test1.GetInterest(), test1.GetMonthlyAmt()); // year interest with monthly deposit

	return 0;
}
