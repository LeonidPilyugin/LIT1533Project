import math
from _speedmath import *

'''
Classes:
    1) ConicSection
    2) Ellipse(ConicSection)
    3) Parabola(ConicSection) not implemented
    4) Hyperbola(ConicSection) not implemented
'''

class ConicSection(object):

    '''
    This class discrabes conic section. More information: 
    https://en.wikipedia.org/wiki/Conic_section

    Protected attributes:
        1) _eccentricity
        2) _semi_major_axis

    Properties:
        1) eccentricity
        2) semi_major_axis
        3) semi_latus_rectum (must be overriden in the child class)
        4) linear_eccentricity (must be overriden in the child class)
        5) focal_parameter (must be overriden in the child class)

    Setters:
        1) eccentricity
        2) _semi_major_axis
    '''


    def __init__(self):
        '''
        This constructor sets:
        _eccentricity = 0.0
        _semi_major_axis = 6400000.0
        '''
        super().__init__()
        self._eccentricity = 0.0
        self._semi_major_axis = 6400000.0
        pass


    def parse(self):
        return self._eccentricity, self._semi_major_axis
     

    @property
    def eccentricity(self):
        '''
        Returns eccentricity.
        '''
        return self._eccentricity

    @property
    def semi_major_axis(self):
        '''
        Returns semi-major axis.
        '''
        return self._semi_major_axis

    @property
    def semi_latus_rectum(self):
        '''
        Returns semi-latus rectum. Must be overriden in the child class.
        '''
        raise NotImplementedError("semi_latus_rectum must be overridden in \
                                   the child class")

    @property
    def linear_eccentricity(self):
        '''
        Returns linear eccentricity. Must be overriden in the child class.
        '''
        raise NotImplementedError("linear_eccentricity must be overridden in \
                                   the child class")

    @property
    def focal_parameter(self):
        '''
        Returns focal parameter. Must be overriden in the child class.
        '''
        raise NotImplementedError("focal_parameter must be overridden in \
                                   the child class")
    

    @eccentricity.setter
    def eccentricity(self, value : float):
        '''
        Sets eccentricity. It must be a non-negative number.
        '''
        if 0.0 <= value:
            self._eccentricity = value
            pass
        else:
            raise ValueError("eccentricity must be a non-negative number")
        pass

    @semi_major_axis.setter
    def semi_major_axis(self, value : float):
        '''
        Sets semi-major axis. It must be a positive number.
        '''
        if value > 0.0:
            self._semi_major_axis = value
            pass
        else:
            raise ValueError("semi_major_axis must be a positive number")
        pass
    pass



class Ellipse(ConicSection):

    '''
    This class discrabes ellipse. More information: 
    https://en.wikipedia.org/wiki/Ellipse
    Class Ellipse inherits from class ConicSection.

    Protected attributes:
        1) _eccentricity
        2) _semiMajorAxis

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

    Setters:
        1) eccentricity
        2) semi_major_axis
    '''


    def __init__(self):
        '''
        This constructor sets:
        _eccentricity = 0
        _semi_major_axis = 6400000
        '''
        super().__init__()
        pass


    @property
    def semi_minor_axis(self):
        '''
        Returns semi-minor axis.
        '''
        return compute_ellipse_semi_minor_axis(self.parse())

    @property
    def aspect_ratio(self):
        '''
        Returns aspect ratio.
        '''
        return compute_ellipse_aspect_ratio(self.parse())

    @property
    def perifocus_distance(self):
        '''
        Returns perifocus distance.
        '''
        return compute_ellipse_perifocus_distance(self.parse())

    @property
    def apothecure_distance(self):
        '''
        Returns apothecure distance.
        '''
        return compute_ellipse_apothecure_distance(self.parse())

    @property
    def semi_latus_rectum(self):
        '''
        Returns semi-latus rectum.
        '''
        return compute_ellipse_semi_latus_rectum(self.parse())

    @property
    def linear_eccentricity(self):
        '''
        Returns linear eccentricity.
        '''
        return compute_ellipse_linear_eccentricity(self.parse())

    @property
    def focal_parameter(self):
        '''
        Returns focal parameter.
        '''
        return compute_ellipse_focal_parameter(self.parse())
    

    @ConicSection.eccentricity.setter
    def eccentricity(self, value : float):
        '''
        Sets eccentricity. It must be a non-negative number less then 1.
        '''
        if 0.0 <= value < 1.0:
            self._eccentricity = value
            pass
        else:
            raise ValueError("Eccentricity must be a number less than \
                              1 and greater than or equal to 0")
        pass
    pass
    