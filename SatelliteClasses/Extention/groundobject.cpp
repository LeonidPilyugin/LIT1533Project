#include "groundobject.h"
#include "usefullthings.h"
#include <cmath>



GroundObject::GroundObject()
{
	longitude = 0.0;
	latitude = 0.0;
}

GroundObject::GroundObject(double longitude, double latitude)
{
	this->longitude = longitude;
	this->latitude = latitude;
}

GroundObject::GroundObject(PyObject* tuple)
{
	set_tuple(tuple);
}

GroundObject::GroundObject(PyObject* longitude, PyObject* latitude)
{
	this->longitude = PyFloat_AsDouble(longitude);
	this->latitude = PyLong_AsLong(latitude);
}

double GroundObject::get_longitude()
{
	return longitude;
}

double GroundObject::get_latitude()
{
	return latitude;
}

PyObject* GroundObject::pytype_get_longitude()
{
	return PyFloat_FromDouble(longitude);
}

PyObject* GroundObject::pytype_get_latitude()
{
	return PyFloat_FromDouble(latitude);
}

void GroundObject::set_longitude(double value)
{
	if(!set_elliptic_angle(&longitude, value))
		throw "Longitude must be less than pi and greater than or equal to -pi";
}

void GroundObject::set_latitude(double value)
{
	if (!set_full_symmetric_angle(&longitude, value, PI/2))
		throw "Latitude must be less than pi and greater than or equal to -pi";
}

void GroundObject::pytype_set_longitude(PyObject* value)
{
	set_longitude(PyFloat_AsDouble(value));
}

void GroundObject::pytype_set_latitude(PyObject* value)
{
	set_latitude(PyFloat_AsDouble(value));
}

PyObject* GroundObject::get_tuple()
{
	return PyTuple_Pack(2, pytype_get_longitude(), pytype_get_latitude());
}

void GroundObject::set_tuple(PyObject* tuple)
{
	pytype_set_longitude(PyTuple_GetItem(tuple, 0));
	pytype_set_latitude(PyTuple_GetItem(tuple, 1));
}

Point3D GroundObject::get_point(DateTime* date_time)
{
	double x = EARTH_MEAN_RADIUS * cos(latitude) * cos(longitude);
	double y = EARTH_MEAN_RADIUS * sin(latitude);
	double z = EARTH_MEAN_RADIUS * cos(latitude) * sin(longitude);
	double star_time = get_star_time(date_time);
	double cw = cos(star_time);
	double sw = sin(star_time);

	return Point3D(cw * x + sw * y, -sw * x + cw * y, z);
}

double GroundObject::distance_to(Point3D point, DateTime* date_time)
{
	return point.distance_to(get_point(date_time));
}
