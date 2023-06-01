/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Todd Yezak
* UNT Email: todd.yezak@my.unt.edu
* Date submitted:4/25/22
*File name: book.h
*Description: header file to set one book in the system
*/

#ifndef BOOK_H
#define BOOK_H


#include <iostream>
#include <string>
using namespace std;

class book
{
	
	
	
	public:
		book();
		book(string author, string title, int isbn, int id, float cost, string status);
		string getbauthor();
		string getbtitle();
		int getisbn();
		int getbid();
		float getbcost();
		string getbstatus();
		void setbauthor(string author);
		void setbtitle(string title);
		void setbisbn(int isbn);
		void setbid(int id);
		void setbcost(float cost);
		void setbstatus(string status);
	
	
	private:
		string bauthor;
		string btitle;
		int bisbn;
		int bid;
		float bcost;
		string bstatus;
	
	
};
#endif