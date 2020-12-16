#pragma once
#include <Python.h>
#include "Orbits.h"



class Satellite
{
protected:
	static const double ROUNDING_CONSTANT;
	static const int ITERATION_CONSTANT;
	static const double GM;
	static const double PI;
	double true_anomaly;
	double direction_ratio;
public:
	Satellite(PyObject*);
	Satellite(PyObject*, PyObject*);
};

const double Satellite::ROUNDING_CONSTANT = 1000000000000000.0;
const int Satellite::ITERATION_CONSTANT = 100;
const double Satellite::GM = 3.986e14;
const double Satellite::PI = 3.14159265358979323846;

class EllipticSatellite : public Satellite, public EllipticOrbit 
{

};

