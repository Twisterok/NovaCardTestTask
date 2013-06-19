#include "MyDate.h"

//CONSTRUCTORS
MyDate::MyDate()
{
	this->year	= 0;
	this->month	= 0;
	this->day	= 1;
}

MyDate::MyDate(int _year,int _month,int _day)
{
	this->year	= _year;
	this->month	= _month;
	this->day	= _day;
}

MyDate::MyDate(tm _time)
{
	this->year	= _time.tm_year;
	this->month	= _time.tm_mon;
	this->day	= _time.tm_mday;
}


//OPERATORS
bool MyDate::operator==(const MyDate& other) const
{
	if (other.year != this->year)
		return false;
	else if (other.month != this->month)
		return false;
	else if (other.day != this->day)
		return false;
	else
		return true;
}

bool MyDate::operator<(const MyDate& other) const
{
	if (this->year < other.year)
		return true;
	else if(this->year	==	other.year	&& 
			this->month <	other.month)
		return true;
	else if(this->year	==	other.year	&& 
			this->month	==	other.month	&&
			this->day	<	other.day)
		return true;
	else
		return false;
}


void MyDate::operator=(const MyDate& other)
{
	this->year	= other.year;
	this->month = other.month;
	this->day	= other.day;
}