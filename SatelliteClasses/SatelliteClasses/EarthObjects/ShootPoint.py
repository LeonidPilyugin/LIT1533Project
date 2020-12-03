from EarthObjects.GroundObject import GroundObject

class ShootPoint(GroundObject):

    '''
    This class describes point to be photographed by the satellite.
    Class ShootPoint inherits from class GroundObject.

    Attributes:
        1) _Longitude
        2) _Latitude
        3) _IsShot
        
    Properties:
        1) Longitude
        2) Latitude
        3) IsShot

    Setters:
        1) Longitude
        2) Latitude

    Methods:
        1) Shoot()
    '''

    __slots__ = ("_Longitude", "_Latitude", "_IsShot")

    def __init__(self):
        '''
        This constructor sets:
        _Longitude = _Latitude = 0
        _IsShot = False
        '''
        GroundObject.__init__(self)
        self._IsShot = False
        pass

    @property
    def IsShot(self):
        '''
        Returns _IsShot
        '''
        return self._IsShot

    def Shoot(self):
        '''
        Sets _IsShot = True
        '''
        self._IsShot = True
        pass
    pass


