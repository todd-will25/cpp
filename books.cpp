/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Todd Yezak
* UNT Email: todd.yezak@my.unt.edu
* Date submitted:4/25/22
*File name: books.cpp
*Description: cpp file to be able to add multiple books in the system
*/

#include "book.h"
#include "books.h"
#include <iterator>
#include <fstream>


int books::getbcount() 
{ 
	return bookcount;
}

void books::incbcount() 
{
	bookcount++;
}

void books::decbcount() 
{ 
	bookcount--;
}


void books::addbook() {
	string tempauthor;
	string temptitle;
	int tempisbn;
	int id;
	int tempid;
	float tempcost;
	string tempstatus;
	book temp;
	cin.ignore();
	
	cout << "Enter book's author" << endl;
	getline(cin,tempauthor);
	temp.setbauthor(tempauthor);
	
	cout << "Enter book's title:" << endl;
	getline(cin, temptitle);
	temp.setbtitle(temptitle);
	
	cout << "Enter book's isbn" << endl;
	cin >> tempisbn;
	temp.setbisbn(tempisbn);

	cout << "Enter book's id" << endl;
	cin >> tempid;
	temp.setbid(tempid);

	cout << "Enter book's cost" << endl;
	cin >> tempcost;
	temp.setbcost(tempcost);
	cin.ignore();
	cout << "Enter book's status(in or out)" << endl;
	getline(cin, tempstatus);
	temp.setbstatus(tempstatus);

	booklist.push_back(temp);
	incbcount();
	
}
	


void books::editbook() {
	
	
	string tempauthor;
	string temptitle;
	int tempisbn;
	int id;
	int tempid;
	float tempcost;
	string tempstatus;
		
	int num;
	
	book temp;
	
	cout << "Enter the id of the book would like to edit: " << endl;
	cin >> id;
	
	for (unsigned int i=0; booklist.size(); i++)
	{
		if(id == booklist.at(i).getbid())
		{
			cout << "What do you want to edit: " << endl;
			cout << "\t 1. author" << endl;
			cout << "\t 2. title" << endl;
			cout << "\t 3. isbn" << endl;
			cout << "\t 4. ID" << endl;
			cout << "\t 5. Cost" << endl;
			cout << "\t 6. Status" << endl;
			
			cin >> num;
			cin.ignore();
			
			if(num == 1)
			{
				cout << "Enter new author" << endl;
				getline(cin,tempauthor);
				booklist.at(i).setbauthor(tempauthor);
				cout <<  "New name updated." << endl;
			}
			if(num == 2)
			{
				cout << "Enter new title:" << endl;
				getline(cin, temptitle);
				booklist.at(i).setbtitle(temptitle);
				cout << "New title updated." << endl;
			}
			if(num == 3)
			{
				cout << "Enter new isbn" << endl;
				cin >> tempisbn;
				booklist.at(i).setbisbn(tempisbn);
				cout << "New isbn updated" << endl;
			}
			
			if(num == 4)
			{
				cout << "Enter new id" << endl;
				cin >> tempid;
				booklist.at(i).setbid(tempid);
				cout << "New id updated" << endl;
			}
			if(num == 5)
			{
				cout << "Enter new cost" << endl;
				cin >> tempcost;
				booklist.at(i).setbcost(tempcost);
				cout << "New cost updated" << endl;
			}
			if(num == 6)
			{
				cout << "Enter new status(checked in or out)" << endl;
				getline(cin, tempstatus);
				booklist.at(i).setbstatus(tempstatus);

				cout << "New status updated" << endl;
			}
		
		}
	}
}


void books::delbook() {
	
   unsigned i = 0;
   unsigned posItem;
   unsigned bookSize;
   bool found;
   int tempid;

   posItem = 0;
   bookSize = booklist.size();
   found = false;
   
   cout << "Enter id of book you would like to delete:" << endl;
   cin >> tempid;

   for(i = 0; i < bookSize; ++i) 
	{
      		if(booklist.at(i).getbid() == tempid && i != (bookSize - 1)) 
		{
			found = true;
			booklist.at(i) = booklist.at(i+1);
			posItem = i;			
			cout << "book removed" << endl;
		}
	  	if(i > posItem && i != (bookSize - 1) && found)
		{
		  booklist.at(i) = booklist.at(i+1);
	  	}
   	}
   booklist.resize(bookSize - 1);
   decbcount();
		
 
}

void books::srchbook() { 
	int num;
	cout << "Enter book you want to search for: " << endl;
	cin >> num;
	
	for(unsigned i = 0; i < booklist.size(); i++)
	{
		if(booklist.at(i).getbid() == num)
		{
			cout << "Book: " << booklist.at(i).getbtitle() << " " << "Author: " << booklist.at(i).getbauthor() << endl;
		}
	}
	
}


void books::prntbklist() {
	
    for (auto it = booklist.begin(); it !=booklist.end(); ++it)
    {
       
        cout << "Book id: " << it->getbid() << " Book author: " << it->getbauthor();
		cout << " Book title: " << it->getbtitle() << " Book isbn: " << it->getisbn();
		cout << " Book cost: " << it->getbcost() << " Book status: " << it->getbstatus() <<endl;
    }

}

void books::prntbook() {
	int id;
	cout << "Enter the id of the book you would like to print: " << endl;
	cin >> id;
	for(unsigned i = 0; i < booklist.size(); i++)
	{
		if(booklist.at(i).getbid() == id)
		{
			cout << "Book author: " << booklist.at(i).getbauthor() << " Book title: " << booklist.at(i).getbtitle() << " Book isbn: " << booklist.at(i).getisbn() << " Book cost: " << booklist.at(i).getbcost() << " Book status: " << booklist.at(i).getbstatus() <<endl;
		}
	}
}

void books::loadbook()
{
    int bookcount;
    ofstream fout;
    fout.open("books.dat");
    fout << bookcount << endl;
    
    for (auto it = booklist.begin(); it !=booklist.end(); ++it)
    {
        fout << it->getbauthor() << " " <<  it->getbtitle() << " " << it->getisbn() << " " << it->getbid() << " " << it->getbcost() << " " << it->getbstatus() << endl;
    }
    fout.close();
}



void books::storebook()
{

    ifstream fin;
	int id;
	string author;
	float cost;
	string title;
	int isbn;
	string status;
	int bookcount;
	
    fin.open("books.dat");
	fin >> bookcount; fin.ignore();
    
    for ( int i=0; i < bookcount; i++)
    {
        
        fin >> author >> title >> isbn >> id >> cost >> status;
        booklist.push_back(book(author, title, isbn, id, cost, status));
    }

    fin.close();
}

void books::cleanup()
{
	for (auto it = booklist.begin(); it !=booklist.end(); ++it)
	{
        	booklist.erase(it);
	}
    booklist.clear();
}