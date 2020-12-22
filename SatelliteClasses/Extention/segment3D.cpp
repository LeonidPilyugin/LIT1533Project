#include "segment3D.h"
#include "object3D.h"
#include <cmath>



Segment3D::Segment3D() :
	Segment3D(0, 0, 0, 1, 1, 1)
{

}

Segment3D::Segment3D(Point3D first, Point3D last)
{
	this->first = first;
	this->last = last;
}

Segment3D::Segment3D(double x1, double y1, double z1, double x2, double y2, double z2) :
	Segment3D(Point3D(x1, y1, z1), Point3D(x2, y2, z2))
{

}

Segment3D::Segment3D(PyObject* tuple) :
	Segment3D(PyTuple_GetItem(tuple, 0), PyTuple_GetItem(tuple, 1), PyTuple_GetItem(tuple, 2),
		PyTuple_GetItem(tuple, 3), PyTuple_GetItem(tuple, 4), PyTuple_GetItem(tuple, 5))
{

}

Segment3D::Segment3D(PyObject* x1, PyObject* y1, PyObject* z1, PyObject* x2, PyObject* y2, PyObject* z2) :
	Segment3D(PyFloat_AsDouble(x1), PyFloat_AsDouble(y1), PyFloat_AsDouble(z1),
		PyFloat_AsDouble(x2), PyFloat_AsDouble(y2), PyFloat_AsDouble(z2))
{

}

Point3D Segment3D::get_first()
{
	return first;
}

Point3D Segment3D::get_last()
{
	return last;
}

PyObject* Segment3D::get_tuple()
{
	return PyTuple_Pack(6, first.pytype_get_x(), first.pytype_get_y(), first.pytype_get_z(),
		last.pytype_get_x(), last.pytype_get_y(), last.pytype_get_z());
}

void Segment3D::set_tuple(PyObject* tuple)
{
	first = Point3D(PyTuple_GetItem(tuple, 0), PyTuple_GetItem(tuple, 1), PyTuple_GetItem(tuple, 2));
	last = Point3D(PyTuple_GetItem(tuple, 3), PyTuple_GetItem(tuple, 4), PyTuple_GetItem(tuple, 5));
}

double Segment3D::length()
{
	return first.distance_to(last);
}

double Segment3D::distance_to(Point3D point)
{
	// Find area of triangle(first; point; last)
	double a = first.distance_to(point);
	double b = point.distance_to(last);
	double c = last.distance_to(first);
	double semi_perimeter = (a + b + c) / 2.0;
	double area = sqrt(semi_perimeter * (semi_perimeter - a) *
		(semi_perimeter - b) * (semi_perimeter - c));

	// Area is also equal to distance * c
	return area * 2.0 / c;
}

/*Point3D Segment3D::perpendicular_base(Point3D point)
{
	double h = distance_to(point);
	double a = first.distance_to(point);
	double b = point.distance_to(last);
	double c = last.distance_to(first);
	double l = sqrt(a * a - h * h); // Get distance between first and perpendicular base

}*/

bool Segment3D::is_crossing(Object3D object)
{
	double h = distance_to(object.get_center());
	double a = first.distance_to(object.get_center());
	double b = last.distance_to(object.get_center());
	double c = length();

	if (object.get_radius() < h)
		return false;
	if (c < sqrt(a * a - h * h) || c < sqrt(b * b - h * h))
		return false;
	return true;
}