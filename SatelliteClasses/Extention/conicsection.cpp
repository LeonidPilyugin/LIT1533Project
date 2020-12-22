#include "conicsection.h"
#include "usefullthings.h"
#include <cmath>

// This module contains description of the methods of the classes ConicSection and Ellipse

ConicSection::ConicSection()
{
	eccentricity = 0.0;
	semi_major_axis = EARTH_SEMI_MAJOR_AXIS;
}

ConicSection::ConicSection(double eccentricity, double semi_major_axis)
{
	this->eccentricity = eccentricity;
	this->semi_major_axis = semi_major_axis;
}

ConicSection::ConicSection(PyObject* tuple) :
	ConicSection(PyTuple_GetItem(tuple, 0), PyTuple_GetItem(tuple, 1))
{

}

ConicSection::ConicSection(PyObject* eccentricity, PyObject* semi_major_axis) :
	ConicSection(PyFloat_AsDouble(eccentricity), PyFloat_AsDouble(semi_major_axis))
{

}

double ConicSection::get_eccentricity()
{
	return eccentricity;
}

double ConicSection::get_semi_major_axis()
{
	return semi_major_axis;
}

PyObject* ConicSection::pytype_get_eccentricity()
{
	return PyFloat_FromDouble(eccentricity);
}

PyObject* ConicSection::pytype_get_semi_major_axis()
{
	return PyFloat_FromDouble(semi_major_axis);
}

void ConicSection::set_eccentricity(double value)
{
	if (value >= 0.0)
		eccentricity = value;
	else
		throw "Eccentricity must be a non-negative number";
}

void ConicSection::set_semi_major_axis(double value)
{
	if (value > 0)
		semi_major_axis = value;
	else
		throw "Semi-major axis must be a positive number";
}

void ConicSection::pytype_set_eccentricity(PyObject* value)
{
	set_eccentricity(PyFloat_AsDouble(value));
}

void ConicSection::pytype_set_semi_major_axis(PyObject* pyvalue)
{
	double value = PyFloat_AsDouble(pyvalue);
	if (value > 0)
		semi_major_axis = value;
	else
		throw "Semi-major axis must be a positive number";
}

PyObject* ConicSection::get_tuple()
{
	return PyTuple_Pack(2, pytype_get_eccentricity(), pytype_get_semi_major_axis());
}

void ConicSection::set_tuple(PyObject* tuple)
{
	pytype_set_eccentricity(PyTuple_GetItem(tuple, 0));
	pytype_set_semi_major_axis(PyTuple_GetItem(tuple, 1));
}