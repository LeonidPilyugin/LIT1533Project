from EarthObjects.GroundObject import GroundObject

class GroundStation(GroundObject):

    '''
    This class describes ground station.
    Class GroundStation inherits from class GroundObject.
    '''

    __slots__ = ("_Longitude", "_Latitude")

    def __init__(self):
        GroundObject.__init__(self)
        pass
    pass


