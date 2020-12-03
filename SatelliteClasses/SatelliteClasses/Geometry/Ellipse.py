import speedmath
from Geometry.ConicSection import ConicSection

class Ellipse(ConicSection):

    '''
    This class discrabes ellipse. More information: https://en.wikipedia.org/wiki/Ellipse
    Class Ellipse inherits from class ConicSection.

    Protected attributes:
        1) _Eccentricity
        2) _SemiMajorAxis

    Properties:
        1) Eccentricity
        2) SemiMajorAxis
        3) SemiMinorAxis
        4) AspectRatio
        5) PerifocusDistance
        6) ApothecureDistance
        7) SemiLatusRectum
        8) LinearEccentricity
        9) FocalParameter

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
        ConicSection.__init__(self)
        pass

    @property
    def SemiMinorAxis(self):
        '''
        Returns semi-minor axis.
        '''
        return speedmath.EllipseSemiminorAxis(self._Eccentricity, self._SemiMajorAxis)

    @property
    def AspectRatio(self):
        '''
        Returns aspect ratio.
        '''
        return speedmath.EllipseAspectRatio(self._Eccentricity)

    @property
    def PerifocusDistance(self):
        '''
        Returns perifocus distance.
        '''
        return speedmath.EllipsePerifocusDistance(self._Eccentricity, self._SemiMajorAxis)

    @property
    def ApothecureDistance(self):
        '''
        Returns aputhecure distance.
        '''
        return speedmath.EllipseApothecureDistance(self._Eccentricity, self._SemiMajorAxis)

    @property
    def SemiLatusRectum(self):
        '''
        Returns semi-latus rectum.
        '''
        return speedmath.EllipseSemiLatusRectum(self._Eccentricity, self._SemiMajorAxis)

    @property
    def LinearEccentricity(self):
        '''
        Returns linear eccentricity.
        '''
        return speedmath.EllipseLinearEccentricity(self._Eccentricity, self._SemiMajorAxis)

    @property
    def FocalParameter(self):
        '''
        Returns focal parameter.
        '''
        return speedmath.EllipseFocalParameter(self._Eccentricity, self._SemiMajorAxis)
    
    @ConicSection.Eccentricity.setter
    def Eccentricity(self, value : float):
        '''
        Sets eccentricity. It must be a non-negative number less then 1.
        '''
        if 0.0 <= value < 1.0:
            self._Eccentricity = value
            pass
        else:
            raise ValueError("Eccentricity should be a number less than 1 and greater than or equal to 0")
        pass
    pass
    