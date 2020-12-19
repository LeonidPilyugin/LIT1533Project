#pragma once
#include <Python.h>
#include "conicsection.h"
// For Ellipse eccentricity must be a non-negative number less then 1

class Ellipse : public ConicSection
{
public:
	// All constructors call similar ConicSection constructors
	Ellipse();
	Ellipse(double, double);
	Ellipse(PyObject*);
	Ellipse(PyObject*, PyObject*);

	void set_eccentricity(double);
	void pytype_set_eccentricity(PyObject*);

	void set_tuple(PyObject*);

	double focal_parameter();
	double semi_latus_rectum();
	double linear_eccentricity();
	double semi_minor_axis();
	double aspect_ratio();
	double perifocus_distance();
	double apothecure_distance();

	PyObject* pytype_focal_parameter();
	PyObject* pytype_semi_latus_rectum();
	PyObject* pytype_linear_eccentricity();
	PyObject* pytype_semi_minor_axis();
	PyObject* pytype_aspect_ratio();
	PyObject* pytype_perifocus_distance();
	PyObject* pytype_apothecure_distance();
};


