from Ellipse import Ellipse
import math

class Orbit(Ellipse):
    """
    Class Orbit. More information in Ellipse docementation and https://en.wikipedia.org/wiki/Orbital_elements
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
    Setters:
        1) Eccentricity
        2) SemiMajorAxis
        3) Inclination
        4) AscendingNodeLongitude
        5) PeriapsisArgument
    """

    def __init__(self, Eccentricity = 0, SemiMajorAxis = 6400000, Inclination = 0, AscendingNodeLongitude = 0, PeriapsisArgument = 0):
        """
        Constructor. Example: orbit = Orbit(Eccentricity, SemiMajorAxis, Inclination, AscendingNodeLongitude, PeriapsisArgument)
        0 <= Eccentricity < 1, default = 0
        SemimajorAxis > 0, default = 6400000
        -pi <= Inclination < pi, default = 0
        -pi <= AscendingNodeLongitude < pi, default = 0
        -pi <= PeriapsisArgument < pi, default = 0
        """
        Ellipse.__init__(self, Eccentricity, SemiMajorAxis)
        self.__Inclination = Inclination
        self.__AscendingNodeLongitude = AscendingNodeLongitude
        self.__PeriapsisArgument = PeriapsisArgument
        pass

    @property
    def Inclination(self):
        """
        Returns inclination. Example: a = orbit.Inclination
        """
        return self.__Inclination

    @property
    def AscendingNodeLongitude(self):
        """
        Returns longitude of the ascending node. Example: a = orbit.AscendingNodeLongitude
        """
        return self.__AscendingNodeLongitude

    @property
    def PeriapsisArgument(self):
        """
        Returns argument of periapsis. Example: a = orbit.PeriapsisArgument
        """
        return self.__PeriapsisArgument
    
    @Inclination.setter
    def Inclination(self, value):
        """
        Sets inclination. Example: orbit.Inclination = a
        If a < -pi or a >= pi inclination  won't be set
        """
        if -math.pi <= value < math.pi:
            self.__Inclination = value
         
    @AscendingNodeLongitude.setter
    def AscendingNodeLongitude(self, value):
        """
        Sets longitude of the ascending node. Example: orbit.AscendingNodeLongitude = a
        If a < -pi or a >= pi longitude of the ascending node  won't be set
        """
        if -math.pi <= value < math.pi:
            self.__AscendingNodeLongitude = value
            pass
        pass

    @PeriapsisArgument.setter
    def PeriapsisArgument(self, value):
        """
        Sets argument of periapsis. Example: orbit.PeriapsisArgument = a
        If a < -pi or a >= pi argument of periapsis  won't be set
        """
        if -math.pi <= value < math.pi:
            self.__PeriapsisArgument = value
            pass
        pass
    pass
