#include <iostream>
#include <string>
#include "AirgeadBank.h"
using namespace std;

// setter and getter funcitons
void BankApp::SetInitialAmt(double setAmt) {
	initialAmt = setAmt;
}

double BankApp::GetInitialAmt() const {
	return initialAmt;
}

void BankApp::SetMonthlyAmt(double setMonthlyAmt) {
	monthlyAmt = setMonthlyAmt;
}

double BankApp::GetMonthlyAmt() const {
	return monthlyAmt;
}

void BankApp::SetInterest(double setInterest) {
	interest = setInterest;
}

double BankApp::GetInterest() const {
	return interest;
}

void BankApp::SetYear(int setYear) {
	year = setYear;
}

int BankApp::GetYear() const {
	return year;
}

int BankApp::PrintYear(int numYear) {
	int year;
	for (int i = 1; i <= numYear; ++i) {
		year = i;
	}
	return year; // attempted to print out each year 
}

double BankApp::CalculateYearEndBalance(double setAmt1, double setInterest1, double amtPerMonth) {
	// since it can only return one value, output initialAmt aka the year end balance
	double closing = 0.0;
	double totalInterest = 0.0;
	double initialAmt = setAmt1;
	double monthlyAmt = amtPerMonth;
	double interest = setInterest1;

	for (int i = 1; i <= 12; ++i) {
		double total = initialAmt + monthlyAmt;
		double interestRate = total * ((interest / 100) / 12);
		closing = total + interestRate;

		initialAmt = closing;

		totalInterest += interestRate;
	}

	return initialAmt;
}

double BankApp::CalculateYearEndInterest(double setAmt1, double setInterest1, double amtPerMonth) {
	// attempted to print year end earned interest 
	double closing = 0.0;
	double totalInterest = 0.0;
	double initialAmt = setAmt1;
	double monthlyAmt = amtPerMonth;
	double interest = setInterest1;

	for (int i = 1; i <= 12; ++i) {
		double total = initialAmt + monthlyAmt;
		double interestRate = total * ((interest / 100) / 12);
		closing = total + interestRate;

		initialAmt = closing;

		totalInterest += interestRate;
	}

	return totalInterest;
}