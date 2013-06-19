#include "SummaryHoursCalculator.h"
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <ctime>
#include<numeric>

using namespace std;

/*------------------------------------------*
*				CONSTRUCTOR					*
*-------------------------------------------*/
SummaryHoursCalculator::SummaryHoursCalculator(std::vector<Period>& _periods)
{
	this->periods = _periods;
}


/*--------------------------------------------------------------------------*
*FUNCTION:	initCalculationMap() put periods to map depending on date		*
* INPUT PARAMETRS:															*
*	vector<Period> periods	- input data									*
*	map<MyDate,<vector<Point> >   -  structure that should be initialized	*
*---------------------------------------------------------------------------*/
void SummaryHoursCalculator::initCalculationMap(const std::vector<Period>& _periods, map<MyDate,std::vector<Point> >& _map)
{
	for (int i(0);i<(int)_periods.size();++i)
	{

		tm currentDate	= _periods[i].getStartDate();
		tm finishDate	= _periods[i].getFinishDate();
		//next line: increment  the last day of the period, cuz the last value of the segment should also be included.
		Period::nextDay(finishDate);
		//next line: while currentDate != finishDate.
		//We use MyDate, cuz tm-structure doesn't have operator==() 
		//and it also contains less memmbers than tm-structure.
		//We use MyDate as the key of the map.
		vector<Day> periodDays = _periods[i].getDays();
		while (!(MyDate(currentDate) == MyDate(finishDate)))
		{
			mktime(&currentDate);
			MyDate currentMyDate = MyDate(currentDate);
			//next line: checking is the current week day is included in period or not
			auto comp_it = find(periodDays.begin(),periodDays.end(),static_cast<short>(currentDate.tm_wday));
			if (comp_it != periodDays.end())
			{
				//BLOCK: if the current week day is included to the current period
				/*if (_map.find(currentMyDate) == _map.end())
				{
					//BLOCK: if current date doesn't exists in the map yet
					vector<Point> value;
					std::pair<MyDate,vector<Point>> toAdd;
					toAdd.first	 = currentMyDate;
					toAdd.second = value;
					//next line: adding a new cell to the map 
					_map.insert(toAdd);
					//next line: adding points to the map[currentDate] value.
					// we mark true, if Point is the startHour(start of the segment)
					_map[currentMyDate].push_back(Point(_periods[i].getStartHour(),true));
					_map[currentMyDate].push_back(Point(_periods[i].getFinishHour(),false));
				}
				else 
				{*/
					//next line: adding points to the map[currentDate] value.
					// we mark true, if Point is the startHour(start of the segment)
					// NOTE: if If k does not match the key of any element in the container, the function inserts a new element 
					// with that key and returns a reference to its mapped value.
					// http://www.cplusplus.com/reference/map/map/operator%5B%5D/
					_map[currentMyDate].push_back(Point(_periods[i].getStartHour(),true));
					_map[currentMyDate].push_back(Point(_periods[i].getFinishHour(),false));
				//}
			}
			//increment current day.
			Period::nextDay(currentDate);
		}
	}
}



/*--------------------------------------------------------------------------------------*
*FUNCTION Calculate() calculates the summary amount of active hours of all periods		*
*INPUT PARAMETR: null																	*
*RETURN VALUE:	return the summary amount of active hours								*
*Uses: initCalculationMap to initialize local variable									*
*---------------------------------------------------------------------------------------*/
double SummaryHoursCalculator::Calculate()
{
	vector<double> results;
	map<MyDate,std::vector<Point> > calculationMap;
	//next line: initialize the calculationMap.
	this->initCalculationMap(periods,calculationMap);
	double result = 0;
	//for each member of the map. member is the vector with points on the time axis 
	//that are marked as the start or the end of the segment.
	for (auto it = calculationMap.begin();
		it != calculationMap.end();++it)
	{
		//sorting points. smth like place them on the time axis.
		std::sort(std::begin(it->second), std::end(it->second));

		double prev_time = it->second.front().m_time;
		int num_segment = 0;
		double union_length = 0;

		for (auto itr = std::begin(it->second); itr != std::end(it->second); ++itr)
		{
		  //number of segments > 0. 
		  // it's the same thing as:
		  // if we are inside the time segment - we increment the length(active hours).
		  if (num_segment > 0)
			union_length += (itr->m_time - prev_time);
  
		  prev_time = itr->m_time;
		  //if the current point is the start of the segment - increase number of segments.
		  if (itr->m_start)
			num_segment = num_segment + 1;
		  else
			num_segment = num_segment - 1;
		}
		//adding active hours.
		result += union_length;
	}
	
	return result;
}