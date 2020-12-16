#pragma once
#include <Python.h>



class ConicSection
{
protected:
	double eccentricity;
	double semi_major_axis;

public:
	ConicSection(PyObject*);
	ConicSection(PyObject*, PyObject*);
	virtual double focal_parameter(void) = 0;
	virtual double semi_latus_rectum(void) = 0;
};



class Ellipse : public ConicSection
{
public:
	Ellipse(PyObject*);
	Ellipse(PyObject*, PyObject*);
	double focal_parameter(void);
	double semi_latus_rectum(void);
	double linear_eccentricity(void);
	double semi_minor_axis(void);
	double aspect_ratio(void);
	double perifocus_distance(void);
	double apothecure_distance(void);
};


