#include "ellipticsatellite.h"




EllipticSatellite::EllipticSatellite() : Satellite(), EllipticOrbit()
{

}

EllipticSatellite::EllipticSatellite(double eccentricity, double semi_major_axis,
	double inclination, double ascending_node_longitude, double periapsis_argument,
	double true_anomaly, int direction_ratio) :
	Satellite(true_anomaly, direction_ratio),
	EllipticOrbit(eccentricity, semi_major_axis, inclination,
		ascending_node_longitude, periapsis_argument)
{

}

EllipticSatellite::EllipticSatellite(PyObject* tuple) :
	Satellite(PyTuple_GetItem(tuple, 5), PyTuple_GetItem(tuple, 6)),
	EllipticOrbit(PyTuple_GetItem(tuple, 0), PyTuple_GetItem(tuple, 1), PyTuple_GetItem(tuple, 2),
		PyTuple_GetItem(tuple, 3), PyTuple_GetItem(tuple, 4))
{
}

EllipticSatellite::EllipticSatellite(PyObject* eccentricity, PyObject* semi_major_axis,
	PyObject* inclination, PyObject* ascending_node_longitude, PyObject* periapsis_argument,
	PyObject* true_anomaly, PyObject* direction_ratio) :
	Satellite(true_anomaly, direction_ratio),
	EllipticOrbit(eccentricity, semi_major_axis, inclination,
		ascending_node_longitude, periapsis_argument)
{

}

PyObject* EllipticSatellite::get_tuple()
{
	return PyTuple_Pack(7, pytype_get_eccentricity(),
		pytype_get_semi_major_axis(), pytype_get_inclination(),
		pytype_get_ascending_node_longitude(), pytype_get_periapsis_argument(),
		pytype_get_true_anomaly(), pytype_get_direction_ratio());
}

void EllipticSatellite::set_tuple(PyObject* tuple)
{
	pytype_set_eccentricity(PyTuple_GetItem(tuple, 0));
	pytype_set_semi_major_axis(PyTuple_GetItem(tuple, 1));
	pytype_set_inclination(PyTuple_GetItem(tuple, 2));
	pytype_set_ascending_node_longitude(PyTuple_GetItem(tuple, 3));
	pytype_set_periapsis_argument(PyTuple_GetItem(tuple, 4));
	pytype_set_true_anomaly(PyTuple_GetItem(tuple, 5));
	pytype_set_direction_ratio(PyTuple_GetItem(tuple, 6));
}

Point3D EllipticSatellite::get_point()
{
	double x = distance_to_Earth() * (cos(true_anomaly + periapsis_argument) *
		cos(ascending_node_longitude) - sin(true_anomaly + periapsis_argument) *
		sin(ascending_node_longitude) * cos(inclination));

	double y = distance_to_Earth() * (cos(true_anomaly + periapsis_argument) *
		sin(ascending_node_longitude) - sin(true_anomaly + periapsis_argument) *
		cos(ascending_node_longitude) * cos(inclination));

	double z = distance_to_Earth() * sin(true_anomaly + periapsis_argument) *
		sin(inclination);

	return Point3D(x, y, z);
}

double EllipticSatellite::mean_angular_velocity()
{
	return sqrt(GM / semi_major_axis / semi_major_axis / semi_major_axis) * direction_ratio;
}

double EllipticSatellite::eccentric_anomaly(double true_anomaly)
{
	// Without this operator in case eccentricity == 0, 
	// function won't work correctly

	if (eccentricity == 0.0)
		return true_anomaly;

	// Without ROUNDING_CONSTANT eccentricity may be nan, because
	// acos takes value between -1 and 1

	double eccentric_anomaly = acos(floor((1 - (1 - eccentricity * eccentricity
		) / (1 + eccentricity * cos(true_anomaly))) /
		eccentricity * ROUNDING_CONSTANT) / ROUNDING_CONSTANT);

	// If sin(trueAnomaly) < 0, eccentric anomaly < 0,
	// but 0 <= acos() <= PI

	if (sin(true_anomaly) < 0)
		eccentric_anomaly = -eccentric_anomaly;

	return eccentric_anomaly;
}

double EllipticSatellite::eccentric_anomaly()
{
	return eccentric_anomaly(true_anomaly);
}

double EllipticSatellite::mean_anomaly(double true_anomaly)
{
	double eccentric_anomaly = this->eccentric_anomaly(true_anomaly);
	return eccentric_anomaly - eccentricity * sin(eccentric_anomaly);
}

double EllipticSatellite::mean_anomaly()
{
	return mean_anomaly(true_anomaly);
}

double EllipticSatellite::orbital_period()
{
	return 2 * PI / mean_angular_velocity() * direction_ratio;
}

double EllipticSatellite::true_anomaly_by_mean_anomaly(double mean_anomaly)
{
	// This function solves Kepler equation by fixed-point iteration method
	// More information:
	// https://en.wikipedia.org/wiki/Kepler%27s_equation#Fixed-point_iteration

	double eccentric_anomaly = mean_anomaly;

	for (int i = 0; i < ITERATION_CONSTANT; i++)
		eccentric_anomaly = eccentricity * sin(eccentric_anomaly) + mean_anomaly;

	double true_anomaly = acos((cos(eccentric_anomaly) - eccentricity) /
		(1 - eccentricity * cos(eccentric_anomaly)));

	if (sin(eccentric_anomaly) < 0)
		true_anomaly = -true_anomaly;

	return true_anomaly;
}

double EllipticSatellite::change_true_anomaly(double time_interval)
{
	// This function computes satellite's new true anomaly after 
	// a period of time
	// Satellite's eccentricity must be less then 0.8, otherwise
	// the function will produce a result with a large error
	true_anomaly = true_anomaly_by_mean_anomaly(mean_angular_velocity() * time_interval + mean_anomaly());
	return true_anomaly;
}

double EllipticSatellite::time_interval(double finish_true_anomaly)
{
	// This function returns the time interval for the satellite 
	// to reach the specified point in orbit

	double DeltaTrueAnomaly =
		mean_anomaly(finish_true_anomaly) - mean_anomaly();

	double TimeInterval = DeltaTrueAnomaly / mean_angular_velocity();

	if (TimeInterval < 0)
		TimeInterval += orbital_period();

	return TimeInterval;
}

PyObject* EllipticSatellite::pytype_change_true_anomaly(PyObject* time_interval)
{
	return PyFloat_FromDouble(change_true_anomaly(PyFloat_AsDouble(time_interval)));
}

PyObject* EllipticSatellite::pytype_time_interval(PyObject* finish_true_anomaly)
{
	return PyFloat_FromDouble(time_interval(PyFloat_AsDouble(finish_true_anomaly)));
}

double EllipticSatellite::distance_to_Earth()
{
	return semi_latus_rectum() / (1 + eccentricity * cos(true_anomaly));
}

double EllipticSatellite::distance_to_point(Point3D point)
{
	return point.distance_to(get_point());
}