/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Todd Yezak
* UNT Email: todd.yezak@my.unt.edu
* Date submitted:4/25/22
*File name: loans.h
*Description: header file to be able to add multiple loans in the system
*/

#ifndef LOANS_H
#define LOANS_H

#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;

class loans
{
	public:
		
		void addloan();
		void delloan();
		void prntovrdue();
		void prntpatlist();
		void recheck();
		void editloan();
		void lost();
		void loadloan();
		void storeloan();
		int getlcount();
		void inclcount();
		void declcount();
		void cleanup();
		
	private:
	
		int loancount;
	
		vector<loan> loanlist;
	
	
	
};

#endif	