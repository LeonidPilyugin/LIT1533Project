#pragma once
#include <Python.h>

static const double GM = 3.986e14;
static const double EarthMajorSemiaxis = 6378200;
static const double EarthSemiminorAxis = 6356900;
static const double PI = 3.14159265358979323846;

static double SemiminorAxis(const double, const double);
static double SemiLatusRectum(const double, const double);
static double AspectRatio(const double);
static double FocalDistance(const double, const  double);
static double PerifocusDistance(const double, const double);
static double ApothecureDistance(const double, const double);
static double MeanAngularVelocity(const double, const double);
//static double TrueAnomalyByShortTineInterval(const double, const double, const double, const double);
static double TrueAnomalyByLongTineInterval(const double, const double, const double, const double, const double);
static double CirculationPeriod(const double, const double);
static double TimeInterval(const double, const double, const double, const double, const double);

static PyObject* PySemiminorAxis(PyObject*, PyObject*);
static PyObject* PySemiLatusRectum(PyObject*, PyObject*);
static PyObject* PyAspectRatio(PyObject*, PyObject*);
static PyObject* PyFocalDistance(PyObject*, PyObject*);
static PyObject* PyPerifocusDistance(PyObject*, PyObject*);
static PyObject* PyApothecureDistance(PyObject*, PyObject*);
//static PyObject* PyTrueAnomalyByShortTineInterval(PyObject*, PyObject*);
static PyObject* PyTrueAnomalyByLongTimeInterval(PyObject*, PyObject*);
static PyObject* PyTimeInterval(PyObject*, PyObject*);