#include "Chapter6.h"
#include <cmath>
double myABS(double t)
{
	if (t < 0)
	{
		return -t;
	}
	else
	{
		return t;
	}
}
double myABS2(double t)
{
	return abs(t);
}