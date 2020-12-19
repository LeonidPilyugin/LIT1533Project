#pragma once
#include <Python.h>
#include "orbit.h"
#include "ellipse.h"

// This module contains description of the classes Orbit and EllipticOrbit
// Other orbit classes should be described here
// 
// Orbit is parent class for other orbits
// Information about orbits: 
// https://en.wikipedia.org/wiki/Orbit
// 
// EllipticOrbit describes elliptic orbit (0 <= eccentricity < 1)

class EllipticOrbit : public Orbit, public Ellipse
{
public:
	EllipticOrbit();
	EllipticOrbit(double, double, double, double, double);
	EllipticOrbit(PyObject*);
	EllipticOrbit(PyObject*, PyObject*, PyObject*, PyObject*, PyObject*);

	PyObject* get_tuple();                  // Returns tuple: (eccentricity, semi_major_axis, inclination, ascending_node_longitude, periapsis_argument)
	void set_tuple(PyObject*);              // Sets fields from a tuple. Argument must be a tuple: (eccentricity, semi_major_axis, inclination, ascending_node_longitude, periapsis_argument)
};



