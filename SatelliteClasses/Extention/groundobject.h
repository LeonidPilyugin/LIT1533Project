#pragma once
#include <Python.h>
#include "point3D.h"
#include "usefullthings.h"

// This module contains description of the class GroundObject
// 
// GroundObject is parent class for other dround objects

class GroundObject
{
protected:
	double longitude;
	double latitude;

public:
	GroundObject();
	GroundObject(double, double);
	GroundObject(PyObject*);
	GroundObject(PyObject*, PyObject*);

	double get_longitude();
	double get_latitude();
	PyObject* pytype_get_longitude();
	PyObject* pytype_get_latitude();

	void set_longitude(double);
	void set_latitude(double);
	void pytype_set_longitude(PyObject*);
	void pytype_set_latitude(PyObject*);

	PyObject* get_tuple();                  // Returns tuple: (longitude, latitude)
	void set_tuple(PyObject*);              // Sets fields from a tuple. Argument must be a tuple: (longitude, latitude)

	Point3D get_point(DateTime*);

	double distance_to(Point3D, DateTime*);
};

