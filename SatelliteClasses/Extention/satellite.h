#pragma once
#include <Python.h>
#include "point3D.h"
#include "usefullthings.h"

// This module contains description of the classes Satellite and EllipticSatellite
// Other satellite classes should be described here
// 
// Satellite is parent class for other satellites
// 
// EllipticSatellite describes elliptic satellite (0 <= eccentricity < 1)

class Satellite
{
protected:
	double true_anomaly;
	int direction_ratio;                 // This is a number (1 or -1), which shows direction of rotation (1 if d(true_anomaly)/dt > 0, otherwise -1)
	
public:
	Satellite();                         // Sets true_anomaly = 0.0, diretion_ratio = 1
	Satellite(double, int);              // Order of arguments: true_anomaly, diretion_ratio
	Satellite(PyObject*);                // Argument must be a tuple: (true_anomaly, diretion_ratio)
	Satellite(PyObject*, PyObject*);     // Sets fields from a tuple. Argument must be a tuple: (true_anomaly, diretion_ratio)

	double get_true_anomaly();
	int get_direction_ratio();
	PyObject* pytype_get_true_anomaly();
	PyObject* pytype_get_direction_ratio();

	void set_true_anomaly(double);
	void set_direction_ratio(double);
	void pytype_set_true_anomaly(PyObject*);
	void pytype_set_direction_ratio(PyObject*);

	PyObject* get_tuple();                  // Returns tuple: (true_anomaly, direction_ratio)
	void set_tuple(PyObject*);              // Sets fields from a tuple. Argument must be a tuple: (true_anomaly, direction_ratio)

	virtual Point3D get_point() = 0;

	virtual double change_true_anomaly(double) = 0; // Changes true_anomaly by time interval, returns new true_anomaly
	virtual double time_interval(double) = 0;       // Returns time interval after which true_anomaly will be equal to argument

	virtual PyObject* pytype_change_true_anomaly(PyObject*) = 0;
	virtual PyObject* pytype_time_interval(PyObject*) = 0;

	virtual double distance_to_point(Point3D) = 0;
	virtual double distance_to_Earth() = 0;
};



