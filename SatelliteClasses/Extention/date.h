#pragma once
#include <Python.h>


class Date
{
protected:
	int year;
	int month;
	int day;
	bool check_day(double);

public:
	Date();
	Date(int, int, int);
	Date(PyObject*);
	Date(PyObject*, PyObject*, PyObject*);

	int get_year();
	int get_month();
	int get_day();
	PyObject* pytype_get_year();
	PyObject* pytype_get_month();
	PyObject* pytype_get_day();

	void set_year(int);
	void set_month(int);
	void set_day(int);
	void pytype_set_year(PyObject*);
	void pytype_set_month(PyObject*);
	void pytype_set_day(PyObject*);

	PyObject* get_tuple();
	void set_tuple(PyObject*);
};

