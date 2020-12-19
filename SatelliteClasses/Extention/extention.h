#pragma once
#include "Python.h"
#include "ellipse.h"
#include "ellipticsatellite.h"



static PyObject* compute_ellipse_linear_eccentricity(PyObject*, PyObject*);

static PyObject* compute_ellipse_focal_parameter(PyObject*, PyObject*);

static PyObject* compute_ellipse_semi_latus_rectum(PyObject*, PyObject*);

static PyObject* compute_ellipse_semi_minor_axis(PyObject*, PyObject*);

static PyObject* compute_ellipse_aspect_ratio(PyObject*, PyObject*);

static PyObject* compute_ellipse_perifocus_distance(PyObject*, PyObject*);

static PyObject* compute_ellipse_apothecure_distance(PyObject*, PyObject*);

static PyObject* compute_elliptic_satellite_true_anomaly(PyObject* self, PyObject*);

static PyObject* compute_elliptic_satellite_time_interval(PyObject* self, PyObject*);