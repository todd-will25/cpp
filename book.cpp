/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Todd Yezak
* UNT Email: todd.yezak@my.unt.edu
* Date submitted: 4/25/22
*File name: book.cpp
*Description: cpp file to set one book into the system
*/

#include "book.h"

book::book()
{
	bauthor = "none";
	btitle = "n/a";
	bisbn = 0;
	bid = 0;
	bcost = 0.0;
	bstatus = "n/a";
}

book::book(string author, string title, int isbn, int id, float cost, string status)
{
	bauthor = author;
	btitle = title;
	bisbn = isbn;
	bid = id;
	bcost = cost;
	bstatus = status;
}

string book::getbauthor()
{
	return bauthor;
}

string book::getbtitle()
{
	return btitle;
}

int book::getisbn()
{
	return bisbn;
}

int book::getbid()
{
	return bid;
}

float book::getbcost()
{
	return bcost;
}

string book::getbstatus()
{
	return bstatus;
}

void book::setbauthor(string author)
{
	bauthor = author;
}

void book::setbtitle(string title)
{
	btitle = title;
}

void book::setbisbn(int isbn)
{
	bisbn = isbn;
}

void book::setbid(int id)
{
	bid = id;
}

void book::setbcost(float cost)
{
	bcost = cost;
}

void book::setbstatus(string status)
{
	bstatus = status;
}