#pragma once
#include <Python.h>

static const double GM = 3.986e14;
static const double PI = 3.14159265358979323846;

static double EllipseLinearEccentricity(const double Eccentricity, const double SemiMajorAxis);
static double EllipseFocalParameter(const double Eccentricity, const double SemiMajorAxis);
static double EllipseSemiLatusRectum(const double Eccentricity, const double SemiMajorAxis);
static double EllipseSemiminorAxis(const double Eccentricity, const double SemiMajorAxis);
static double EllipseAspectRatio(const double Eccentricity);
static double EllipsePerifocusDistance(const double Eccentricity, const double SemiMajorAxis);
static double EllipseApothecureDistance(const double Eccentricity, const double SemiMajorAxis);
static double EllipticalOrbitMeanAngularVelocity(const double SemiMajorAxis, const double DirectionRatio);
static double EllipticalOrbitMeanAnomalyByTrueAnomaly(const double Eccentricity, const double TrueAnomaly);
static double EllipticalOrbitTrueAnomalyByMeanAnomaly(const double Eccentricity, const double MeanAnomaly);
static double EllipticalOrbitTrueAnomalyByLongTineInterval(const double Eccentricity, const double SemiMajorAxis, const double TrueAnomaly, const double TimeInterval, const int DirectionRatio);
static double EllipticalOrbitOrbitalPeriod(const double SemiMajorAxis, const int DirectionRatio);
static double EllipticalOrbitTimeInterval(const double Eccentricity, const double SemiMajorAxis, const double StartTrueAnomaly, const double FinishTrueAnomaly, const int DirectionRatio);

static PyObject* PyEllipseLinearEccentricity(PyObject*, PyObject* args);
static PyObject* PyEllipseSemiLatusRectum(PyObject*, PyObject* args);
static PyObject* PyEllipseFocalParameter(PyObject*, PyObject* args);
static PyObject* PyEllipseSemiminorAxis(PyObject*, PyObject* args);
static PyObject* PyEllipseAspectRatio(PyObject*, PyObject* Eccentricity);
static PyObject* PyEllipsePerifocusDistance(PyObject*, PyObject* args);
static PyObject* PyEllipseApothecureDistance(PyObject*, PyObject* args);
static PyObject* PyEllipticalOrbitTrueAnomaly(PyObject* self, PyObject* args);
static PyObject* PyEllipticalOrbitTimeInterval(PyObject* self, PyObject* args);
