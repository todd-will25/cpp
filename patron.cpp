/*
* CSCE 1040 Homeowork 3
* Section: 001
* Name: Todd Yezak
* UNT Email: todd.yezak@my.unt.edu
* Date submitted: 4/25/22
*File name: patron.cpp
*Description:  cpp file of inputting one patron into the system
*/

#include "patron.h"
using namespace std;

patron::patron()
{
	patname = "none";
	pid = 0;
	pbalance = 0.0;
	pbout = 0;
}

patron::patron(int id, string name, float balance, int booksout)
{
	patname = name;
	pid = id;
	pbalance = balance;
	pbout = booksout;
}

string patron::getpname()
{
	return patname;
}

int patron::getpid()
{
	return pid;
}

float patron::getpbalance()
{
	return pbalance;
}

int patron::getpbout()
{
	return pbout;
}

void patron::setpname(string name)
{
	patname = name;;
}

void patron::setpid(int id)
{
	pid = id;
}

void patron::setpbalance(float balance)
{
	pbalance = balance;
}

void patron::setpbout(int booksout)
{
	pbout = booksout;
}