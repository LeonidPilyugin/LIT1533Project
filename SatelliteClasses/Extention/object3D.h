#pragma once
#include <Python.h>
#include "point3D.h"



class Object3D // Now it is a sphere
{
protected:
	Point3D center;
	double radius;

public:
	Object3D();
	Object3D(Point3D, double);
	Object3D(double, double, double, double);
	Object3D(PyObject*);
	Object3D(PyObject*, PyObject*, PyObject*, PyObject*);

	Point3D get_center();
	double get_radius();
	PyObject* pytype_get_radius();

	void set_radius(double);
	void pytype_set_radius(PyObject*);

	PyObject* get_tuple();
	void set_tuple(PyObject*);
};

