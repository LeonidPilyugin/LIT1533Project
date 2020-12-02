from Orbits.Orbit import Orbit
from Geometry.Ellipse import Ellipse

class EllipticOrbit(Orbit, Ellipse):

    '''
    This class discrabes elliptical orbit. More information: https://en.wikipedia.org/wiki/Elliptic_orbit
    Class EllipticOrbit inherits from classes Ellise and Orbit

    Protected attributes:
        1) _Eccentricity
        2) _SemiMajorAxis
        3) _Inclination
        4) _AscendingNodeLongitude
        5) _PeriapsisArgument

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
        10) Inclination
        11) AscendingNodeLongitude
        12) PeriapsisArgument

    Setters:
        1) Eccentricity
        2) SemiMajorAxis
        3) Inclination
        4) AscendingNodeLongitude
        5) PeriapsisArgument
    '''
    
    def __init__(self):
        '''
        This constructor sets:
        _Eccentricity = 0
        _SemiMajorAxis = 6400000
        _Inclination = _AscendingNodeLongitude = _PeriapsisArgument = 0
        '''
        Orbit.__init__(self)
        Ellipse.__init__(self)
        pass
    pass



