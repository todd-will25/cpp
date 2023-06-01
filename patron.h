/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Todd Yezak
* UNT Email: todd.yezak@my.unt.edu
* Date submitted:4/25/22
*File name: patron.h
*Description: header file of inputting one patron
*/

#ifndef PATRON_H
#define PATRON_H


#include <iostream>
#include <string>
using namespace std;

class patron
{
	
	
	public:
		patron();
		patron(int id, string name, float balance, int booksout);
		string getpname();
		int getpid();
		float getpbalance();
		int getpbout();
		void setpname(string name);
		void setpid(int id);
		void setpbalance(float balance);
		void setpbout(int booksout);
	
	private:
		string patname;
		int pid;
		float pbalance;
		int pbout;
		
	
	
};

#endif