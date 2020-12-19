#pragma once
#include "point3D.h"
#include "object3D.h"



class Segment3D
{
protected:
	Point3D first;
	Point3D last;

public:
	Segment3D();
	Segment3D(Point3D, Point3D);
	Segment3D(double, double, double, double, double, double);
	Segment3D(PyObject*);
	Segment3D(PyObject*, PyObject*, PyObject*, PyObject*, PyObject*, PyObject*);

	Point3D get_first();
	Point3D get_last();

	PyObject* get_tuple();
	void set_tuple(PyObject*);

	double length();
	double distance_to(Point3D);
	//Point3D perpendicular_base(Point3D);
	bool is_crossing(Object3D); // for sphere works with small radius and very big distance between points
};

