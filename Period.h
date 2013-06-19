/*--------------------------------------------------------------------------------------*
*	class Period is used as an input data of the program. It describes the time period.	*
*																						*
*	e.g.    Start  Date:	2.06.00														*
*			Finish Date:	7.06.00														*
*			Active Days:	Sunday,Monday												*
*			Start  Hour:	10															*
*			Finish Hour:	19															*
*---------------------------------------------------------------------------------------*/

#ifndef __PERIOD__
#define __PERIOD__
//STANDARD INCLUDES
#include <vector>
#include <ctime>

//OTHER INCLUDES
#include "Days.h"

class Period
{	
	std::vector<Day> days;				// Active days of the period (e.g. Sunday,Tuesday, etc.).
	tm startDate,finishDate;			// Bounds of the period.
	double startHour,finishHour;		// Working hours.
	
public:
	
	Period(const std::vector<Day>& _days,
		const tm& _startDate,
		const tm& _finishDate,
		double _startHour,
		double _finishHour);

	//GETTERS
	std::vector<Day>	getDays()		const;
	tm					getStartDate()	const;
	tm					getFinishDate() const;
	double				getStartHour()	const;
	double				getFinishHour()	const;

	//INCREMENT
	static void nextDay(tm& date); 
};

#endif