/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Todd Yezak
* UNT Email: todd.yezak@my.unt.edu
* Date submitted:4/25/22
*File name: patrons.cpp
*Description: cpp file to be able to add multiple patrons in the system
*/

#include "patron.h"
#include "patrons.h"
#include <fstream>
#include <iterator>
using namespace std;

int patrons::getpcount() 
{ 
	return patcount;
}

void patrons::incpcount() 
{
	patcount++;
}

void patrons::decpcount() 
{ 
	patcount--;
}


void patrons::addpatron() {
	
	int id;
	string tem;
	patron temp;
	float balance = 0.0;
	int booksout = 0;
	
	cout << "Create new ID for patron: ";
	cin >> id;
	temp.setpid(id);
	cin.ignore();
	
	cout << "Enter name of new patron: ";
	getline(cin, tem);
	temp.setpname(tem);
	temp.setpbalance(balance);
	temp.setpbout(booksout);
	
	patronlist.push_back(temp);
	incpcount();
}

void patrons::editpatron() {
	int numofbook = 0;
	int id;
	int tempid;
	int tempbook;
	int tempday;
	float tempbalance;
	
	int num;
	string tempname;
	patron temp;
	char choice;
	
	cout << "Enter the id of the patron would like to edit: " << endl;
	cin >> id;
	
	for (unsigned int i=0; patronlist.size(); i++)
	{
		if(id == patronlist.at(i).getpid())
		{
			cout << "What do you want to edit: " << endl;
			cout << "\t 1. name" << endl;
			cout << "\t 2. ID" << endl;
			cout << "\t 3. balance" << endl;
			cout << "\t 4. number of books out" << endl;
			cin >> num;
			cin.ignore();
			
			if(num == 1)
			{
				cout << "Enter new name" << endl;
				getline(cin,tempname);
				patronlist.at(i).setpname(tempname);
				cout <<  "New name added." << endl;
			}
			if(num == 2)
			{
				cout << "Enter new id:" << endl;
				cin >> tempid;
				patronlist.at(i).setpid(tempid);
				cout << "New id added." << endl;
			}
			if(num == 3)
			{
				cout << "How many books out?" << endl;
				cin >> tempbook;
				
				cout << "How manys days checked out?";
				cin >> tempday;
				
				tempbalance = tempbook * (tempday * 0.25);
				patronlist.at(i).setpbalance(tempbalance);
				cout << "Balance updated." << endl;
			}
			
			if(num == 4)
			{
				cout << "Did patron check out book(y or n)?" << endl;
				cin >> choice;
	
				if(choice == 'y'){
					if(numofbook <= 6){
						numofbook++;
					}
					else 
					{
						cout << "Can not check out anymore books " << endl;
					}
				}
				if(choice == 'n'){
					cout << "Patron returned book" << endl;
					numofbook--;
				}
					patronlist.at(i).setpbout(numofbook);
			}
		}
		
	}
}

void patrons::deletepatron()
{
   unsigned i = 0;
   unsigned posItem;
   unsigned patronSize;
   bool found;
   int tempid;

   posItem = 0;
   patronSize = patronlist.size();
   found = false;
   
   cout << "Enter id of patron you would like to delete:" << endl;
   cin >> tempid;

   for(i = 0; i < patronSize; ++i) 
	{
      		if(patronlist.at(i).getpid() == tempid && i != (patronSize - 1)) 
		{
			found = true;
			patronlist.at(i) = patronlist.at(i+1);
			posItem = i;			
			cout << "Patron removed" << endl;
		}
	  	if(i > posItem && i != (patronSize - 1) && found)
		{
		  patronlist.at(i) = patronlist.at(i+1);
	  	}
   	}
   patronlist.resize(patronSize - 1);
   decpcount();
}

void patrons::srchpatron()
{
	int tempid;
	cout << "Enter id of patron you would like to search:" << endl;
	cin >> tempid;

	patron temp;
	for(unsigned i = 0; i < patronlist.size(); i++)
	{
		if(patronlist.at(i).getpid() == tempid)
		{
			cout << "patron id: " << patronlist.at(i).getpid() << " patron name: " << patronlist.at(i).getpname() << " patron balance " << patronlist.at(i).getpbalance() << " patron books checked out " << patronlist.at(i).getpbout() <<endl;

		}
	}
	
}


void patrons::prtpatrons()
{
	
    for (auto it = patronlist.begin(); it !=patronlist.end(); ++it)
    {
        
        cout << "Patron id: " << it->getpid() << " Patron name: " << it->getpname() <<endl;
    }
}


void patrons::prtone()
{

	int id;
	patron temp;
	cout << "Enter the id of the patron you would like to print: " << endl;
	cin >> id;
	for(unsigned i = 0; i < patronlist.size(); i++)
	{
		if(patronlist.at(i).getpid() == id)
		{
			cout << "patron id: " << patronlist.at(i).getpid() << " patron name: " << patronlist.at(i).getpname() << " patron balance " << patronlist.at(i).getpbalance() << " patron books checked out " << patronlist.at(i).getpbout() <<endl;
		}
	}
}

void patrons::payfines()
{
	int numobooks;
	int id;
	patron temp;
	float balance;
	
	cout << "Enter the id of the patron you would like to find the balance of: " << endl;
	cin >> id;
	for(unsigned i = 0; i < patronlist.size(); i++)
	{
		if(patronlist.at(i).getpid() == id)
		{
			balance = patronlist.at(i).getpbalance();
			numobooks = patronlist.at(i).getpbout();
			balance = (0.25 * 10) * numobooks;
		}
		cout << "Balance due: " << balance << endl;
	
	}
}
	
	
void patrons::loadpatron()
{
    int patcount;
    ofstream fout;
    fout.open("patrons.dat");
    fout << patcount << endl;
    
       for (auto it = patronlist.begin(); it !=patronlist.end(); ++it)
    {
        fout << it->getpid() << " " <<  it->getpname() << " " << it->getpbalance() << " " << it->getpbout() << endl;
    }
    fout.close();
}



void patrons::storepatron()
{

    ifstream fin;
	int id;
	string name;
	float balance;
	int booksout;
	int patcount;
   
	fin.open("patrons.dat");
	fin >> patcount; fin.ignore();
    
    for ( int i=0; i < patcount; i++)
    {
        
        fin >> id >> name >> balance >> booksout;
        patronlist.push_back(patron(id,name,balance,booksout));
    }

    fin.close();
}

void patrons::cleanup()
{
	for (auto it = patronlist.begin(); it != patronlist.end(); ++it)
	{
        	patronlist.erase(it);
	}
    
	patronlist.clear();
}


