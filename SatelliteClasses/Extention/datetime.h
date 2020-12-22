#pragma once
#include <Python.h>
#include "date.h"
#include "time.h"

class DateTime : Date, Time
{
public:
	DateTime();
	DateTime(int, int, int, int, int, int, int);
	DateTime(PyObject*);
	DateTime(PyObject*, PyObject*, PyObject*, PyObject*, 
		PyObject*, PyObject*, PyObject*);
	
	PyObject* get_tuple();
	void set_tuple(PyObject*);

	double julian_day();
	double julian_century();
	double star_time();
};

