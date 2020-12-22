#pragma once
#include <Python.h>



class Time
{
protected:
	int hour;
	int minute;
	int second;
	int millisecond;

public:
	Time();
	Time(int, int, int, int);
	Time(PyObject*);
	Time(PyObject*, PyObject*, PyObject*, PyObject*);

	int get_hour();
	int get_minute();
	int get_second();
	int get_millisecond();
	PyObject* pytype_get_hour();
	PyObject* pytype_get_minute();
	PyObject* pytype_get_second();
	PyObject* pytype_get_millisecond();

	void set_hour(int);
	void set_minute(int);
	void set_second(int);
	void set_millisecond(int);
	void pytype_set_hour(PyObject*);
	void pytype_set_minute(PyObject*);
	void pytype_set_second(PyObject*);
	void pytype_set_millisecond(PyObject*);

	PyObject* get_tuple();
	void set_tuple(PyObject*);
};

