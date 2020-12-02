from Satellites.Satellite import Satellite
from Orbits.EllipticalOrbit import EllipticalOrbit
from Orbits.Orbit import Orbit
import math
import speedmath

class EllipticalOrbitSatellite(Satellite):
    
    def __init__(self):
        super().__init__()
        self._Orbit = EllipticalOrbit()
        pass

    @Satellite.TrueAnomaly.setter
    def TrueAnomaly(self, TrueAnomaly):
        if Orbit._AngleCheck(TrueAnomaly):
            self._TrueAnomaly = TrueAnomaly
            pass
        else:
            raise ValueError("TrueAnomaly must be ")
        
    @property
    def Orbit(self):
        return self._Orbit

    def ChangeTrueAnomaly(self, TimeInterval):
        if TimeInterval <= 0:
            raise ValueError("TimeInterval must be positive")
        self._TrueAnomaly = speedmath.TrueAnomaly(self._Eccentricity, self._SemiMajorAxis, self._TrueAnomaly, TimeInterval, self._DirectionRatio)
        pass

    def TimeInterval(self, StartTrueAnomaly, FinishTrueAnomaly):
        if Orbit._AngleCheck(StartTrueAnomaly) and Orbit._AngleCheck(FinishTrueAnomaly):
            return speedmath.TimeInterval()
        else:
            raise ValueError("")
    pass



