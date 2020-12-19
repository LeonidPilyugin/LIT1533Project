#include "object3D.h"




Object3D::Object3D()
{
	center = Point3D();
	radius = 10.0;
}

Object3D::Object3D(Point3D center, double radius)
{
	this->center = center;
	this->radius = radius;
}

Object3D::Object3D(double x, double y, double z, double radius)
{
	center = Point3D(x, y, z);
	this->radius = radius;
}

Object3D::Object3D(PyObject* tuple)
{
	set_tuple(tuple);
}

Object3D::Object3D(PyObject* x, PyObject* y, PyObject* z, PyObject* radius)
{
	center = Point3D(x, y, z);
	this->radius = PyFloat_AsDouble(radius);
}

Point3D Object3D::get_center()
{
	return center;
}

double Object3D::get_radius()
{
	return radius;
}

PyObject* Object3D::pytype_get_radius()
{
	return PyFloat_FromDouble(radius);
}

void Object3D::set_radius(double value)
{
	if (value > 0.0)
		radius = value;
	else
		throw "Radius must be a positive number";
}

void Object3D::pytype_set_radius(PyObject* value)
{
	set_radius(PyFloat_AsDouble(value));
}

PyObject* Object3D::get_tuple()
{
	return PyTuple_Pack(4, center.pytype_get_x(), center.pytype_get_y(),
		center.pytype_get_z(), radius);
}

void Object3D::set_tuple(PyObject* tuple)
{
	center = Point3D(PyTuple_GetItem(tuple, 0), PyTuple_GetItem(tuple, 1), PyTuple_GetItem(tuple, 2));
	radius = PyFloat_AsDouble(PyTuple_GetItem(tuple, 3));
}