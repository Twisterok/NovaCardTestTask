/*--------------------------------------------------------------------------------------*
*	class MyDate is used as a key of std::map<MyDate,std::vector<double> >				*
*	This map is used to sort hours by date.												*
*																						*
*	e.g.    map[4.06.00] == {	Point(10,true),											*
*								Point(19,false),										*
*								Point(8,true),											*
*								Point(15,false)};										*
*																						*
*	Description of class Point you can find in Point.h									*
*---------------------------------------------------------------------------------------*/

#ifndef ___MYDATE___
#define ___MYDATE___
#include <ctime>

class MyDate
{
public:
	int year,month,day;

	MyDate();
	MyDate(int _year,int _month,int _day);
	MyDate(tm _time);
	bool operator==(const MyDate& other) const;
	bool operator<(const MyDate& other)	 const;
	void operator=(const MyDate& other);
};

#endif