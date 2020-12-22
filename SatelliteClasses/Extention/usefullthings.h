#pragma once



static const double ROUNDING_CONSTANT = 1000000000000000.0;
static const int ITERATION_CONSTANT = 100;
static const double GM = 3.986e14;
static const double PI = 3.14159265358979323846;
static const double ANGLE_BETWEEN_ECLIPTIC_AND_EQUATOR = 0.818185;
static const double EARTH_SEMI_MAJOR_AXIS = 6378245.0;
static const double EARTH_MEAN_RADIUS = 6371.0;
static const double EARTH_ECCENTRICITY = 0.081813;
static const double EARTH_ANGULAR_VELOCITY_AROUND_AXIS = 2 * PI / 86400.0;



bool set_symmetric_angle(double*, double, double); //sets angle a value if it is < last argument and >= -last argument and returns true, if angle is set

bool set_full_symmetric_angle(double*, double, double); //sets angle a value if it is <= last argument and >= -last argument and returns true, if angle is set

bool set_elliptic_angle(double*, double); //sets angle a value if it is < pi and >= -pi and returns true, if angle is set

