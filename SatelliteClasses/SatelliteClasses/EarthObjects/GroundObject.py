import math

class GroundObject(object):

    """
    This class describes object on Earth.

    Attributes:
        1) _Longitude
        2) _Latitude

    Properties:
        1) Longitude
        2) Latitude

    Setters:
        1) Longitude
        2) Latitude
    """

    __slots__ = ("_Longitude", "_Latitude")

    def __init__(self):
        '''
        This constructor sets:
        _Longitude = _Latitude = 0
        '''
        self._Longitude = 0.0
        self._Latitude = 0.0
        pass

    @property
    def Longitude(self):
        '''
        Returns longitudes.
        '''
        return self._Longitudes

    @property
    def Latitude(self):
        '''
        Returns latitude.
        '''
        return self._Latitude

    @Longitude.setter
    def Longitude(self, value):
        '''
        Sets the longitude. It must be less than pi and greater than or equal to -pi.
        '''
        if -math.pi <= value < math.pi:
            self._Longitude = value
            pass
        else:
            raise ValueError("Longitude must be less than pi and greater than or equal to -pi.")
        pass

    @Latitude.setter
    def Latitude(self, value):
        '''
        Sets the longitude. It must be less than or equal to pi/2 and greater than or equal to -pi/2.
        '''
        if -math.pi/2 <= value <= math.pi/2:
            self._Latitude = value
            pass
        else:
            raise ValueError("Latitude must be less than or equal to pi/2 and greater than or equal to -pi/2.")
        pass
    pass



