#include <cmath>
#include <Python.h>
#include "speedmath.h"
#include "ConicSections.h"
#include "c++functions.cpp"




// This file contains Python types functions and structs
// More information about C++ extensions for Python:
// https://docs.microsoft.com/en-us/visualstudio/python/working-with-c-cpp-python-in-visual-studio?view=vs-2019


const char* ellipseSemiLatusRectumDocstring =
"Returns semi-latus rectum for ellipse.\n\
Example: ellipse_semi_latus_rectum(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* ellipseLinearEccentricityDocstring =
"Returns linear eccentricity rectum for ellipse.\n\
Example: ellipse_linear_eccentricity(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* ellipseFocalParameterDocstring =
"Returns focal parameter for ellipse.\n\
Example: ellipse_focal_parameter(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* ellipseSemiminorAxisDocstring =
"Returns semi-minor axis for ellipse.\n\
Example: ellipse_semiminor_axis(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* ellipseAspectRatioDocstring =
"Returns aspect ratio for ellipse.\n\
Example: ellipse_aspect_ratio(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* ellipsePerifocusDistanceDocstring =
"Returns perifocus distance for ellipse.\n\
Example: ellipse_semi_latus_rectum(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* ellipseApothecureDistanceDocstring =
"Returns apothecure distance for ellipse.\n\
Example: ellipse_apothecure_distance(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* ellipticalSatelliteTrueAnomalyDocstring =
"Returns new true anomaly for ellipatical satellite.\n\
Example: ellipse_apothecure_distance(tuple, time_interval)\n\
tuple = (eccentricity, semi_major_axis, \n\
inclination, ascending_node_longitude, periapsis_argument, \n\
true_anomaly, direction_ratio, name)";

const char* ellipticalSatelliteTimeIntervalDocstring =
"Returns time interval.\n\
Example: ellipse_apothecure_distance(tuple, finish_true_anomaly)\n\
tuple = (eccentricity, semi_major_axis, \n\
inclination, ascending_node_longitude, periapsis_argument, \n\
true_anomaly, direction_ratio, name)";



static PyMethodDef methods[] =
{
	{ "compute_ellipse_linear_eccentricity",
	(PyCFunction)python_compute_ellipse_linear_eccentricity, METH_VARARGS,
	ellipseLinearEccentricityDocstring },

	{ "compute_ellipse_focal_parameter",
	(PyCFunction)python_compute_ellipse_focal_parameter, METH_VARARGS,
	ellipseFocalParameterDocstring },

	{ "compute_ellipse_semi_latus_rectum",
	(PyCFunction)python_compute_ellipse_semi_latus_rectum, METH_VARARGS,
	ellipseSemiLatusRectumDocstring },

	{ "ellipse_semiminor_axis",
	(PyCFunction)pyComputeEllipseSemiminorAxis, METH_VARARGS,
	ellipseSemiminorAxisDocstring },

	{ "ellipse_aspect_ratio",
	(PyCFunction)pyComputeEllipseAspectRatio, METH_VARARGS,
	ellipseAspectRatioDocstring },

	{ "ellipse_perifocus_distance",
	(PyCFunction)pyComputeEllipsePerifocusDistance, METH_VARARGS,
	ellipsePerifocusDistanceDocstring },

	{ "ellipse_apothecure_distance",
	(PyCFunction)pyComputeEllipseApothecureDistance, METH_VARARGS,
	ellipseApothecureDistanceDocstring },

	{ "elliptic_orbit_true_anomaly",
	(PyCFunction)pyComputeEllipticOrbitTrueAnomaly, METH_VARARGS,
	ellipticalSatelliteTrueAnomalyDocstring },

	{ "elliptic_orbit_time_interval",
	(PyCFunction)pyComputeEllipticOrbitTimeInterval, METH_VARARGS,
	ellipticalSatelliteTimeIntervalDocstring },

	{ nullptr, nullptr, 0, nullptr }
};

const char* moduleDocstring = "Provides some functions, but faster";

static PyModuleDef speedMathModule =
{
	PyModuleDef_HEAD_INIT,
	"speedmath",
	moduleDocstring,
	0,
	methods
};



PyMODINIT_FUNC PyInit_speedmath()
{
	return PyModule_Create(&speedMathModule);
}



static void 
collect_orbit(Orbit* orbit, PyObject* tuple)
{
	collect_conic_section(orbit, tuple);
	orbit->inclination = PyFloat_AsDouble(PyTuple_GetItem(tuple, 2));
	orbit->ascending_node_longitude = PyFloat_AsDouble(PyTuple_GetItem(tuple, 3));
	orbit->periapsisArgument = PyFloat_AsDouble(PyTuple_GetItem(tuple, 4));
}



static void 
collect_satellite(Satellite* satellite, PyObject* tuple)
{
	collect_conic_section(satellite, tuple);
	satellite->true_anomaly = PyFloat_AsDouble(PyTuple_GetItem(tuple, 5));
	satellite->direction_ratio = (int)PyLong_AsLong(PyTuple_GetItem(tuple, 6));
}



// Next functions take nested tuple:
// ((object_arg1, object_arg2, ...), another_args1, another_arg2, ...)
// To get another_args1 you should use PyTuple_GetItem(args, 2)
// For another_args2 PyTuple_GetItem(args, 3), etc



static PyObject* 
python_compute_ellipse_linear_eccentricity(PyObject*, PyObject* args)
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return PyFloat_FromDouble(ellipse.linear_eccentricity());
}



static PyObject*
python_compute_ellipse_focal_parameter(PyObject*, PyObject* args)
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return PyFloat_FromDouble(ellipse.focal_parameter());
}



static PyObject* 
python_compute_ellipse_semi_latus_rectum(PyObject*, PyObject* args)
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return PyFloat_FromDouble(ellipse.semi_latus_rectum());
}



static PyObject* 
pyComputeEllipseSemiminorAxis(PyObject*, PyObject* args) 
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return PyFloat_FromDouble(ellipse.semi_minor_axis());
}



static PyObject* 
pyComputeEllipseAspectRatio(PyObject*, PyObject* args)
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return PyFloat_FromDouble(ellipse.aspect_ratio());
}



static PyObject* 
pyComputeEllipsePerifocusDistance(PyObject*, PyObject* args) 
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return PyFloat_FromDouble(ellipse.perifocus_distance());
}



static PyObject* 
pyComputeEllipseApothecureDistance(PyObject*, PyObject* args) 
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return PyFloat_FromDouble(ellipse.apothecure_distance());
}



static PyObject* 
pyComputeEllipticOrbitTrueAnomaly(PyObject* self, PyObject* args) 
{
	Satellite satellite;
	collect_conic_section(&satellite, PyTuple_GetItem(args, 0));
	double timeInterval = PyFloat_AsDouble(PyTuple_GetItem(args, 1));

	return PyFloat_FromDouble(computeEllipticOrbitTrueAnomalyByTimeInterval(
		   &satellite, timeInterval));
}



static PyObject* 
pyComputeEllipticOrbitTimeInterval(PyObject* self, PyObject* args) 
{
	Satellite satellite;
	collect_conic_section(&satellite, PyTuple_GetItem(args, 0));
	double finishTrueAnomaly = PyFloat_AsDouble(PyTuple_GetItem(args, 1));

	return PyFloat_FromDouble(computeEllipticOrbitTrueAnomalyByTimeInterval(
		   &satellite, finishTrueAnomaly));
}