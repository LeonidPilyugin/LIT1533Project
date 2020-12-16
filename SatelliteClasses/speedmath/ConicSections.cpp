#include "ConicSections.h"
#include <cmath>



ConicSection::ConicSection(PyObject* tuple) 
{
	eccentricity = PyFloat_AsDouble(PyTuple_GetItem(tuple, 0));
	semi_major_axis = PyFloat_AsDouble(PyTuple_GetItem(tuple, 1));
}

ConicSection::ConicSection(PyObject* eccentricity, PyObject* semi_major_axis)
{
	this->eccentricity = PyFloat_AsDouble(eccentricity);
	this->semi_major_axis = PyFloat_AsDouble(semi_major_axis);
}



Ellipse::Ellipse(PyObject* tuple) : ConicSection(tuple)
{

}

Ellipse::Ellipse(PyObject* eccentricity, PyObject* semi_major_axis) : ConicSection(eccentricity, semi_major_axis)
{

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