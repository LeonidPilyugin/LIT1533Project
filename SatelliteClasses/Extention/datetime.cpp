#include "datetime.h"
#include "usefullthings.h"



DateTime::DateTime() : Date(), Time()
{

}

DateTime::DateTime(int year, int month, int day, int hour,
	int minute, int second, int millisecond) :
	Date(year, month, day), Time(hour, minute, second, millisecond)

{

}

DateTime::DateTime(PyObject* tuple) :
	Date(PyTuple_GetItem(tuple, 0), PyTuple_GetItem(tuple, 1), PyTuple_GetItem(tuple, 2)),
	Time(PyTuple_GetItem(tuple, 3), PyTuple_GetItem(tuple, 4), PyTuple_GetItem(tuple, 5), PyTuple_GetItem(tuple, 6))
{

}

DateTime::DateTime(PyObject* year, PyObject* month, PyObject* day, 
	PyObject* hour, PyObject* minute, PyObject* second, PyObject* millisecond) :
	Date(year, month, day), Time(hour, minute, second, millisecond)
{

}

PyObject* DateTime::get_tuple()
{
	return PyTuple_Pack(7, pytype_get_year(), pytype_get_month(),
		pytype_get_day(), pytype_get_hour(), pytype_get_minute(),
		pytype_get_second(), pytype_get_millisecond());
}

void DateTime::set_tuple(PyObject* tuple)
{
	pytype_set_year(PyTuple_GetItem(tuple, 0));
	pytype_set_month(PyTuple_GetItem(tuple, 1));
	pytype_set_day(PyTuple_GetItem(tuple, 2));
	pytype_set_hour(PyTuple_GetItem(tuple, 3));
	pytype_set_minute(PyTuple_GetItem(tuple, 4));
	pytype_set_second(PyTuple_GetItem(tuple, 5));
	pytype_set_millisecond(PyTuple_GetItem(tuple, 6));
}

double DateTime::julian_day()
{
	return 367.0 * year -
		floor((7.0 * (year + floor((month + 9.0) / 12.0))) * 0.25) +
		floor(275.0 * month / 9.0) +
		day + 1721013.5 +
		(((millisecond / 1000.0 + second) / 60.0 +
			minute) / 60.0 + hour) / 24.0;
}

double DateTime::julian_century()
{
	return (julian_day() - 2451545.0) / 36525.0;
}

double DateTime::star_time()
{
	double julian_century = DateTime::julian_century();
	double star_time = -6.2e-6 * julian_century * julian_century * julian_century +
		0.093104 * julian_century * julian_century +
		(876600.0 * 3600.0 + 8640184.812866) * julian_century + 67310.54841;
	star_time = fmod(star_time * PI / 240.0 / 180.0, 2 * PI);

	if (star_time < 0.0)
		star_time += 2 * PI;

	return star_time;
}