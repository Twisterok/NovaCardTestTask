#include "Period.h"

//CONSTRUCTOR
Period::Period(const std::vector<Day>& _days,
		const tm& _startDate,
		const tm& _finishDate,
		double _startHour,
		double _finishHour)
{
		days		= _days;
		startDate	= _startDate;
		finishDate	= _finishDate;
		startHour	= _startHour;
		finishHour	= _finishHour;
}

//GETTERS
std::vector<Day>	Period::getDays()	const
{
	return this->days;
}

tm		Period::getStartDate() const
{
	return this->startDate;
}

tm		Period::getFinishDate() const
{
	return this->finishDate;
}

double	Period::getStartHour()	const
{
	return this->startHour;
}

double	Period::getFinishHour()	const
{
	return this->finishHour;
}


//INCREMENTS THE DAY.
void Period::nextDay(tm& date)
{
	date.tm_mday++;
	if ( date.tm_mday == 32)
	{
		date.tm_mday = 1;
		date.tm_mon++;
		if (date.tm_mon == 12)
		{
			date.tm_mon = 0;
			date.tm_year++;
		}
	}
}