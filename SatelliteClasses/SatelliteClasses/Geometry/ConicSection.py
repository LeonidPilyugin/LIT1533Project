import speedmath
import math

class ConicSection(object):

    '''
    This class discrabes conic section. More information: https://en.wikipedia.org/wiki/Conic_section

    Protected attributes:
        1) _Eccentricity
        2) _SemiMajorAxis

    Properties:
        1) Eccentricity
        2) SemiMajorAxis
        3) SemiLatusRectum (must be overriden in the child class)
        4) LinearEccentricity (must be overriden in the child class)
        5) FocalParameter (must be overriden in the child class)

    Setters:
        1) Eccentricity
        2) SemiMajorAxis
    '''

    __slots__ = ("_Eccentricity", "_SemiMajorAxis")

    def __init__(self):
        '''
        This constructor sets:
        _Eccentricity = 0
        _SemiMajorAxis = 6400000
        '''
        self._Eccentricity = 0.0
        self._SemiMajorAxis = 6400000.0
        pass
     
    @property
    def Eccentricity(self):
        '''
        Returns eccentricity.
        '''
        return self._Eccentricity

    @property
    def SemiMajorAxis(self):
        '''
        Returns semi-major axis.
        '''
        return self._SemiMajorAxis

    @property
    def SemiLatusRectum(self):
        '''
        Returns semi-latus rectum. Must be overriden in the child class.
        '''
        raise NotImplementedError("SemiMinorAxis must be overridden in the child class")

    @property
    def LinearEccentricity(self):
        '''
        Returns linear eccentricity. Must be overriden in the child class.
        '''
        raise NotImplementedError("SemiMinorAxis must be overridden in the child class")

    @property
    def FocalParameter(self):
        '''
        Returns focal parameter. Must be overriden in the child class.
        '''
        raise NotImplementedError("SemiMinorAxis must be overridden in the child class")
    
    @Eccentricity.setter
    def Eccentricity(self, value : float):
        '''
        Sets eccentricity. It must be a non-negative number.
        '''
        if 0.0 <= value:
            self._Eccentricity = value
            pass
        else:
            raise ValueError("Eccentricity should be a non-negative number")
        pass

    @SemiMajorAxis.setter
    def SemiMajorAxis(self, value : float):
        '''
        Sets semi-major axis. It must be a positive number.
        '''
        if value > 0.0:
            self._SemiMajorAxis = value
            pass
        else:
            raise ValueError("SemiMajorAxis should be a positive number")
        pass
    pass