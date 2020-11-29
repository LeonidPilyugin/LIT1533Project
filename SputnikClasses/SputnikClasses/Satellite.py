import math
from Orbit import Orbit
import speedmath

class Satellite(Orbit):
    """
    Class Satellite. More information in Orbit docementation
    Properties:
        1) SemiminorAxis
        2) FocalParameter
        3) AspectRatio
        4) FocalDistance
        5) PerifocusDistance
        6) ApothecureDistance
        7) Eccentricity
        8) SemiMajorAxis
        9) Inclination
        10) AscendingNodeLongitude
        11) PeriapsisArgument
        12) TrueAnomaly
        13) Name
    Setters:
        1) Eccentricity
        2) SemiMajorAxis
        3) Inclination
        4) AscendingNodeLongitude
        5) PeriapsisArgument
        6) TrueAnomaly
        7) Name
    Methods:
        1) ChangeTrueAnomalyByLongTimeInterval
    """

    def __init__(self, Eccentricity = 0, SemiMajorAxis = 6400000, Inclination = 0, AscendingNodeLongitude = 0, PeriapsisArgument = 0, TrueAnomaly = 0, DirectionRatio = 1, Name = 'New satellite'):
        """
        Constructor. Example: satellite = Satellite(Eccentricity, SemiMajorAxis, Inclination, AscendingNodeLongitude, PeriapsisArgument, DirectionRatio, Name)
        0 <= Eccentricity < 1, default = 0
        SemimajorAxis > 0, default = 6400000
        -pi <= Inclination < pi, default = 0
        -pi <= AscendingNodeLongitude < pi, default = 0
        -pi <= PeriapsisArgument < pi, default = 0
        Name is a string, default = 'New satellite'
        DirectionRatio is a number (1 or -1) which shows direction of rotation
        """
        Orbit.__init__(self, Eccentricity, SemiMajorAxis, Inclination, AscendingNodeLongitude, PeriapsisArgument)
        self.__TrueAnomaly = TrueAnomaly
        self.__Name = Name
        self.DirectionRatio = DirectionRatio
        pass

    @property
    def DirectionRatio(self):
        return self.DirectionRatio

    @property
    def TrueAnomaly(self):
        """
        Returns true anomaly. Example: a = satellite.TrueAnomaly
        """
        return self.__TrueAnomaly

    @property
    def Name(self):
        """
        Returns name. Example: a = satellite.Name
        """
        return self.__Name
        
    @Name.setter
    def Name(self, Name):
        """
        Sets name. Example: satellite.Name = a
        If a isn't string name won't be set
        """
        if(object(str, Name)):
            self.__Name = Name
            pass
        pass


    @TrueAnomaly.setter
    def TrueAnomaly(self, value):
        """
        Sets direction ratio. Example: satellite.TrueAnomaly = a
        If If a < -pi or a >= pi true anomaly won't be set
        """
        if -math.pi <= value < math.pi:
            self.__TrueAnomaly = value
            pass
        pass

    @DirectionRatio.setter
    def DirectionRatio(self, DirectionRatio):
        if DirectionRatio == 1 or -1:
            self.__DirectionRatio = DirectionRatio
            pass
        pass

    def ChangeTrueAnomaly(self, TimeInterval):
        """
        Sets true anomaly a new value. Example: satellite.ChangeTrueAnomalyByLongTimeInterval(TimeInterval)
        TimeInterval is a time interval between last and this call
        """
        self.__TrueAnomaly = speedmath.TrueAnomaly(self._Ellipse__Eccentricity, self._Ellipse__SemiMajorAxis, self.__TrueAnomaly, TimeInterval, self.__DirectionRatio)
        pass

    def TimeInterval(self, StartTrueAnomaly, FinishTrueAnomaly):
        return speedmath.TimeInterval(self._Ellipse__Eccentricity, self._Ellipse__SemiMajorAxis, StartTrueAnomaly, FinishTrueAnomaly, self.__DirectionRatio)

    pass

