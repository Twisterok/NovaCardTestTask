/*--------------------------------------------------------------------------------------*
*	class SummaryHoursCalculator is able to calculate the summary amount of active hours*
*	of periods that came as input data.													*
*Function descriptions are written in SummaryHoursCalculator.cpp						*															*
*---------------------------------------------------------------------------------------*/
#ifndef __SUMMARYHOURSCALCULATOR__
#define __SUMMARYHOURSCALCULATOR__
#include <vector>
#include <map>

#include "Period.h"
#include "MyDate.h"
#include "Point.h"

class SummaryHoursCalculator
{
	std::vector<Period> periods;
	void initCalculationMap(const std::vector<Period>& _period, std::map<MyDate,std::vector<Point> >& _map);
public:
	SummaryHoursCalculator(std::vector<Period>& _periods);
	double Calculate();
};

#endif