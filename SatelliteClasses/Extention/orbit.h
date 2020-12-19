#pragma once
#include <Python.h>

// This module contains description of the classes Orbit and EllipticOrbit
// Other orbit classes should be described here
// 
// Orbit is parent class for other orbits
// Information about orbits: 
// https://en.wikipedia.org/wiki/Orbit
// 
// EllipticOrbit describes elliptic orbit (0 <= eccentricity < 1)

class Orbit
{
protected:
	double inclination;
	double ascending_node_longitude;
	double periapsis_argument;

public:
	Orbit();                                // Sets inclination = 0.0, ascending_node_longitude = 0.0, periapsis_argument = 0.0
	Orbit(double, double, double);          // Order of arguments: inclination, ascending_node_longitude, periapsis_argument
	Orbit(PyObject*);                       // Argument must be a tuple: (inclination, ascending_node_longitude, periapsis_argument)
	Orbit(PyObject*, PyObject*, PyObject*); // Order of arguments: inclination, ascending_node_longitude, periapsis_argument

	double get_inclination();
	double get_ascending_node_longitude();
	double get_periapsis_argument();
	PyObject* pytype_get_inclination();
	PyObject* pytype_get_ascending_node_longitude();
	PyObject* pytype_get_periapsis_argument();

	void set_inclination(double);
	void set_ascending_node_longitude(double);
	void set_periapsis_argument(double);
	void pytype_set_inclination(PyObject*);
	void pytype_set_ascending_node_longitude(PyObject*);
	void pytype_set_periapsis_argument(PyObject*);

	PyObject* get_tuple();                  // Returns tuple: (inclination, ascending_node_longitude, periapsis_argument)
	void set_tuple(PyObject*);              // Sets fields from a tuple. Argument must be a tuple: (inclination, ascending_node_longitude, periapsis_argument)
};