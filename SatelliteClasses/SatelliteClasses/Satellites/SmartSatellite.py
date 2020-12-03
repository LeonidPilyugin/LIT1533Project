from Satellites.Satellite import Satellite

class SmartSatellite(Satellite):
    
    __slots__ = ("_TrueAnomaly", "_DirectionRatio", "_Name", "_Orbit")

    def __init__(self):
        Satellite.__init__(self)
        pass
    pass



