#pragma once
#include "orbit.h"
#include "satellite.h"
#include "ellipticorbit.h"


class EllipticSatellite : public Satellite, public EllipticOrbit
{
protected:
	double mean_angular_velocity(void);
	double eccentric_anomaly(double);
	double eccentric_anomaly(void);
	double mean_anomaly(double);
	double mean_anomaly(void);
	double orbital_period(void);
	double true_anomaly_by_mean_anomaly(double);

public:
	EllipticSatellite();
	EllipticSatellite(double, double, double, double, double, double, int);
	EllipticSatellite(PyObject*);
	EllipticSatellite(PyObject*, PyObject*, PyObject*, PyObject*,
		PyObject*, PyObject*, PyObject*);

	PyObject* get_tuple();                  // Returns tuple: (eccentricity, semi_major_axis, inclination, ascending_node_longitude, periapsis_argument, true_anomaly, direction_ratio)
	void set_tuple(PyObject*);              // Sets fields from a tuple. Argument must be a tuple: (eccentricity, semi_major_axis, inclination, ascending_node_longitude, periapsis_argument, true_anomaly, direction_ratio)

	Point3D get_point();

	double change_true_anomaly(double);
	double time_interval(double);

	PyObject* pytype_change_true_anomaly(PyObject*);
	PyObject* pytype_time_interval(PyObject*);

	double distance_to_point(Point3D);
	double distance_to_Earth();
};

