#include <iostream>
#include <map>
#include <string>


#include "Period.h"
#include "MyDate.h"
#include "Point.h"
#include "SummaryHoursCalculator.h"

using namespace std;


void printDay(Day dd)
{

	switch (dd)
	{
	case SUNDAY:
		cout<<"Sunday";
		break;
	case MONDAY:
		cout<<"Monday";
		break;
	case TUESDAY:
		cout<<"Tuesday";
		break;
	case WEDNESDAY:
		cout<<"Wednesday";
		break;
	case THURSDAY:
		cout<<"Thursday";
		break;
	case FRIDAY:
		cout<<"Friday";
		break;
	case SATURDAY:
		cout<<"Saturday";
		break;
	}
}


int main()
{
	map<MyDate,double> _map;
	std::vector<Day> days;				// Active days of the period (e.g. Sunday,Tuesday, etc.).
	days.push_back(Day::SUNDAY);
	days.push_back(Day::MONDAY);

	std::vector<Day> days2;				// Active days of the period (e.g. Sunday,Tuesday, etc.).
	days2.push_back(Day::SUNDAY);
	days2.push_back(Day::TUESDAY);


	tm startDate;
	startDate.tm_hour	= 0;
	startDate.tm_mday	= 2;
	startDate.tm_sec	= 0;
	startDate.tm_min	= 0;
	startDate.tm_mon	= 5;
	startDate.tm_year	= 100;

	tm finishDate;
	finishDate.tm_hour	= 0;
	finishDate.tm_mday	= 7;
	finishDate.tm_sec	= 0;
	finishDate.tm_min	= 0;
	finishDate.tm_mon	= 5;
	finishDate.tm_year	= 100;

	double startHour	= 10;
	double finishHour	= 19;
	double startHour2	= 8;
	double finishHour2	= 15;


	Period per1(days,startDate,finishDate,startHour,finishHour);

	tm startDate2;
	startDate2.tm_hour	= 0;
	startDate2.tm_mday	= 1;
	startDate2.tm_sec	= 0;
	startDate2.tm_min	= 0;
	startDate2.tm_mon	= 5;
	startDate2.tm_year	= 100;

	tm finishDate2;
	finishDate2.tm_hour	= 0;
	finishDate2.tm_mday	= 8;
	finishDate2.tm_sec	= 0;
	finishDate2.tm_min	= 0;
	finishDate2.tm_mon	= 5;
	finishDate2.tm_year	= 100;

	Period per2(days2,startDate2,finishDate2,startHour2,finishHour2);

	vector<Period> vect;
	vect.push_back(per1);
	vect.push_back(per2);
	SummaryHoursCalculator calc(vect);
	double hours = calc.Calculate();
	cout<<"active hours = "<<hours<<endl;
	return 0;
}