#pragma once
#include <Python.h>

// This module contains description of the classes ConicSection and Ellipse
// Other conic section classes should be described here
// 
// ConicSection is abstract parent class for other conic sections
// ConicSection describes conic section
// Information about conic sections: 
// https://en.wikipedia.org/wiki/Conic_section
// 
// Ellipse describes ellipse (0 <= eccentricity < 1)

class ConicSection
{
protected:
	double eccentricity;
	double semi_major_axis;

public:
	ConicSection();                        // Sets eccentricity = 0.0, semi_major_axis = 0.0
	ConicSection(double, double);          // Order of arguments: eccentricity, semi_major_axis
	ConicSection(PyObject*);               // Argument must be a tuple: (eccentricity, semi_major_axis)
	ConicSection(PyObject*, PyObject*);    // Order of arguments: eccentricity, semi_major_axis

	double get_eccentricity();
	double get_semi_major_axis();
	PyObject* pytype_get_eccentricity();
	PyObject* pytype_get_semi_major_axis();

	virtual void set_eccentricity(double);
	void set_semi_major_axis(double);      // Semi-major axis must be a positive number
	virtual void pytype_set_eccentricity(PyObject*);
	void pytype_set_semi_major_axis(PyObject*);

	PyObject* get_tuple();                 // Returns tuple: (eccentricity, semi_major_axis)
	virtual void set_tuple(PyObject*);     // Sets fields from a tuple. Argument must be a tuple: (eccentricity, semi_major_axis)

	virtual double focal_parameter() = 0;
	virtual double semi_latus_rectum() = 0;
	virtual PyObject* pytype_focal_parameter() = 0;
	virtual PyObject* pytype_semi_latus_rectum() = 0;
};