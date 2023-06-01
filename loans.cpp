/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Todd Yezak
* UNT Email: todd.yezak@my.unt.edu
* Date submitted:4/25/22
*File name: loans.cpp
*Description: cpp file to be able to add multiple loans in the system
*/

#include "loan.h"
#include "loans.h"
#include <fstream>
#include <iterator>
#include <string>

int loans::getlcount() 
{ 
	return loancount;
}

void loans::inclcount() 
{
	loancount++;
}

void loans::declcount() 
{ 
	loancount--;
}


void loans::addloan() { 
	int id; //loan id
	int id2; //patron id
	int id3;  //book id
	string status;
	int day;
	int month;
	int year;
	int hour;
	int minute;
	loan temp;
	
	cout << "Enter new loan id: " << endl;
	cin >> id;
	temp.setlid(id);
	
	cout << "Enter patron id: " << endl;
	cin >> id2;
	temp.setpatronlid(id2);
	
	cout << "Enter book id: " << endl;
	cin >> id3;
	temp.setbooklid(id3);
	cin.ignore();
	
	cout << "Set status of book: " << endl;
	getline(cin, status);
	temp.setcurrstatus(status);
	
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	cout << "Duedate set: " << endl;
	month = ltm->tm_mon;
	day = ltm->tm_mday + 10;
	year = 1900 + ltm->tm_year;
	hour = 1 + ltm->tm_hour;
	minute = 1 + ltm->tm_min;
	
	temp.setmonth(month);
	temp.setday(day);
	temp.setyear(year);
	temp.sethour(hour);
	temp.sethour(hour);
	temp.setminute(minute);

	loanlist.push_back(temp);
	inclcount();
}

void loans::delloan()
{
    int loa;
    cout << "Enter loan id you would like to delete: " << endl;
    cin >> loa;
    for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    {
        if (it->getlid() == loa)
        {
            loanlist.erase(it);
        }
        
    }
	declcount();
}

void loans::prntovrdue() {
	
	loan temp;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	for(unsigned i = 0; i < loanlist.size(); i++){
		
		if(ltm->tm_mday > loanlist.at(i).getday()){
			
			cout << "Book overdue: " << loanlist.at(i).getbooklid() << endl;
		
		}
	}
}


void loans::prntpatlist()
{

    for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    {

        cout << "Loan id: " << it->getlid() << " Customer id: " << it->getpatronlid() << " book id: " << it->getbooklid() <<endl;
    }
}


void loans::recheck() {
		
	int id;
	int month;
	int day;
	int year;
	int hour;
	int minute;
	
	time_t now = time(0);
	tm *ltm = localtime(&now);
	
	cout << "Enter loan id: " << endl;
	cin >> id;
		
	for(unsigned i = 0; i < loanlist.size(); i++){
		
	if(id == loanlist.at(i).getlid()) {
	
		cout << "Duedate set: " << endl;
		month = ltm->tm_mon;
		day = ltm->tm_mday + 20;
		year = 1900 + ltm->tm_year;
		hour = 1 + ltm->tm_hour;
		minute = 1 + ltm->tm_min;
		
		loanlist.at(i).setmonth(month);
		loanlist.at(i).setday(day);
		loanlist.at(i).setyear(year);
		loanlist.at(i).sethour(hour);
		loanlist.at(i).sethour(hour);
		loanlist.at(i).setminute(minute);

		}
	}
	cout << "Ten more days added to loan, cannot check out again." << endl;
}


void loans::editloan() {
	int id;
	string status;
	cout << "Enter loan id: " << endl;
	cin >> id;
	
	cin.ignore();
	
	for(unsigned i = 0; i < loanlist.size(); i++){
		
		if(id == loanlist.at(i).getlid()) {
			cout << "Enter new status(normal or overdue): " << endl;
			getline(cin, status);
			loanlist.at(i).setcurrstatus(status);
			
		}
	}
	
}


void loans::lost() {
	string status;
	int id;
	
	cin.ignore();
	cout << "Report lost book" << endl;
	cout << "Enter loan id: " << endl;
	cin >> id;
	
	cin.ignore();
	
	for(unsigned i = 0; i < loanlist.size(); i++){
		
		if(id == loanlist.at(i).getlid()) {
			cout << "Enter new status: " << endl;
			getline(cin, status);
			loanlist.at(i).setcurrstatus(status);
			
		}
	}
	

}


void loans::loadloan()
{
    int loancount;
    ofstream fout;
    fout.open("loans.dat");
    fout << loancount << endl;
    
   for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    {

        fout << it->getlid() << " " <<  it->getbooklid() << " " << it->getpatronlid() << " " << it->getmonth() << " " << it->getday() << " " << it->getyear() << " " << it->gethour() << " " << it->getminute() << endl; 
    }
    fout.close();
}



void loans::storeloan()
{

    ifstream fin;
	int id; // loan id
	int id2; // book id
	int id3; // patron id
	string status;	
	int month;
	int day;
	int year;
	int hour;
	int minute;
	
    fin.open("loans.dat");
	fin >> loancount; fin.ignore();
    
    for ( int i=0; i < loancount; i++)
    {
        
        fin >> id >> id2 >> id3 >> status >> month >> day >> year >> hour >> minute;
        loanlist.push_back(loan(id, id2, id3, status, month, day, year, hour, minute));
    }

    fin.close();
}


void loans::cleanup()
{
       for (auto it = loanlist.begin(); it !=loanlist.end(); ++it)
    {
	loanlist.erase(it);        
    }
    loanlist.clear();
}