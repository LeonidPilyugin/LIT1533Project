#include "time.h"



Time::Time() : Time(0, 0, 0, 0)
{

}

Time::Time(int hour, int minute, int second, int millisecond)
{
	this->hour = hour;
	this->minute = minute;
	this->second = second;
	this->millisecond = millisecond;
}

Time::Time(PyObject* tuple) :
	Time(PyTuple_GetItem(tuple, 0), PyTuple_GetItem(tuple, 1),
		PyTuple_GetItem(tuple, 2), PyTuple_GetItem(tuple, 3))
{

}

Time::Time(PyObject* hour, PyObject* minute, PyObject* second, PyObject* millisecond) :
	Time(PyLong_AsLong(hour), PyLong_AsLong(minute), PyLong_AsLong(second),
		PyLong_AsLong(millisecond))
{

}

int Time::get_hour()
{
	return hour;
}

int Time::get_minute()
{
	return minute;
}

int Time::get_second()
{
	return second;
}

int Time::get_millisecond()
{
	return millisecond;
}

PyObject* Time::pytype_get_hour()
{
	return PyLong_FromLong(hour);
}

PyObject* Time::pytype_get_minute()
{
	return PyLong_FromLong(minute);
}

PyObject* Time::pytype_get_second()
{
	return PyLong_FromLong(second);
}

PyObject* Time::pytype_get_millisecond()
{
	return PyLong_FromLong(millisecond);
}

void Time::set_hour(int value)
{
	if (value >= 0 && value < 24)
		hour = value;
	else
		throw "Hour must be less then 24 and more or equal to 0";
}

void Time::set_minute(int value)
{
	if (value < 60 && value >= 0)
		minute = value;
	else
		throw "Minute must be less than 60 and more or equal to 0";
}

void Time::set_second(int value)
{
	if (value < 60 && value >= 0)
		second = value;
	else
		throw "Second must be less than 60 and more or equal to 0";
}

void Time::set_millisecond(int value)
{
	if (value < 1000 && value >= 0)
		millisecond = value;
	else
		throw "Second must be less than 1000 and more or equal to 0";
}

void Time::pytype_set_hour(PyObject* value)
{
	set_hour(PyLong_AsLong(value));
}

void Time::pytype_set_minute(PyObject* value)
{
	set_minute(PyLong_AsLong(value));
}

void Time::pytype_set_second(PyObject* value)
{
	set_second(PyLong_AsLong(value));
}

void Time::pytype_set_millisecond(PyObject* value)
{
	set_millisecond(PyLong_AsLong(value));
}

PyObject* Time::get_tuple()
{
	return PyTuple_Pack(4, pytype_get_hour(), pytype_get_minute(), 
		pytype_get_second(), pytype_get_millisecond());
}

void Time::set_tuple(PyObject* tuple)
{
	pytype_set_hour(PyTuple_GetItem(tuple, 0));
	pytype_set_minute(PyTuple_GetItem(tuple, 1));
	pytype_set_second(PyTuple_GetItem(tuple, 2));
	pytype_set_millisecond(PyTuple_GetItem(tuple, 3));
}
