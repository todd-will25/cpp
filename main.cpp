/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Todd Yezak
* UNT Email: todd.yezak@my.unt.edu
* Date submitted:4/25/22
*File name: main.cpp
*Description: menu to navigate and do all the processes 
*/

#include <stdio.h>
#include <iostream>
#include <string>

#include "patron.h"
#include "book.h"
#include "loan.h"
#include "patrons.h"
#include "books.h"
#include "loans.h"
using namespace std;

patrons patro;
books book;
loans loan;

int main() 
{
	
	int choice;
	int num;
	int tempid;
	
	patro.loadpatron();
	book.loadbook();
	loan.loadloan();
	
	while(choice != 0)
	{
		cout << "1. patron" << endl;
		cout << "2. book" << endl;
		cout << "3. loan" << endl;
		cout << "0. Quit" << endl;
		cin >> choice;
	
		switch(choice)
		{
			
			case 1:
				cout << "1: add patron" << endl;
				cout << "2: delete patron" << endl;
				cout << "3: edit patron" << endl;
				cout << "4: search patron" << endl;
				cout << "5: print patrons" << endl;
				cout << "6: print one patron" << endl;
				cout << "7: pay fines for patron" << endl;
				cin >> num;
				
				if(num == 1)
				{
					patro.addpatron();
				}
				
				if(num == 2)
				{
								
					patro.deletepatron();
				}
				
				if(num == 3)
				{
					patro.editpatron();
				}
				
				if(num == 4)
				{
					patro.srchpatron();
				}
				
				if(num == 5)
				{
					patro.prtpatrons();

				}
				
				if(num == 6)
				{
					patro.prtone();
				}
				
				if(num == 7)
				{
					patro.payfines();	
				}
				
				break;
			
			case 2: 
			
				cout << "1: add book" << endl;
				cout << "2: delete book" << endl;
				cout << "3: edit book" << endl;
				cout << "4: search books" << endl;
				cout << "5: print books" << endl;
				cout << "6: print one book" << endl;
				cin >> num;
				
				if(num == 1)
				{
					book.addbook();
				}
				
				if(num == 2)
				{
					book.editbook();
				}
				
				if(num == 3)
				{
					book.delbook();
				}
				
				if(num == 4)
				{
					book.srchbook();
				}
				
				if(num == 5)
				{
					book.prntbklist();
				}
				
				if(num == 6)
				{
					book.prntbook();
				}
			
			break;
		
			
			case 3:
			
				cout << "1: add loan" << endl;
				cout << "2: delete loan" << endl;
				cout << "3: edit loan" << endl;
				cout << "4: print overdue" << endl;
				cout << "5: recheck" << endl;
				cout << "6: print list" << endl;
				cout << "7: report lost" << endl;

				cin >> num;
				
				if(num == 1)
				{
					loan.addloan();

				}
				
				if(num == 2)
				{
					loan.delloan();
				}
				
				if(num == 3)
				{
					loan.editloan();
				}
				
				if(num == 4)
				{
					loan.prntovrdue();
				}
				
				
				if(num == 5)
				{
					loan.recheck();
				}
				
				if(num == 6)
				{
					loan.prntpatlist();
	
				}

				if(num == 7)
				{
					loan.lost();
				}
				
				break;
				
				default:
					
				if(num == 0)
				{
					break;
				}	
			
		}
		
	}
	
	patro.storepatron();
	book.storebook();
	loan.storeloan();
	patro.cleanup();
	book.cleanup();
	loan.cleanup();
	
	return 0;
}
	