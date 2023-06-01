/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Todd Yezak
* UNT Email: todd.yezak@my.unt.edu
* Date submitted:4/25/22
*File name: loan.h
*Description: header file to set one loan in the system
*/

#ifndef LOAN_H
#define LOAN_H


#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class loan
{
	
	
	
	public:
		loan();
		loan(int loanid, int bookid, int patronid, string status, int month, int day, int year, int hour, int minute); 
		int getlid();
		int getbooklid();
		int getpatronlid();
		string getcurrstatus();
		int getmonth();
		int getday();
		int getyear();
		int gethour();
		int getminute();
		void setmonth(int month);
		void setday(int day);
		void setyear(int year);
		void sethour(int hour);
		void setminute(int minute);
		void setlid(int loanid);
		void setpatronlid(int patronid);
		void setbooklid(int bookid);
		void setcurrstatus(string status);
		
	
	
	private:
		int lid;
		int booklid;
		int patronlid;
		string currstatus;
		int loanday;
		int loanmonth;
		int loanyear;
		int loanhour;
		int loanminute;
	
	
};
#endif