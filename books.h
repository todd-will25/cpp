/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Todd Yezak
* UNT Email: todd.yezak@my.unt.edu
* Date submitted:4/25/22
*File name: book.h
*Description: header file to be able to add multiple books in the system
*/

#ifndef BOOKS_H
#define BOOKS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
using namespace std;

using namespace std;

class books
{
	public:
		
		void addbook();
		void editbook();
		void delbook();
		void srchbook();
		void prntbklist();
		void prntbook();
		void loadbook();
		void storebook();
		int getbcount();
		void incbcount();
		void decbcount();
		void cleanup();
	
	private:
	
		int bookcount;
	
		vector<book> booklist;
	
	
	
};
#endif	