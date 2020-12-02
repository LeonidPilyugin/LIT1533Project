#include <cmath>
#include "speedmath.h"
#include <Python.h>

static double EllipseLinearEccentricity(const double Eccentricity, const double SemiMajorAxis) {
	return SemiMajorAxis * Eccentricity;
}

static double EllipseFocalParameter(const double Eccentricity, const double SemiMajorAxis) {
	return SemiMajorAxis * (1 - Eccentricity * Eccentricity) / Eccentricity;
}

static double EllipseSemiLatusRectum(const double Eccentricity, const double SemiMajorAxis) {
	return SemiMajorAxis * (1 - Eccentricity * Eccentricity);
}

static double EllipseSemiminorAxis(const double Eccentricity, const double SemiMajorAxis) {
	return SemiMajorAxis * sqrt(1 - Eccentricity * Eccentricity);
}

static double EllipseAspectRatio(const double Eccentricity) {
	return sqrt(1 - Eccentricity * Eccentricity);
}

static double EllipsePerifocusDistance(const double Eccentricity, const double SemiMajorAxis) {
	return SemiMajorAxis * (1 - Eccentricity);
}

static double EllipseApothecureDistance(const double Eccentricity, const double SemiMajorAxis) {
	return SemiMajorAxis * (1 + Eccentricity);
}

//static double AngularVelocity(const double Eccentricity, const double SemiMajorAxis, const double TrueAnomaly, const double DirectionRatio) {
//	double FocalParameter_ = SemiLatusRectum(Eccentricity, SemiMajorAxis);
//	double temp = 1 + Eccentricity * cos(TrueAnomaly);
//	return sqrt(GM * FocalParameter_) / FocalParameter_ / FocalParameter_ * temp * temp;
//}

//static double TrueAnomalyByShortTineInterval(const double Eccentricity, const double SemiMajorAxis, const double TrueAnomaly, const double TimeInterval) {
//	double NewTrueAnomaly = AngularVelocity(Eccentricity, SemiMajorAxis, TrueAnomaly) * TimeInterval + TrueAnomaly;
//	while (NewTrueAnomaly >= PI)
//		NewTrueAnomaly -= 2 * PI;
//	return NewTrueAnomaly;
//}

static double EllipticalOrbitMeanAngularVelocity(const double SemiMajorAxis, const double DirectionRatio) {
	return sqrt(GM / SemiMajorAxis / SemiMajorAxis / SemiMajorAxis) * DirectionRatio;
}

static double EllipticalOrbitMeanAnomalyByTrueAnomaly(const double Eccentricity, const double TrueAnomaly) {
	if (Eccentricity == 0)
		return TrueAnomaly;
	double EccentricAnomaly = acos(floor((1 - (1 - Eccentricity * Eccentricity) / (1 + Eccentricity * cos(TrueAnomaly))) / Eccentricity * 1000000000000000) / 1000000000000000.0);
	if (sin(TrueAnomaly) < 0)
		EccentricAnomaly = -EccentricAnomaly;
	return EccentricAnomaly - Eccentricity * sin(EccentricAnomaly);
}

static double EllipticalOrbitTrueAnomalyByMeanAnomaly(const double Eccentricity, const double MeanAnomaly) {
	double EccentricAnomaly = MeanAnomaly;
	for (int i = 0; i < 100; i++)
		EccentricAnomaly = Eccentricity * sin(EccentricAnomaly) + MeanAnomaly;
	double TrueAnomaly = acos((cos(EccentricAnomaly) - Eccentricity) / (1 - Eccentricity * cos(EccentricAnomaly)));
	if (sin(EccentricAnomaly) < 0)
		TrueAnomaly = -TrueAnomaly;
	return TrueAnomaly;
}

static double EllipticalOrbitTrueAnomalyByLongTineInterval(const double Eccentricity, const double SemiMajorAxis, const double TrueAnomaly, const double TimeInterval, const int DirectionRatio) {
	return EllipticalOrbitTrueAnomalyByMeanAnomaly(Eccentricity, EllipticalOrbitMeanAngularVelocity(SemiMajorAxis, DirectionRatio) * TimeInterval + EllipticalOrbitMeanAnomalyByTrueAnomaly(Eccentricity, TrueAnomaly));
}

static double EllipticalOrbitOrbitalPeriod(const double SemiMajorAxis, const int DirectionRatio) {
	return 2 * PI / EllipticalOrbitMeanAngularVelocity(SemiMajorAxis, DirectionRatio) * DirectionRatio;
}

static double EllipticalOrbitTimeInterval(const double Eccentricity, const double SemiMajorAxis, const double StartTrueAnomaly, const double FinishTrueAnomaly, const int DirectionRatio) {
	double DeltaTrueAnomaly = EllipticalOrbitMeanAnomalyByTrueAnomaly(Eccentricity, FinishTrueAnomaly) - EllipticalOrbitMeanAnomalyByTrueAnomaly(Eccentricity, StartTrueAnomaly);
	double TimeInterval = DeltaTrueAnomaly / EllipticalOrbitMeanAngularVelocity(SemiMajorAxis, DirectionRatio);
	if (TimeInterval < 0)
		TimeInterval += EllipticalOrbitOrbitalPeriod(SemiMajorAxis, DirectionRatio);
	return TimeInterval;
}

static PyObject* PyEllipseLinearEccentricity(PyObject*, PyObject* args) {
	double Eccentricity, SemiMajorAxis;
	if (!PyArg_ParseTuple(args, "dd", &Eccentricity, &SemiMajorAxis)) {
		return nullptr;
	}
	return PyFloat_FromDouble(EllipseLinearEccentricity(Eccentricity, SemiMajorAxis));
}

static PyObject* PyEllipseSemiLatusRectum(PyObject*, PyObject* args) {
	double Eccentricity, SemiMajorAxis;
	if (!PyArg_ParseTuple(args, "dd", &Eccentricity, &SemiMajorAxis)) {
		return nullptr;
	}
	return PyFloat_FromDouble(EllipseSemiLatusRectum(Eccentricity, SemiMajorAxis));
}

static PyObject* PyEllipseFocalParameter(PyObject*, PyObject* args) {
	double Eccentricity, SemiMajorAxis;
	if (!PyArg_ParseTuple(args, "dd", &Eccentricity, &SemiMajorAxis)) {
		return nullptr;
	}
	return PyFloat_FromDouble(EllipseFocalParameter(Eccentricity, SemiMajorAxis));
}

static PyObject* PyEllipseSemiminorAxis(PyObject*, PyObject* args) {
	double Eccentricity, SemiMajorAxis;
	if (!PyArg_ParseTuple(args, "dd", &Eccentricity, &SemiMajorAxis)) {
		return nullptr;
	}
	return PyFloat_FromDouble(EllipseSemiminorAxis(Eccentricity, SemiMajorAxis));
}

static PyObject* PyEllipseAspectRatio(PyObject*, PyObject* Eccentricity) {
	return PyFloat_FromDouble(EllipseAspectRatio(PyFloat_AsDouble(Eccentricity)));
}

static PyObject* PyEllipsePerifocusDistance(PyObject*, PyObject* args) {
	double Eccentricity, SemiMajorAxis;
	if (!PyArg_ParseTuple(args, "dd", &Eccentricity, &SemiMajorAxis)) {
		return nullptr;
	}
	return PyFloat_FromDouble(EllipsePerifocusDistance(Eccentricity, SemiMajorAxis));
}

static PyObject* PyEllipseApothecureDistance(PyObject*, PyObject* args) {
	double Eccentricity, SemiMajorAxis;
	if (!PyArg_ParseTuple(args, "dd", &Eccentricity, &SemiMajorAxis)) {
		return nullptr;
	}
	return PyFloat_FromDouble(EllipseApothecureDistance(Eccentricity, SemiMajorAxis));
}

//static PyObject* PyTrueAnomalyByShortTineInterval(PyObject* self, PyObject* args) {
//	double Eccentricity, SemiMajorAxis, TrueAnomaly, TimeInterval;
//	if (!PyArg_ParseTuple(args, "dddd", &Eccentricity, &SemiMajorAxis, &TrueAnomaly, &TimeInterval)) {
//		return nullptr;
//	}
//	return PyFloat_FromDouble(TrueAnomalyByShortTineInterval(Eccentricity, SemiMajorAxis, TrueAnomaly, TimeInterval));
//}

static PyObject* PyEllipticalOrbitTrueAnomaly(PyObject* self, PyObject* args) {
	double Eccentricity, SemiMajorAxis, TrueAnomaly, TimeInterval;
	int DirectionRatio;
	if (!PyArg_ParseTuple(args, "ddddi", &Eccentricity, &SemiMajorAxis, &TrueAnomaly, &TimeInterval, &DirectionRatio)) {
		return nullptr;
	}
	return PyFloat_FromDouble(EllipticalOrbitTrueAnomalyByLongTineInterval(Eccentricity, SemiMajorAxis, TrueAnomaly, TimeInterval, DirectionRatio));
}

static PyObject* PyEllipticalOrbitTimeInterval(PyObject* self, PyObject* args) {
	double Eccentricity, SemiMajorAxis, StartTrueAnomaly, FinishTrueAnomaly;
	int DirectionRatio;
	if (!PyArg_ParseTuple(args, "ddddi", &Eccentricity, &SemiMajorAxis, &StartTrueAnomaly, &FinishTrueAnomaly, &DirectionRatio)) {
		return nullptr;
	}
	return PyFloat_FromDouble(EllipticalOrbitTimeInterval(Eccentricity, SemiMajorAxis, StartTrueAnomaly, FinishTrueAnomaly, DirectionRatio));
}

static PyMethodDef Methods[] = {
	{ "EllipseSemiLatusRectum", (PyCFunction)PyEllipseSemiLatusRectum, METH_VARARGS, "" },
	{ "EllipseLinearEccentricity", (PyCFunction)PyEllipseLinearEccentricity, METH_VARARGS, "" },
	{ "EllipseFocalParameter", (PyCFunction)PyEllipseFocalParameter, METH_VARARGS, "" },
	{ "EllipseSemiminorAxis", (PyCFunction)PyEllipseSemiminorAxis, METH_VARARGS, "" },
	{ "EllipseAspectRatio", (PyCFunction)PyEllipseAspectRatio, METH_O, "" },
	{ "EllipsePerifocusDistance", (PyCFunction)PyEllipsePerifocusDistance, METH_VARARGS, "" },
	{ "EllipseApothecureDistance", (PyCFunction)PyEllipseApothecureDistance, METH_VARARGS, "" },
	{ "EllipticalOrbitTrueAnomaly", (PyCFunction)PyEllipticalOrbitTrueAnomaly, METH_VARARGS, "" },
	{ "EllipticalOrbitTimeInterval", (PyCFunction)PyEllipticalOrbitTimeInterval, METH_VARARGS, "" },
	{ nullptr, nullptr, 0, nullptr }
};

static PyModuleDef SpeedMathModule = {
	PyModuleDef_HEAD_INIT,
	"speedmath",
	"Provides some functions, but faster",
	0,
	Methods
};

PyMODINIT_FUNC PyInit_speedmath() {
	return PyModule_Create(&SpeedMathModule);
}