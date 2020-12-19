#include "point3D.h"
#include <cmath>



Point3D::Point3D()
{
	x = y = z = 0.0;
}

Point3D::Point3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Point3D::Point3D(PyObject* tuple)
{
	set_tuple(tuple);
}

Point3D::Point3D(PyObject* x, PyObject* y, PyObject* z)
{
	this->x = PyFloat_AsDouble(x);
	this->y = PyLong_AsLong(y);
	this->z = PyLong_AsLong(z);
}

double Point3D::get_x()
{
	return x;
}

double Point3D::get_y()
{
	return y;
}

double Point3D::get_z()
{
	return z;
}

PyObject* Point3D::pytype_get_x()
{
	return PyFloat_FromDouble(x);
}

PyObject* Point3D::pytype_get_y()
{
	return PyFloat_FromDouble(y);
}

PyObject* Point3D::pytype_get_z()
{
	return PyFloat_FromDouble(z);
}


void Point3D::set_x(double value)
{
	x = value;
}

void Point3D::set_y(double value)
{
	y = value;
}

void Point3D::set_z(double value)
{
	z = value;
}

void Point3D::pytype_set_x(PyObject* value)
{
	set_x(PyFloat_AsDouble(value));
}

void Point3D::pytype_set_y(PyObject* value)
{
	set_y(PyFloat_AsDouble(value));
}

void Point3D::pytype_set_z(PyObject* value)
{
	set_z(PyFloat_AsDouble(value));
}

PyObject* Point3D::get_tuple()
{
	return PyTuple_Pack(3, pytype_get_x(), pytype_get_y(), pytype_get_z());
}

void Point3D::set_tuple(PyObject* tuple)
{
	pytype_set_x(PyTuple_GetItem(tuple, 0));
	pytype_set_y(PyTuple_GetItem(tuple, 1));
	pytype_set_z(PyTuple_GetItem(tuple, 2));
}

double Point3D::distance_to(Point3D point)
{
	double deltax = point.x - x;
	double deltay = point.y - y;
	double deltaz = point.z - z;
	return sqrt(deltax * deltax + deltay * deltay + deltaz * deltaz);
}
