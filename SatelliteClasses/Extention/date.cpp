#include "date.h"




bool Date::check_day(double value)
{
	if (month <= 6)
	{
		if (month % 2 == 0) // January, March, May, July
			return value < 32;
		else if (month == 1) // February
			return (year % 4 == 0 && value < 30) ||
			(year % 4 != 0 && value < 29);
		else // April
			return value < 31;
	}
	else
	{
		if (month % 2 == 1) // August, October, December
			return value < 32;
		else // September, November
			return value < 31;
	}
}

Date::Date() : Date(0, 0, 0)
{

}

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(PyObject* tuple) :
	Date(PyTuple_GetItem(tuple, 0), PyTuple_GetItem(tuple, 1), PyTuple_GetItem(tuple, 2))
{

}

Date::Date(PyObject* year, PyObject* month, PyObject* day) :
	Date(PyLong_AsLong(year), PyLong_AsLong(month), PyLong_AsLong(day))
{

}

int Date::get_year()
{
	return year;
}

int Date::get_month()
{
	return month;
}

int Date::get_day()
{
	return day;
}

PyObject* Date::pytype_get_year()
{
	return PyLong_FromLong(year);
}

PyObject* Date::pytype_get_month()
{
	return PyLong_FromLong(month);
}

PyObject* Date::pytype_get_day()
{
	return PyLong_FromLong(day);
}

void Date::set_year(int value)
{
	year = value;
}

void Date::set_month(int value)
{
	if (value < 12 && value >= 0)
		month = value;
	else
		throw "Month must be less than 12 and more or equal to 0";
}

void Date::set_day(int value)
{
	if (check_day(value))
		month = value;
	else
		throw "Day isn't correct";
}

void Date::pytype_set_year(PyObject* value)
{
	set_year(PyLong_AsLong(value));
}

void Date::pytype_set_month(PyObject* value)
{
	set_month(PyLong_AsLong(value));
}

void Date::pytype_set_day(PyObject* value)
{
	set_day(PyLong_AsLong(value));
}

PyObject* Date::get_tuple()
{
	return PyTuple_Pack(3, pytype_get_year(), pytype_get_month(), pytype_get_day());
}

void Date::set_tuple(PyObject* tuple)
{
	pytype_set_year(PyTuple_GetItem(tuple, 0));
	pytype_set_month(PyTuple_GetItem(tuple, 1));
	pytype_set_day(PyTuple_GetItem(tuple, 2));
}
