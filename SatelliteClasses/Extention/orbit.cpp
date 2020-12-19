#include "orbit.h"
#include "usefullthings.h"

// This module contains description of the methods of the classes Orbit and EllipticOrbit

Orbit::Orbit()
{
	inclination = 0.0;
	ascending_node_longitude = 0.0;
	periapsis_argument = 0.0;
}

Orbit::Orbit(double inclination, double ascending_node_longitude,
	double periapsis_argument)
{
	this->inclination = inclination;
	this->ascending_node_longitude = ascending_node_longitude;
	this->periapsis_argument = periapsis_argument;
}

Orbit::Orbit(PyObject* tuple)
{
	set_tuple(tuple);
}

Orbit::Orbit(PyObject* inclination, PyObject* ascending_node_longitude,
	PyObject* periapsis_argument)
{
	this->inclination = PyFloat_AsDouble(inclination);
	this->ascending_node_longitude = PyFloat_AsDouble(ascending_node_longitude);
	this->periapsis_argument = PyFloat_AsDouble(periapsis_argument);
}

double Orbit::get_inclination()
{
	return inclination;
}

double Orbit::get_ascending_node_longitude()
{
	return ascending_node_longitude;
}

double Orbit::get_periapsis_argument()
{
	return periapsis_argument;
}

PyObject* Orbit::pytype_get_inclination()
{
	return PyFloat_FromDouble(inclination);
}

PyObject* Orbit::pytype_get_ascending_node_longitude()
{
	return PyFloat_FromDouble(ascending_node_longitude);
}

PyObject* Orbit::pytype_get_periapsis_argument()
{
	return PyFloat_FromDouble(periapsis_argument);
}

void Orbit::set_inclination(double value)
{
	if (!set_elliptic_angle(&inclination, value))
		throw "Inclination must be less than pi and greater than or equal to -pi";
}

void Orbit::set_ascending_node_longitude(double value)
{
	if (!set_elliptic_angle(&ascending_node_longitude, value))
		throw "The longitude of ascending node must be less than pi and greater than or equal to -pi";
}

void Orbit::set_periapsis_argument(double value)
{
	if (!set_elliptic_angle(&periapsis_argument, value))
		throw "Periapsis argument must be less than pi and greater than or equal to -pi";
}

void Orbit::pytype_set_inclination(PyObject* value)
{
	set_inclination(PyFloat_AsDouble(value));
}

void Orbit::pytype_set_ascending_node_longitude(PyObject* value)
{
	set_ascending_node_longitude(PyFloat_AsDouble(value));
}

void Orbit::pytype_set_periapsis_argument(PyObject* value)
{
	set_periapsis_argument(PyFloat_AsDouble(value));
}

PyObject* Orbit::get_tuple()
{
	return PyTuple_Pack(3, pytype_get_inclination(), pytype_get_ascending_node_longitude(),
		pytype_get_periapsis_argument());
}

void Orbit::set_tuple(PyObject* tuple)
{
	pytype_set_inclination(PyTuple_GetItem(tuple, 0));
	pytype_set_ascending_node_longitude(PyTuple_GetItem(tuple, 1));
	pytype_set_periapsis_argument(PyTuple_GetItem(tuple, 2));
}