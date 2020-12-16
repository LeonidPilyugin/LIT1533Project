#pragma once
#include <Python.h>
#include "conic_sections.h"


class Orbit
{
protected:
	double inclination;
	double ascending_node_longitude;
	double periapsis_argument;

public:
	Orbit(PyObject*);
	Orbit(PyObject*, PyObject*, PyObject*);
};



class EllipticOrbit : public Orbit, public Ellipse
{
public:
	EllipticOrbit(PyObject*);
	EllipticOrbit(PyObject*, PyObject*, PyObject*, PyObject*, PyObject*);
};

