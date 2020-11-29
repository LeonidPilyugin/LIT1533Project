from ArtificialSatellite import ArtificialSatellite

class SmartArtificialSatellite(ArtificialSatellite):
    def __init__(self, Eccentricity = 0, SemiMajorAxis = 6400000, Inclination = 0, AscendingNodeLongitude = 0, PeriapsisArgument = 0, TrueAnomaly = 0, Name = "New satellite"):
        ArtificialSatellite.__init__(self, Eccentricity, SemiMajorAxis, Inclination, AscendingNodeLongitude, PeriapsisArgument)
        pass
    pass