#include "Orbits.h"



Orbit::Orbit(PyObject* tuple) 
{
	inclination = PyFloat_AsDouble(PyTuple_GetItem(tuple, 0));
	ascending_node_longitude = PyFloat_AsDouble(PyTuple_GetItem(tuple, 1));
	periapsis_argument = PyFloat_AsDouble(PyTuple_GetItem(tuple, 2));
}

Orbit::Orbit(PyObject* inclination, PyObject* ascending_node_longitude, PyObject* periapsis_argument)
{
	this->inclination = PyFloat_AsDouble(inclination);
	this->ascending_node_longitude = PyFloat_AsDouble(ascending_node_longitude);
	this->periapsis_argument = PyFloat_AsDouble(periapsis_argument);
}



EllipticOrbit::EllipticOrbit(PyObject* tuple) : 
	Ellipse(PyTuple_GetItem(tuple, 0), PyTuple_GetItem(tuple, 1)),
	Orbit(PyTuple_GetItem(tuple, 2), PyTuple_GetItem(tuple, 3), PyTuple_GetItem(tuple, 4))
{

}

EllipticOrbit::EllipticOrbit(PyObject* eccentricity, PyObject* semi_major_axis, 
	PyObject* inclination, PyObject* ascending_node_longitude, PyObject* periapsis_argument) :
	Ellipse(eccentricity, semi_major_axis), Orbit(inclination, ascending_node_longitude, periapsis_argument)
{

}