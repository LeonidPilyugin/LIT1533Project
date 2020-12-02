import math
from UsefullFunctions import *

class Orbit(object):

    '''
    This class describes Orbit. More information: https://en.wikipedia.org/wiki/Orbit

    Attributes:
        1) _Inclination
        2) _AscendingNodeLongitude
        3) _PeriapsisArgument

    Properties:
        1) Inclination
        2) AscendingNodeLongitude
        3) PeriapsisArgument

    Setters:
        1) Inclination
        2) AscendingNodeLongitude
        3) PeriapsisArgument
    '''

    def __init__(self):
        '''
        This constructor sets:
        _Inclination = _AscendingNodeLongitude = _PeriapsisArgument = 0
        '''
        self._Inclination = 0.0
        self._AscendingNodeLongitude = 0.0
        self._PeriapsisArgument = 0.0
        pass

    @property
    def Inclination(self):
        '''
        Returns inclination
        '''
        return self._Inclination

    @property
    def AscendingNodeLongitude(self):
        '''
        Returns the longitude of ascending node.
        '''
        return self._AscendingNodeLongitude

    @property
    def PeriapsisArgument(self):
        '''
        Returns periapsis argument
        '''
        return self._PeriapsisArgument

    @Inclination.setter
    def Inclination(self, value : float):
        '''
        Sets inclination. It must be less then pi and greater than or equal to -pi.
        '''
        if EllipseAngleCheck(value):
            self._Inclination = value
            pass
        else:
            raise ValueError("Inclination must be less then pi and greater than or equal to -pi")
         
    @AscendingNodeLongitude.setter
    def AscendingNodeLongitude(self, value : float):
        '''
        Sets the longitude of ascending node. It must be less then pi and greater than or equal to -pi.
        '''
        if EllipseAngleCheck(value):
            self._AscendingNodeLongitude = value
            pass
        else:
            raise ValueError("AscendingNodeLongitude must be less then pi and greater than or equal to -pi")
        pass

    @PeriapsisArgument.setter
    def PeriapsisArgument(self, value : float):
        '''
        Sets periapsis argument. It must be less then pi and greater than or equal to -pi.
        '''
        if EllipseAngleCheck(value):
            self._PeriapsisArgument = value
            pass
        else:
            raise ValueError("PeriapsisArgument must be less then pi and greater than or equal to -pi")
        pass
    pass


