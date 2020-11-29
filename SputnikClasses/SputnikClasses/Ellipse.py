import speedmath

class Ellipse(object):
    """
    Ellipse class. Information about ellipse https://en.wikipedia.org/wiki/Ellipse. Used International System of Units units (https://en.wikipedia.org/wiki/International_System_of_Units)
    Properties:
        1) SemiminorAxis
        2) FocalParameter
        3) AspectRatio
        4) FocalDistance
        5) PerifocusDistance
        6) ApothecureDistance
        7) Eccentricity
        8) SemiMajorAxis
    Setters:
        1) Eccentricity
        2) SemiMajorAxis
    """

    def __init__(self, Eccentricity = 0, SemiMajorAxis = 6400000):
        """
        Constructor. Example: ellipse = Ellipse(Eccentricity, SemiMajorAxis)
        0 <= Eccentricity < 1, default = 0
        SemimajorAxis > 0, default = 6400000
        """
        self.__Eccentricity = Eccentricity
        self.__SemiMajorAxis = SemiMajorAxis
        pass
     
    @property
    def Eccentricity(self):
        """
        Returns eccentricity. Example: a = ellipse.Eccentricity
        """
        return self.__Eccentricity

    @property
    def SemiMajorAxis(self):
        """
        Returns semi-major axis. Example: a = ellipse.SemiMajorAxis
        """
        return self.__SemiMajorAxis

    @property
    def SemiMinorAxis(self):
        """
        Returns semi-minor axis. Example: a = ellipse.SemiMinorAxis
        """
        return speedmath.SemiminorAxis(self.__Eccentricity, self.__SemiMajorAxis)

    @property
    def SemiLatusRectum(self):
        """
        Returns semi-latus rectum. Example: a = ellipse.Eccentricity
        """
        return speedmath.SemiLatusRectum(self.__Eccentricity, self.__SemiMajorAxis)

    @property
    def AspectRatio(self):
        """
        Returns aspect ratio. Example: a = ellipse.AspectRatio
        """
        return speedmath.AspectRatio(self.__Eccentricity)

    @property
    def FocalDistance(self):
        """
        Returns focal distance. Example: a = ellipse.FocalDistance
        """
        return speedmath.FocalDistance(self.__Eccentricity, self.__SemiMajorAxis)

    @property
    def PerifocusDistance(self):
        """
        Returns perifocus distance. Example: a = ellipse.PerifocusDistance
        """
        return speedmath.PerifocusDistance(self.__Eccentricity, self.__SemiMajorAxis)
    
    @property
    def ApothecureDistance(self):
        """
        Returns aothecure distance. Example: a = ellipse.ApothecureDistance
        """
        return speedmath.ApothecureDistance(self.__Eccentricity, self.__SemiMajorAxis)

    @Eccentricity.setter
    def Eccentricity(self, Eccentricity):
        """
        Sets eccentricity. Example: ellipse.Eccentricity = a
        If a < 0 or a >= 1 eccenricity  won't be set
        """
        if 0 <= Eccentricity < 1:
            self.__Eccentricity = Eccentricity
            pass
        pass

    @SemiMajorAxis.setter
    def SemiMajorAxis(self, value):
        """
        Sets semi-major axis. Example: ellipse.SemiMajorAxis = a
        If a < 0 semi-major axis won't be set
        """
        if value > 0:
            self.__SemiMajorAxis = value
            pass
        pass
    pass
    