#include "ellipticorbit.h"
#include "usefullthings.h"

// This module contains description of the methods of the classes Orbit and EllipticOrbit

EllipticOrbit::EllipticOrbit() : Orbit(), Ellipse()
{

}

EllipticOrbit::EllipticOrbit(double eccentricity, double semi_major_axis,
	double inclination, double ascending_node_longitude,
	double periapsis_argument) :
	Orbit(inclination, ascending_node_longitude, periapsis_argument),
	Ellipse(eccentricity, semi_major_axis)
{

}
	
EllipticOrbit::EllipticOrbit(PyObject* tuple) :
	Orbit(PyTuple_GetItem(tuple, 2), PyTuple_GetItem(tuple, 3),
		PyTuple_GetItem(tuple, 4)),
	Ellipse(PyTuple_GetItem(tuple, 0), PyTuple_GetItem(tuple, 1))
{

}

EllipticOrbit::EllipticOrbit(PyObject* eccentricity, PyObject* semi_major_axis,
	PyObject* inclination, PyObject* ascending_node_longitude,
	PyObject* periapsis_argument) : Orbit(inclination, ascending_node_longitude,
		periapsis_argument), Ellipse(eccentricity, semi_major_axis)
{

}

PyObject* EllipticOrbit::get_tuple()
{
	return PyTuple_Pack(5, pytype_get_eccentricity(),
		pytype_get_semi_major_axis(), pytype_get_inclination(),
		pytype_get_ascending_node_longitude(), pytype_get_periapsis_argument());
}

void EllipticOrbit::set_tuple(PyObject* tuple)
{
	pytype_set_eccentricity(PyTuple_GetItem(tuple, 0));
	pytype_set_semi_major_axis(PyTuple_GetItem(tuple, 1));
	pytype_set_inclination(PyTuple_GetItem(tuple, 2));
	pytype_set_ascending_node_longitude(PyTuple_GetItem(tuple, 3));
	pytype_set_periapsis_argument(PyTuple_GetItem(tuple, 4));
}
