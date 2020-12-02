import speedmath
from Orbits.Orbit import Orbit
from Orbits.EllipticOrbit import EllipticOrbit
from UsefullFunctions import *

class Satellite(object):

    '''
    Class Satellite describes satellite. More information: https://en.wikipedia.org/wiki/Satellite

    Attributes:
        1) _TrueAnomaly
        2) _DirectionRatio
        3) _Name
        4) _Orbit

    Properties:
        1) TrueAnomaly
        2) DirectionRatio
        3) Name
        4) Orbit

    Setters:
        1) True Anomaly
        2) DirectionRatio
        3) Name
        4) Orbit

    Methods:
        1) ChangeTrueAnomaly(TimeInterval)
        2) TimeInterval(StartTrueAnomaly, FinishTrueAnomaly)
    '''

    def __init__(self):
        '''
        This constructor sets:
        _Eccentricity = 0
        _SemiMajorAxis = 6400000
        _Inclination = _AscendingNodeLongitude = _PeriapsisArgument = 0
        '''
        self._TrueAnomaly = 0.0
        self._DirectionRatio = 1
        self._Name = "New Satellite"
        self._Orbit = EllipticOrbit()
        pass

    @property
    def TrueAnomaly(self):
        '''
        Returns true anomaly.
        '''
        return self._TrueAnomaly

    @property
    def DirectionRatio(self):
        '''
        Returns direction ratio.
        '''
        return _DirectionRatio

    @property
    def Name(self):
        '''
        Returns name.
        '''
        return self._Name

    @property
    def Orbit(self):
        '''
        Returns orbit.
        '''
        return self._Orbit

    @DirectionRatio.setter
    def DirectionRatio(self, value : int):
        '''
        Sets direction ratio. It must be 1 or -1. Direction ratio is a coefficient at angular velocity.
        '''
        if value == -1 or 1:
            self._DirectionRatio = value
            pass
        else:
            raise ValueError("DirectionRatio must be 1 or -1")

    @TrueAnomaly.setter
    def TrueAnomaly(self, value : float):
        '''
        Sets TrueAnomaly. It must be 1 or -1. Direction ratio is a coefficient at angular velocity.
        '''
        if isinstance(self._Orbit, EllipticOrbit):
            if EllipseAngleCheck(value):
                self._TrueAnomaly = value
                pass
            else:
                raise ValueError("TrueAnomaly must be less then pi and greater than or equal to -pi.")
            pass
        else:
            raise Warning("Satellites.Satellite.TrueAnomaly setter works only with EllipticalOrbit. If you want to use other orbit types, you should edit it.")

    @Name.setter
    def Name(self, value : str):
        '''
        Sets name. It must be string.
        '''
        if isinstance(value, str):
            self._Name = value
            pass
        else:
            raise ValueError("Name must be a string")
        pass

    @Orbit.setter
    def Orbit(self, value):
        '''
        Sets orbit. It must be child class of Orbit.
        '''
        if isinstance(value, Orbit):
            self._Orbit = value
            pass
        else:
            raise ValueError("Orbit must be child class of Orbit")
        pass

    def ChangeTrueAnomaly(self, TimeInterval : float):
        '''
        Changes true anomaly by time interval.
        '''
        if TimeInterval <= 0.0:
            raise ValueError("TimeInterval must be a positive number")
        if isinstance(self._Orbit, EllipticOrbit):
            self._TrueAnomaly = speedmath.EllipseTrueAnomaly(self._Orbit.Eccentricity, self._Orbit.SemiMajorAxis, self._TrueAnomaly, TimeInterval, self._DirectionRatio)
            pass
        else:
            raise Warning("Satellites.Satellite.ChangeTrueAnomaly works only with EllipticalOrbit. If you want to use other orbit types, you should edit it.")

    def TimeInterval(self, StartTrueAnomaly : float, FinishTrueAnomaly : float):
        '''
        Returns time interval between two values of true anomaly.
        '''
        if not AngleCheck(StartTrueAnomaly, FinishTrueAnomaly):
            raise ValueError("StartTrueAnomaly and FinishTrueAnomaly must be less then pi and greater than or equal to -pi.")
        if isinstance(self._Orbit, EllipticalOrbit):
            self._TrueAnomaly = speedmath.EllipseTrueAnomaly(self._Orbit.Eccentricity, self._Orbit.SemiMajorAxis, self._TrueAnomaly, TimeInterval, self._DirectionRatio)
            pass
        else:
            raise Warning("Satellites.Satellite.TimeInterval works only with EllipticalOrbit. If you want to use other orbit types, you should edit it.")
    pass



