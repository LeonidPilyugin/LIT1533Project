#include "satellite.h"
#include <cmath>

// This module contains description of the methods of the classes Satellite and EllipticSatellite

Satellite::Satellite()
{
	true_anomaly = 0.0;
	direction_ratio = 1;
}

Satellite::Satellite(double true_anomaly, int direction_ratio)
{
	this->true_anomaly = true_anomaly;
	this->direction_ratio = direction_ratio;
}

Satellite::Satellite(PyObject* tuple)
{
	set_tuple(tuple);
}

Satellite::Satellite(PyObject* true_anomaly, PyObject* direction_ratio)
{
	this->true_anomaly = PyFloat_AsDouble(true_anomaly);
	this->direction_ratio = PyLong_AsLong(direction_ratio);
}

double Satellite::get_true_anomaly()
{
	return true_anomaly;
}

int Satellite::get_direction_ratio()
{
	return direction_ratio;
}

PyObject* Satellite::pytype_get_true_anomaly()
{
	return PyFloat_FromDouble(true_anomaly);
}

PyObject* Satellite::pytype_get_direction_ratio()
{
	return PyLong_FromLong(direction_ratio);
}

void Satellite::set_true_anomaly(double value)
{
	if (!set_elliptic_angle(&true_anomaly, value))
		throw "True anomaly must be less than pi and greater than or equal to -pi";
}

void Satellite::set_direction_ratio(double value)
{
	if (value == 1 || value == -1)
		direction_ratio = value;
	else
		throw "Direction ratio must be 1 or -1";
}

void Satellite::pytype_set_true_anomaly(PyObject* value)
{
	set_true_anomaly(PyFloat_AsDouble(value));
}

void Satellite::pytype_set_direction_ratio(PyObject* value)
{
	set_direction_ratio(PyFloat_AsDouble(value));
}

PyObject* Satellite::get_tuple()
{
	return PyTuple_Pack(2, pytype_get_true_anomaly(), pytype_get_direction_ratio());
}

void Satellite::set_tuple(PyObject* tuple)
{
	pytype_set_true_anomaly(PyTuple_GetItem(tuple, 0));
	pytype_set_direction_ratio(PyTuple_GetItem(tuple, 1));
}