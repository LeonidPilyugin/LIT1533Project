#pragma once
#include <Python.h>




static const double ROUNDING_CONSTANT = 1000000000000000.0;
static const int ITERATION_CONSTANT = 100;
static const double GM = 3.986e14;
static const double PI = 3.14159265358979323846;
static const double ANGLE_BETWEEN_ECLIPTIC_AND_EQUATOR = 0.818185;
static const double EARTH_SEMI_MAJOR_AXIS = 6378245.0;
static const double EARTH_ECCENTRICITY = 0.081813;
static const double EARTH_ANGULAR_VELOCITY_AROUND_AXIS = 2 * PI / 86400.0;




struct GroundObject {
	double longitude = 0.0;
	double latitude = 0.0;
};



//static double compute_ellipse_linear_eccentricity(ConicSection*);

//static double compute_ellipse_focal_parameter(ConicSection*);

//static double compute_ellipse_semi_latus_rectum(ConicSection*);

//static double compute_ellipse_semi_minor_axis(ConicSection*);

//static double compute_ellipse_aspect_ratio(ConicSection*);

//static double compute_ellipse_perifocus_distance(ConicSection*);

//static double compute_ellipse_apothecure_distance(ConicSection*);

static double compute_elliptical_satellite_mean_angular_velocity(Satellite*);

static double compute_elliptic_orbit_eccentric_anomaly(double, double);

static double compute_elliptic_orbit_mean_anomaly_by_true_anomaly(double, double);

static double compute_elliptic_orbit_true_anomaly_by_mean_anomaly(double, double);

static double compute_elliptic_orbit_true_anomaly_by_time_interval(Satellite*, double);

static double compute_orbital_period(Satellite*);

static double compute_elliptical_satellite_time_interval(Satellite*, double);

static double compute_distance_to_satellite(Satellite*);

static bool can_shoot(Satellite*, GroundObject*);

static double compute_time_to_shoot(Satellite*, GroundObject*);



static PyObject* python_compute_ellipse_linear_eccentricity(PyObject*, PyObject*);

static PyObject* python_compute_ellipse_focal_parameter(PyObject*, PyObject*);

static PyObject* python_compute_ellipse_semi_latus_rectum(PyObject*, PyObject*);

static PyObject* python_compute_ellipse_semi_minor_axis(PyObject*, PyObject*);

static PyObject* python_compute_ellipse_aspect_ratio(PyObject*, PyObject*);

static PyObject* python_compute_ellipse_perifocus_distance(PyObject*, PyObject*);

static PyObject* python_compute_ellipse_apothecure_distance(PyObject*, PyObject*);

static PyObject* python_compute_elliptical_satellite_true_anomaly(PyObject*, PyObject*);

static PyObject* python_compute_elliptical_satellite_time_interval(PyObject*, PyObject*);
