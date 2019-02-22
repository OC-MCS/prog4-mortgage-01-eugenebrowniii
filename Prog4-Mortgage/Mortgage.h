#pragma once
// header file for Mortgage class
#ifndef MORTGAGE_H
#define MORTGAGE_H

#include <iostream>
#include <cmath>

using namespace std;

class Mortgage {
private:
	double loan;
	int years;
	double iRate;

	
	double getTerm() const {
		double term;
		term = pow((1 + iRate / 12), (12 * years));
		return term;
	}

public:
	
	Mortgage() {
		loan = 0;
		years = 0;
		iRate = 0;
	}

	//user sets the amount of loan
	void setLoan() {
		double l;
		cout << "Enter amount of loan in $: ";
		cin >> l;
		//validate input
		while (l < 0) {
			cout << "Negative numbers for loans are not";
			cout << " accepted. Enter again: ";
			cin >> l;
		}
		loan = l;
	}
	//user sets the interest rate
	void setInterestRate() {
		double r;
		cout << "Enter interest rate: ";
		cin >> r;
		iRate = r;
	}
	//user sets the amount of years
	void setYears() {
		int y;
		cout << "Enter number of years: ";
		cin >> y;
		//validate input
		while (y < 1) {
			cout << "Values less than 1 are not accepted for years. Enter again";
			
			cin >> y;
		}
		years = y;
	}

	
	double getLoan() const {
		return loan;
	}

	int getYears() const {
		return years;
	}

	double getInterestRate() const {
		return iRate;
	}

	//monthly payment is not declared as a member variable, because it may become stale if we forget to update it so, the function is called that calculates it whenever we need to access it
	double getMonthlyPayment() const {
		double payment;
		payment = (loan * iRate * getTerm() / 12) / (getTerm() - 1);
		return payment;
	}
	//total paid to bank is monthly payment
		//times number of months, which in turn
		//is number of years times 12
	double getTotalPaid() const {
		double total;
		
		total = 12 * years * getMonthlyPayment();
		return total;
	}
};

#endif








	

