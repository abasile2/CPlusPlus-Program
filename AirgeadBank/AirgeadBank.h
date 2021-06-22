#ifndef AIRGEADBANK_H
#define AIRGEADBANK_H

class BankApp {
public: // several different functions
	void SetInitialAmt(double setAmt);
	double GetInitialAmt() const;

	void SetMonthlyAmt(double setMonthlyAmt);
	double GetMonthlyAmt() const;

	void SetInterest(double setInterest);
	double GetInterest() const;

	void SetYear(int setYear);
	int GetYear() const;
	// to print out each year
	int PrintYear(int numYear);

	// to get calculations for year end balance
	double CalculateYearEndBalance(double setAmt1, double setInterest1, double amtPerMonth);
	
	// to get calculations for year end earned interests
	double CalculateYearEndInterest(double setAmt1, double setInterest1, double amtPerMonth);

private:
	double initialAmt;
	double monthlyAmt;
	double interest;
	int year;
};

#endif
