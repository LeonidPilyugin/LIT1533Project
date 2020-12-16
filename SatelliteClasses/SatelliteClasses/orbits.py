import math
from usefull_functions import *
import conic_sections

'''
Classes:
    1) Orbit
    2) EllipticOrbit(Orbit, conical_sections.Ellipse)
    3) ParabolicOrbit(Orbit, conical_sections.Parabola) not implemented
    4) HyperbolicOrbit(Orbit, conical_sections.Hyperbola) not implemented
'''

class Orbit(object):

    '''
    This class describes Orbit. More information: 
    https://en.wikipedia.org/wiki/Orbit

    Attributes:
        1) _inclination
        2) _ascending_node_longitude
        3) _periapsis_argument

    Properties:
        1) inclination
        2) ascending_node_longitude
        3) periapsis_argument

    Setters:
        1) inclination
        2) ascending_node_longitude
        3) periapsis_argument
    '''


    def __init__(self):
        '''
        This constructor sets:
        _inclination = 0.0
        _ascending_node_longitude = 0.0
        _periapsis_argument = 0.0
        '''
        super().__init__()
        self._inclination = 0.0
        self._ascending_node_longitude = 0.0
        self._periapsis_argument = 0.0
        pass


    def split_into_attributes(self):
        return (self._inclination, self._ascending_node_longitude,
                self._periapsis_argument)


    @property
    def inclination(self):
        '''
        Returns inclination
        '''
        return self._inclination

    @property
    def ascending_node_longitude(self):
        '''
        Returns the longitude of ascending node.
        '''
        return self._ascending_node_longitude

    @property
    def periapsis_argument(self):
        '''
        Returns periapsis argument
        '''
        return self._periapsis_argument


    @inclination.setter
    def inclination(self, value : float):
        '''
        Sets inclination. It must be less than pi and 
        greater than or equal to -pi.
        '''
        if ellipse_check_angle(value):
            self._inclination = value
            pass
        else:
            raise ValueError("Inclination must be less than pi and \
                              greater than or equal to -pi")
         
    @ascending_node_longitude.setter
    def ascending_node_longitude(self, value : float):
        '''
        Sets the longitude of ascending node. It must be 
        less than pi and greater than or equal to -pi.
        '''
        if ellipse_check_angle(value):
            self._ascending_node_longitude = value
            pass
        else:
            raise ValueError("The longitude of ascending node must be less \
                              than pi and greater than or equal to -pi")
        pass

    @periapsis_argument.setter
    def periapsis_argument(self, value : float):
        '''
        Sets periapsis argument. It must be less 
        then pi and greater than or equal to -pi.
        '''
        if ellipse_check_angle(value):
            self._periapsis_argument = value
            pass
        else:
            raise ValueError("Periapsis argument must be less \
                              than pi and greater than or equal to -pi")
        pass

    pass




class EllipticOrbit(Orbit, conic_sections.Ellipse):

    '''
    This class discrabes elliptical orbit. More information: 
    https://en.wikipedia.org/wiki/Elliptic_orbit
    Class EllipticOrbit inherits from classes Ellise and Orbit.

    Protected attributes:
        1) _eccentricity
        2) _semi_major_axis
        3) _inclination
        4) _ascending_node_longitude
        5) _periapsis_argument

    Properties:
        1) eccentricity
        2) semi_major_axis
        3) semi_minor_axis
        4) aspect_ratio
        5) perifocus_distance
        6) apothecure_distance
        7) semi_latus_rectum
        8) linear_eccentricity
        9) focal_parameter
        10) inclination
        11) ascending_node_longitude
        12) periapsis_argument

    Setters:
        1) eccentricity
        2) semi_major_axis
        3) inclination
        4) ascending_node_longitude
        5) periapsis_argument
    '''


    def __init__(self):
        '''
        This constructor sets:
        _eccentricity = 0.0
        _semi_major_axis = 6400000.0
        _inclination = 0.0
        _AscendingNodeLongitude = 0.0
        _PeriapsisArgument = 0.0
        '''
        super().__init__()
        pass



    def split_into_attributes(self):
        return self._eccentricity, self.semi_major_axis, self._inclination, \
               self._ascending_node_longitude, self._periapsis_argument

    pass

