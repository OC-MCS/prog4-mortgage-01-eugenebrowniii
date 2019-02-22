
// main goes here. Code that *uses* the Mortgage class
// goes in this file

#include <iostream>
#include <string>
#include <iomanip>
#include "Mortgage.h"

using namespace std;

int main()
{
	Mortgage mtg;

	mtg.setLoan();
	mtg.setInterestRate();
	mtg.setYears();

	cout << setprecision(2) << fixed;
	cout << "\nMonthly payment to bank: $";
	cout << mtg.getMonthlyPayment();

	cout << "\nTotal paid to bank at the end of period: $";
	cout << mtg.getTotalPaid();

	return 0;

}