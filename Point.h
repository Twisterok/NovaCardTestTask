/*--------------------------------------------------------------------------------------*
*	class Point is used in algorithm of segments union.									*
*	m_time describes the time (point on the time axis)									*
*	m_start describes is that point is the start of the segment or not					*
*	e.g.    m_time:	 10																	*
*			m_start: true																*
*---------------------------------------------------------------------------------------*/
#ifndef	__POINT__
#define __POINT__
#include <ctime>

struct Point
{
  double m_time;	// time. the point on the time axis
  bool m_start;		// is start of the segment or not

  Point(double time, bool start) : m_time(time), m_start(start)  {}
  bool operator <(const Point& other) const  { return m_time < other.m_time; }
};
#endif