#include <cmath>
#include "speedmath.h"
#include <Python.h>

static double SemiminorAxis(const double Eccentricity, const double SemiMajorAxis) {
	return SemiMajorAxis * sqrt(1 - Eccentricity * Eccentricity);
}

static double SemiLatusRectum(const double Eccentricity, const  double SemiMajorAxis) {
	return SemiMajorAxis * (1 - Eccentricity * Eccentricity);
}

static double AspectRatio(const double Eccentricity) {
	return sqrt(1 - Eccentricity * Eccentricity);
}

static double FocalDistance(const double Eccentricity, const double SemiMajorAxis) {
	return SemiMajorAxis * Eccentricity;
}

static double PerifocusDistance(const double Eccentricity, const double SemiMajorAxis) {
	return SemiMajorAxis * (1 - Eccentricity);
}

static double ApothecureDistance(const double Eccentricity, const double SemiMajorAxis) {
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

static double MeanAngularVelocity(const double SemiMajorAxis, const double DirectionRatio) {
	return sqrt(GM / SemiMajorAxis / SemiMajorAxis / SemiMajorAxis) * DirectionRatio;
}

static double MeanAnomalyByTrueAnomaly(const double Eccentricity, const double TrueAnomaly) {
	if (Eccentricity == 0)
		return TrueAnomaly;
	double EccentricAnomaly = acos(floor((1 - (1 - Eccentricity * Eccentricity) / (1 + Eccentricity * cos(TrueAnomaly))) / Eccentricity * 1000000000000000) / 1000000000000000.0);
	if (sin(TrueAnomaly) < 0)
		EccentricAnomaly = -EccentricAnomaly;
	return EccentricAnomaly - Eccentricity * sin(EccentricAnomaly);
}

static double TrueAnomalyByMeanAnomaly(const double Eccentricity, const double MeanAnomaly) {
	double EccentricAnomaly = MeanAnomaly;
	for (int i = 0; i < 100; i++)
		EccentricAnomaly = Eccentricity * sin(EccentricAnomaly) + MeanAnomaly;
	double TrueAnomaly = acos((cos(EccentricAnomaly) - Eccentricity) / (1 - Eccentricity * cos(EccentricAnomaly)));
	if (sin(EccentricAnomaly) < 0)
		TrueAnomaly = -TrueAnomaly;
	return TrueAnomaly;
}

static double TrueAnomalyByLongTineInterval(const double Eccentricity, const double SemiMajorAxis, const double TrueAnomaly, const double TimeInterval, const double DirectionRatio) {
	return TrueAnomalyByMeanAnomaly(Eccentricity, MeanAngularVelocity(SemiMajorAxis, DirectionRatio) * TimeInterval + MeanAnomalyByTrueAnomaly(Eccentricity, TrueAnomaly));
}

static double CirculationPeriod(const double SemiMajorAxis, const double DirectionRatio) {
	return 2 * PI / MeanAngularVelocity(SemiMajorAxis, DirectionRatio) * DirectionRatio;
}

static double TimeInterval(const double Eccentricity, const double SemiMajorAxis, const double StartTrueAnomaly, const double FinishTrueAnomaly, const double DirectionRatio) {
	double DeltaTrueAnomaly = MeanAnomalyByTrueAnomaly(Eccentricity, FinishTrueAnomaly) - MeanAnomalyByTrueAnomaly(Eccentricity, StartTrueAnomaly);
	double TimeInterval = DeltaTrueAnomaly / MeanAngularVelocity(SemiMajorAxis, DirectionRatio);
	if (TimeInterval < 0)
		TimeInterval += CirculationPeriod(SemiMajorAxis, DirectionRatio);
	return TimeInterval;
}

static PyObject* PySemiminorAxis(PyObject*, PyObject* args) {
	double Eccentricity, SemiMajorAxis;
	if (!PyArg_ParseTuple(args, "dd", &Eccentricity, &SemiMajorAxis)) {
		return nullptr;
	}
	return PyFloat_FromDouble(SemiminorAxis(Eccentricity, SemiMajorAxis));
}

static PyObject* PySemiLatusRectum(PyObject*, PyObject* args) {
	double Eccentricity, SemiMajorAxis;
	if (!PyArg_ParseTuple(args, "dd", &Eccentricity, &SemiMajorAxis)) {
		return nullptr;
	}
	return PyFloat_FromDouble(SemiLatusRectum(Eccentricity, SemiMajorAxis));
}

static PyObject* PyAspectRatio(PyObject*, PyObject* Eccentricity) {
	return PyFloat_FromDouble(AspectRatio(PyFloat_AsDouble(Eccentricity)));
}

static PyObject* PyFocalDistance(PyObject*, PyObject* args) {
	double Eccentricity, SemiMajorAxis;
	if (!PyArg_ParseTuple(args, "dd", &Eccentricity, &SemiMajorAxis)) {
		return nullptr;
	}
	return PyFloat_FromDouble(FocalDistance(Eccentricity, SemiMajorAxis));
}

static PyObject* PyPerifocusDistance(PyObject*, PyObject* args) {
	double Eccentricity, SemiMajorAxis;
	if (!PyArg_ParseTuple(args, "dd", &Eccentricity, &SemiMajorAxis)) {
		return nullptr;
	}
	return PyFloat_FromDouble(PerifocusDistance(Eccentricity, SemiMajorAxis));
}

static PyObject* PyApothecureDistance(PyObject*, PyObject* args) {
	double Eccentricity, SemiMajorAxis;
	if (!PyArg_ParseTuple(args, "dd", &Eccentricity, &SemiMajorAxis)) {
		return nullptr;
	}
	return PyFloat_FromDouble(ApothecureDistance(Eccentricity, SemiMajorAxis));
}

//static PyObject* PyTrueAnomalyByShortTineInterval(PyObject* self, PyObject* args) {
//	double Eccentricity, SemiMajorAxis, TrueAnomaly, TimeInterval;
//	if (!PyArg_ParseTuple(args, "dddd", &Eccentricity, &SemiMajorAxis, &TrueAnomaly, &TimeInterval)) {
//		return nullptr;
//	}
//	return PyFloat_FromDouble(TrueAnomalyByShortTineInterval(Eccentricity, SemiMajorAxis, TrueAnomaly, TimeInterval));
//}

static PyObject* PyTrueAnomalyByLongTimeInterval(PyObject* self, PyObject* args) {
	double Eccentricity, SemiMajorAxis, TrueAnomaly, TimeInterval, DirectionRatio;
	if (!PyArg_ParseTuple(args, "ddddd", &Eccentricity, &SemiMajorAxis, &TrueAnomaly, &TimeInterval, &DirectionRatio)) {
		return nullptr;
	}
	return PyFloat_FromDouble(TrueAnomalyByLongTineInterval(Eccentricity, SemiMajorAxis, TrueAnomaly, TimeInterval, DirectionRatio));
}

static PyObject* PyTimeInterval(PyObject* self, PyObject* args) {
	double Eccentricity, SemiMajorAxis, StartTrueAnomaly, FinishTrueAnomaly, DirectionRatio;
	if (!PyArg_ParseTuple(args, "ddddd", &Eccentricity, &SemiMajorAxis, &StartTrueAnomaly, &FinishTrueAnomaly, &DirectionRatio)) {
		return nullptr;
	}
	return PyFloat_FromDouble(TimeInterval(Eccentricity, SemiMajorAxis, StartTrueAnomaly, FinishTrueAnomaly, DirectionRatio));
}

static PyMethodDef Methods[] = {
	{ "SemiminorAxis", (PyCFunction)PySemiminorAxis, METH_VARARGS, "Returns semi-minor axis by eccentricity and major semiaxis. Example: a = SemiminorAxis(Eccentricity, MajorSemiaxis)" },
	{ "SemiLatusRectum", (PyCFunction)PySemiLatusRectum, METH_VARARGS, "Returns semi-latus rectum by eccentricity and major semiaxis. Example: a = SemiLatusRectum(Eccentricity, MajorSemiaxis)" },
	{ "AspectRatio", (PyCFunction)PyAspectRatio, METH_O, "Returns aspect ratio by eccentricity and major semiaxis. Example: a = AspectRatio(Eccentricity, MajorSemiaxis)" },
	{ "FocalDistance", (PyCFunction)PyFocalDistance, METH_VARARGS, "Returns focal distance by eccentricity and major semiaxis. Example: a = FocalDistance(Eccentricity, MajorSemiaxis)" },
	{ "PerifocusDistance", (PyCFunction)PyPerifocusDistance, METH_VARARGS, "Returns perifocus distance by eccentricity and major semiaxis. Example: a = PerifocusDistance(Eccentricity, MajorSemiaxis)" },
	{ "ApothecureDistance", (PyCFunction)PyApothecureDistance, METH_VARARGS, "Returns apothecure distance by eccentricity and major semiaxis. Example: a = ApothecureDistance(Eccentricity, MajorSemiaxis)" },
	//{ "TrueAnomalyByShortTimeInterval", (PyCFunction)PyTrueAnomalyByShortTineInterval, METH_VARARGS, "Returns true anomaly by short time interval by angular velocity. Example: a = TrueAnomalyByShortTineInterval(Eccentricity, SemiMajorAxis, TrueAnomaly, TimeInterval)" },
	{ "TrueAnomaly", (PyCFunction)PyTrueAnomalyByLongTimeInterval, METH_VARARGS, "Returns true anomaly by long time interval by angular velocity. Example: a = TrueAnomalyByLongTimeInterval(Eccentricity, SemiMajorAxis, TrueAnomaly, TimeInterval)" },
	{ "TimeInterval", (PyCFunction)PyTimeInterval, METH_VARARGS, "Returns the time it takes for a satellite to travel the distance between two points. Example: a = TimeInterval(Eccentricity, SemiMajorAxis, StartTrueAnomaly, FinishTrueAnomaly)" },
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