import math
from usefull_functions import *

class GroundObject(object):

    """
    This class describes object on Earth.

    Attributes:
        1) _longitude
        2) _latitude

    Properties:
        1) longitude
        2) latitude

    Setters:
        1) longitude
        2) latitude
    """


    def __init__(self):
        '''
        This constructor sets:
        _longitude = 0.0
        _latitude = 0.0
        '''
        super().__init__()
        self._longitude = 0.0
        self._latitude = 0.0
        pass


    @property
    def longitude(self):
        '''
        Returns longitudes.
        '''
        return self._longitude

    @property
    def latitude(self):
        '''
        Returns latitude.
        '''
        return self._latitude


    @longitude.setter
    def longitude(self, value):
        '''
        Sets the longitude. It must be less than pi and 
        greater than or equal to -pi.
        '''
        if ellipse_check_angle(value):
            self._longitude = value
            pass
        else:
            raise ValueError("Longitude must be less than pi and \
                              greater than or equal to -pi.")
        pass

    @latitude.setter
    def latitude(self, value):
        '''
        Sets the longitude. It must be less than or equal to 
        pi/2 and greater than or equal to -pi/2.
        '''
        if -math.pi/2 <= value <= math.pi/2:
            self._latitude = value
            pass
        else:
            raise ValueError("Latitude must be less than or equal to pi/2 and \
                              greater than or equal to -pi/2.")
        pass

    pass



class GroundStation(GroundObject):

    '''
    This class describes ground station.
    Class GroundStation inherits from class GroundObject.
    '''


    def __init__(self):
        super().__init__()
        pass

    pass



class ShootPoint(GroundObject):

    '''
    This class describes point to be photographed by the satellite.
    Class ShootPoint inherits from class GroundObject.

    Attributes:
        1) _longitude
        2) _latitude
        3) _has_shot
        
    Properties:
        1) longitude
        2) latitude
        3) has_shot

    Setters:
        1) longitude
        2) latitude

    Methods:
        1) shoot()
    '''


    def __init__(self):
        '''
        This constructor sets:
        _longitude = _latitude = 0
        _has_shot = False
        '''
        super().__init__()
        self._has_shot = False
        pass


    @property
    def has_shot(self):
        '''
        Returns _has_shot
        '''
        return self._has_shot


    def shoot(self):
        '''
        Sets _has_shot = True
        '''
        self._has_shot = True
        pass

    pass


