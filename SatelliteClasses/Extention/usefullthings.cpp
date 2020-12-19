#include "usefullthings.h"
#include <cmath>



bool set_symmetric_angle(double* angle, double value, double boundary_value)
{
	if (value < boundary_value && value >= -boundary_value)
	{
		*angle = value;
		return true;
	}

	return false;
}

bool set_full_symmetric_angle(double* angle, double value, double boundary_value)
{
	if (value <= boundary_value && value >= -boundary_value)
	{
		*angle = value;
		return true;
	}

	return false;
}

bool set_elliptic_angle(double* angle, double value)
{
	return set_symmetric_angle(angle, value, PI);
}

double get_star_time(DateTime* date_time)
{
	double julian_day = 367.0 * date_time->year -
		floor((7.0 * (date_time->year + floor((date_time->month + 9.0) / 12.0))) * 0.25) +
		floor(275.0 * date_time->month / 9.0) +
		date_time->day + 1721013.5 +
		(((date_time->millisecond / 1000.0 + date_time->second) / 60.0 +
			date_time->minute) / 60.0 + date_time->hour) / 24.0;

	double julian_century = (julian_day - 2451545.0) / 36525.0;

	double star_time = -6.2e-6 * julian_century * julian_century * julian_century +
		0.093104 * julian_century * julian_century +
		(876600.0 * 3600.0 + 8640184.812866) * julian_century + 67310.54841;
	star_time = fmod(star_time * PI / 240.0 / 180.0, 2 * PI);

	if (star_time < 0.0)
		star_time += 2 * PI;

	return star_time;
}