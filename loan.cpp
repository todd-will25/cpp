/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Todd Yezak
* UNT Email: todd.yezak@my.unt.edu
* Date submitted:4/25/22
*File name: loan.cpp
*Description: cpp file to set one loan in the system
*/

#include "loan.h"

loan::loan()
{
	lid = 0;
	booklid = 0;
	patronlid = 0;
	currstatus = "n/a";
	loanmonth = 0;
	loanday = 0;
	loanyear = 0;
	loanhour = 0;
	loanminute = 0;
}


loan::loan(int loanid, int bookid, int patronid, string status, int month, int day, int year, int hour, int minute) 
{
	lid = loanid;
	booklid = bookid;
	patronlid = patronid;
	currstatus = status;
	loanmonth = month;
	loanday = day;
	loanyear = year;
	loanhour = hour;
	loanminute = minute;
}

int	loan::getlid()
{
	return lid;
}

int loan::getbooklid()
{
	return booklid;
}

int loan::getpatronlid()
{
	return patronlid;
}


string loan::getcurrstatus()
{
	return currstatus;
}

int loan::getmonth()
{
	return loanmonth;
}

int loan::getday()
{
	return loanday;
}

int loan::getyear()
{
	return loanmonth;
}

int loan::gethour()
{
	return loanhour;
}

int loan::getminute()
{
	return loanminute;
}

void loan::setmonth(int month)
{
	loanmonth = month;
}

void loan::setday(int day){
	loanday = day;
}

void loan::setyear(int year) {
		loanyear = year;
}

void loan::sethour(int hour) {
		loanhour = hour;
}

void loan::setminute(int minute) {
	loanminute = minute;
}

void loan::setlid(int loanid)
{
	lid = loanid;
}

void loan::setbooklid(int bookid)
{
	booklid = bookid;
}

void loan::setcurrstatus(string status)
{
	currstatus = status;
}

void loan::setpatronlid(int patronid)
{
	patronlid = patronid;
}