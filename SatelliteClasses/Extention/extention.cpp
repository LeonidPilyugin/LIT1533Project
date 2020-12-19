#include <Python.h>
#include "extention.h"

// This file contains Python types functions and structs
// More information about C++ extensions for Python:
// https://docs.microsoft.com/en-us/visualstudio/python/working-with-c-cpp-python-in-visual-studio?view=vs-2019

const char* ellipse_linear_eccentricity_docstring =
"Returns linear eccentricity rectum for ellipse.\n\
Example: ellipse_linear_eccentricity(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* ellipse_semi_latus_rectum_docstring =
"Returns semi-latus rectum for ellipse.\n\
Example: ellipse_semi_latus_rectum(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* ellipse_focal_parameter_docstring =
"Returns focal parameter for ellipse.\n\
Example: ellipse_focal_parameter(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* ellipse_semi_minor_axis_docstring =
"Returns semi-minor axis for ellipse.\n\
Example: ellipse_semiminor_axis(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* ellipse_aspect_ratio_docstring =
"Returns aspect ratio for ellipse.\n\
Example: ellipse_aspect_ratio(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* ellipse_perifocus_distance_docstring =
"Returns perifocus distance for ellipse.\n\
Example: ellipse_semi_latus_rectum(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* ellipse_apothecure_distance_docstring =
"Returns apothecure distance for ellipse.\n\
Example: ellipse_apothecure_distance(tuple)\n\
tuple = (eccentricity, semi_major_axis)";

const char* elliptic_satellite_true_anomaly_docstring =
"Returns new true anomaly for ellipatical satellite.\n\
Example: ellipse_apothecure_distance(tuple, time_interval)\n\
tuple = (eccentricity, semi_major_axis, \n\
inclination, ascending_node_longitude, periapsis_argument, \n\
true_anomaly, direction_ratio, name)";

const char* elliptic_satellite_time_interval_docstring =
"Returns time interval.\n\
Example: ellipse_apothecure_distance(tuple, finish_true_anomaly)\n\
tuple = (eccentricity, semi_major_axis, \n\
inclination, ascending_node_longitude, periapsis_argument, \n\
true_anomaly, direction_ratio, name)";

static PyMethodDef methods[] =
{
	{ "compute_ellipse_linear_eccentricity",
	(PyCFunction)compute_ellipse_linear_eccentricity, METH_VARARGS,
	ellipse_linear_eccentricity_docstring },

	{ "compute_ellipse_focal_parameter",
	(PyCFunction)compute_ellipse_focal_parameter, METH_VARARGS,
	ellipse_focal_parameter_docstring },

	{ "compute_ellipse_semi_latus_rectum",
	(PyCFunction)compute_ellipse_semi_latus_rectum, METH_VARARGS,
	ellipse_semi_latus_rectum_docstring },

	{ "compute_ellipse_semi_minor_axis",
	(PyCFunction)compute_ellipse_semi_minor_axis, METH_VARARGS,
	ellipse_semi_minor_axis_docstring },

	{ "compute_ellipse_aspect_ratio",
	(PyCFunction)compute_ellipse_aspect_ratio, METH_VARARGS,
	ellipse_aspect_ratio_docstring },

	{ "compute_ellipse_perifocus_distance",
	(PyCFunction)compute_ellipse_perifocus_distance, METH_VARARGS,
	ellipse_perifocus_distance_docstring },

	{ "compute_ellipse_apothecure_distance",
	(PyCFunction)compute_ellipse_apothecure_distance, METH_VARARGS,
	ellipse_apothecure_distance_docstring },

	{ "compute_elliptic_orbit_true_anomaly",
	(PyCFunction)compute_elliptic_satellite_true_anomaly, METH_VARARGS,
	elliptic_satellite_true_anomaly_docstring },

	{ "compute_elliptic_orbit_time_interval",
	(PyCFunction)compute_elliptic_satellite_time_interval, METH_VARARGS,
	elliptic_satellite_time_interval_docstring },

	{ nullptr, nullptr, 0, nullptr }
};

const char* module_docstring = "Provides some functions, but faster";

static PyModuleDef extention_module =
{
	PyModuleDef_HEAD_INIT,
	"_speedmath",
	module_docstring,
	0,
	methods
};

PyMODINIT_FUNC PyInit__speedmath()
{
	return PyModule_Create(&extention_module);
}

// Next functions take nested tuple:
// ((object_arg1, object_arg2, ...), another_args1, another_arg2, ...)
// To get another_args1 you should use PyTuple_GetItem(args, 2)
// For another_args2 PyTuple_GetItem(args, 3), etc

static PyObject*
compute_ellipse_linear_eccentricity(PyObject*, PyObject* args)
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return ellipse.pytype_linear_eccentricity();
}

static PyObject*
compute_ellipse_focal_parameter(PyObject*, PyObject* args)
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return ellipse.pytype_focal_parameter();
}

static PyObject*
compute_ellipse_semi_latus_rectum(PyObject*, PyObject* args)
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return ellipse.pytype_semi_latus_rectum();
}

static PyObject*
compute_ellipse_semi_minor_axis(PyObject*, PyObject* args)
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return ellipse.pytype_semi_minor_axis();
}

static PyObject*
compute_ellipse_aspect_ratio(PyObject*, PyObject* args)
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return ellipse.pytype_aspect_ratio();
}

static PyObject*
compute_ellipse_perifocus_distance(PyObject*, PyObject* args)
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return ellipse.pytype_perifocus_distance();
}

static PyObject*
compute_ellipse_apothecure_distance(PyObject*, PyObject* args)
{
	Ellipse ellipse(PyTuple_GetItem(args, 0));
	return ellipse.pytype_focal_parameter();
}

static PyObject*
compute_elliptic_satellite_true_anomaly(PyObject* self, PyObject* args)
{
	EllipticSatellite satellite(PyTuple_GetItem(args, 0));
	return satellite.pytype_change_true_anomaly(PyTuple_GetItem(args, 1));
}

static PyObject*
compute_elliptic_satellite_time_interval(PyObject* self, PyObject* args)
{
	EllipticSatellite satellite(PyTuple_GetItem(args, 0));
	return satellite.pytype_time_interval(PyTuple_GetItem(args, 1));
}