#pragma once
#include <Python.h>



class Point3D
{
protected:
	double x;
	double y;
	double z;

public:
	Point3D();
	Point3D(double, double, double);
	Point3D(PyObject*);
	Point3D(PyObject*, PyObject*, PyObject*);

	double get_x();
	double get_y();
	double get_z();
	PyObject* pytype_get_x();
	PyObject* pytype_get_y();
	PyObject* pytype_get_z();

	void set_x(double);
	void set_y(double);
	void set_z(double);
	void pytype_set_x(PyObject*);
	void pytype_set_y(PyObject*);
	void pytype_set_z(PyObject*);

	PyObject* get_tuple();
	void set_tuple(PyObject*);


	double distance_to(Point3D);
};

