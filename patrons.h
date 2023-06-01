/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Todd Yezak
* UNT Email: todd.yezak@my.unt.edu
* Date submitted: 4/25/22
*File name: patrons.h
*Description: header file to be able to add multiple patrons in the system
*/

#ifndef PATRONS_H
#define PATRONS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>


class patrons
{

	public:
		
		
		void addpatron();
		void editpatron();
		void deletepatron();
		void srchpatron();
		void prtpatrons();
		void prtone();
		void payfines();
		void loadpatron();
		void storepatron();
		int getpcount();
		void incpcount();
		void decpcount();
		void cleanup();
		
	private:
		int patcount;
		vector<patron> patronlist;
	
};
#endif	