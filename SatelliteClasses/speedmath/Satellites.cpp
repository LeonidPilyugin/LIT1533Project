#include "satellites.h"
#include "constants.h"
#include <cmath>



Satellite::Satellite(PyObject* tuple)
{
	true_anomaly = PyFloat_AsDouble(PyTuple_GetItem(tuple, 0));
	direction_ratio = PyFloat_AsDouble(PyTuple_GetItem(tuple, 1));
}

Satellite::Satellite(PyObject* true_anomaly, PyObject* direction_ratio)
{
	this->true_anomaly = PyFloat_AsDouble(true_anomaly);
	this->direction_ratio = PyFloat_AsDouble(direction_ratio);
}