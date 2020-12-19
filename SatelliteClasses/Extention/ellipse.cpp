#include "ellipse.h"
#include "usefullthings.h"
#include <cmath>

// This module contains description of the methods of the classes ConicSection and Ellipse

Ellipse::Ellipse() : ConicSection()
{

}

Ellipse::Ellipse(double eccentricity, double semi_major_axis) : 
	ConicSection(eccentricity, semi_major_axis)
{

}

Ellipse::Ellipse(PyObject* tuple) : ConicSection(tuple)
{

}

Ellipse::Ellipse(PyObject* eccentricity, PyObject* semi_major_axis) : 
	ConicSection(eccentricity, semi_major_axis)
{

}

void Ellipse::set_eccentricity(double value)
{
	if (value >= 0 && value < 1)
		eccentricity = value;
	else
		throw "Eccentricity must be a non-negative number less then 1";
}

void Ellipse::pytype_set_eccentricity(PyObject* pyvalue)
{
	double value = PyFloat_AsDouble(pyvalue);
	if (value >= 0 && value < 1)
		eccentricity = value;
	else
		throw "Eccentricity must be a non-negative number less then 1";
}

void Ellipse::set_tuple(PyObject* tuple)
{
	pytype_set_eccentricity(PyTuple_GetItem(tuple, 0));
	pytype_set_semi_major_axis(PyTuple_GetItem(tuple, 1));
}

double Ellipse::focal_parameter()
{
	return semi_major_axis * (1 - eccentricity * eccentricity) / eccentricity;
}

double Ellipse::semi_latus_rectum()
{
	return semi_major_axis * (1 - eccentricity * eccentricity);
}

double Ellipse::linear_eccentricity()
{
	return eccentricity * semi_major_axis;
}

double Ellipse::semi_minor_axis()
{
	return semi_major_axis * sqrt(1 - eccentricity * eccentricity);
}

double Ellipse::aspect_ratio()
{
	return sqrt(1 - eccentricity * eccentricity);
}

double Ellipse::perifocus_distance()
{
	return semi_major_axis * (1 - eccentricity);
}

double Ellipse::apothecure_distance()
{
	return semi_major_axis * (1 + eccentricity);
}

PyObject* Ellipse::pytype_focal_parameter()
{
	return PyFloat_FromDouble(focal_parameter());
}

PyObject* Ellipse::pytype_semi_latus_rectum()
{
	return PyFloat_FromDouble(semi_latus_rectum());
}

PyObject* Ellipse::pytype_linear_eccentricity()
{
	return PyFloat_FromDouble(linear_eccentricity());
}

PyObject* Ellipse::pytype_semi_minor_axis()
{
	return PyFloat_FromDouble(semi_minor_axis());
}

PyObject* Ellipse::pytype_aspect_ratio()
{
	return PyFloat_FromDouble(aspect_ratio());
}

PyObject* Ellipse::pytype_perifocus_distance()
{
	return PyFloat_FromDouble(perifocus_distance());
}

PyObject* Ellipse::pytype_apothecure_distance()
{
	return PyFloat_FromDouble(apothecure_distance());
}