#include "speedmath.h"
#include <cmath>


// All functions work only with elliptic orbits

static double
compute_ellipse_linear_eccentricity(ConicSection* ellipse)
{
	return ellipse->semi_major_axis * ellipse->eccentricity;
}



static double
compute_ellipse_focal_parameter(ConicSection* ellipse)
{
	return ellipse->semi_major_axis *
		   (1 - ellipse->eccentricity * ellipse->eccentricity) /
		   ellipse->eccentricity;
}



static double
compute_ellipse_semi_latus_rectum(ConicSection* conicSection)
{
	return conicSection->semi_major_axis *
		   (1 - conicSection->eccentricity * conicSection->eccentricity);
}



static double
compute_ellipse_semi_minor_axis(ConicSection* ellipse)
{
	return ellipse->semi_major_axis *
		   sqrt(1 - ellipse->eccentricity * ellipse->eccentricity);
}



static double
compute_ellipse_aspect_ratio(ConicSection* ellipse)
{
	return sqrt(1 - ellipse->eccentricity * ellipse->eccentricity);
}



static double 
compute_ellipse_perifocus_distance(ConicSection* ellipse)
{
	return ellipse->semi_major_axis * (1 - ellipse->eccentricity);
}



static double
compute_ellipse_apothecure_distance(ConicSection* ellipse)
{
	return ellipse->semi_major_axis * (1 + ellipse->eccentricity);
}



static double
compute_elliptical_satellite_mean_angular_velocity(Satellite* satellite)
{
	return sqrt(GM / satellite->semi_major_axis / satellite->semi_major_axis /
		satellite->semi_major_axis) * satellite->direction_ratio;
}



static double
compute_elliptic_orbit_eccentric_anomaly(double eccentricity, double true_anomaly)
{
	// Without this operator in case eccentricity == 0, 
	// function won't work correctly

	if (eccentricity == 0.0)
		return true_anomaly;

	// Without ROUNDING_CONSTANT eccentricity may be nan, because
	// acos takes value between -1 and 1

	double eccentric_anomaly = acos(floor((1 - (1 - eccentricity * eccentricity
		) / (1 + eccentricity * cos(true_anomaly))) /
		eccentricity * ROUNDING_CONSTANT) /
		ROUNDING_CONSTANT);

	// If sin(trueAnomaly) < 0, eccentric anomaly < 0,
	// but 0 <= acos() <= PI

	if (sin(true_anomaly) < 0)
		eccentric_anomaly = -eccentric_anomaly;

	return eccentric_anomaly;
}



static double
compute_elliptic_orbit_mean_anomaly_by_true_anomaly
(double eccentricity, double true_anomaly) 
{
	double eccentric_anomaly = compute_elliptic_orbit_eccentric_anomaly(eccentricity, true_anomaly);
	return eccentric_anomaly - eccentricity * sin(eccentric_anomaly);
}



static double
compute_elliptic_orbit_true_anomaly_by_mean_anomaly
(double eccentricity, double mean_anomaly) 
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




static double
compute_elliptic_orbit_true_anomaly_by_time_interval
(Satellite* satellite, double time_interval) 
{
	// This function computes satellite's new true anomaly after 
	// a period of time
	// Satellite's eccentricity must be less then 0.8, otherwise
	// the function will produce a result with a large error

	return compute_elliptic_orbit_true_anomaly_by_mean_anomaly(satellite->eccentricity,
		   compute_elliptical_satellite_mean_angular_velocity(satellite) * time_interval +
		   compute_elliptic_orbit_mean_anomaly_by_true_anomaly(satellite->eccentricity,
		   satellite->true_anomaly));
}



static double
compute_orbital_period
(Satellite* satellite)
{
	return 2 * PI / compute_elliptical_satellite_mean_angular_velocity(satellite) *
		   satellite->direction_ratio;
}



static double
compute_elliptical_satellite_time_interval
(Satellite* satellite, double finishTrueAnomaly)
{
	// This function returns the time interval for the satellite 
	// to reach the specified point in orbit

	double DeltaTrueAnomaly = 
		compute_elliptic_orbit_mean_anomaly_by_true_anomaly(satellite->eccentricity,
	finishTrueAnomaly) - compute_elliptic_orbit_mean_anomaly_by_true_anomaly(
	satellite->eccentricity, satellite->true_anomaly);

	double TimeInterval = DeltaTrueAnomaly / 
		compute_elliptical_satellite_mean_angular_velocity(satellite);

	if (TimeInterval < 0)
		TimeInterval += compute_orbital_period(satellite);

	return TimeInterval;
}



static double
compute_distance_to_satellite(Satellite* satellite)
{
	// This function returns distance between 
	// the center of the Earth and satellite

	return compute_ellipse_semi_latus_rectum(satellite) /
		   (1 + satellite->eccentricity * cos(satellite->true_anomaly));
}



static bool
can_shoot(Satellite* satellite, GroundObject* shootPoint)
{
	return true;
}



static double
compute_time_to_shoot(Satellite* satellite, GroundObject* shootPoint)
{
	// This function returns time after which satellite can shoot point
	return 0.0;
}