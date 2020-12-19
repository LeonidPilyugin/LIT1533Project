import math
import aiomas
from usefull_functions import *
import orbits
from _speedmath import *

# определить граничные значения КПО

class SatelliteMethodError(Exception):
    pass

class Satellite(object):

    '''
    Class Satellite describes satellite. More information: 
    https://en.wikipedia.org/wiki/Satellite

    Attributes:
        1) _true_anomaly
        2) _direction_ratio
        3) _id
        4) _orbit

    Properties:
        1) true_anomaly
        2) direction_ratio
        3) name
        4) orbit

    Setters:
        1) true_anomaly
        2) direction_ratio
        3) name
        4) orbit

    Methods:
        1) change_true_anomaly(TimeInterval)
        2) time_interval(StartTrueAnomaly, FinishTrueAnomaly)
    '''
    

    def __init__(self):
        '''
        This constructor sets:
        _Eccentricity = 0.0
        _SemiMajorAxis = 6400000.0
        _Inclination = 0.0
        _AscendingNodeLongitude = 0.0
        _PeriapsisArgument = 0.0
        _id = "New Satellite"
        _TrueAnomaly = 0.0
        _DirectionRatio = 1
        _Orbit = EllipticOrbit()
        '''
        super().__init__()
        self._true_anomaly = 0.0
        self._direction_ratio = 1
        self._id = "New Satellite"
        self._orbit = orbits.EllipticOrbit()
        pass


    def parse(self):
        return self._orbit.parse() + (self._true_anomaly, self.direction_ratio)

    @property
    def true_anomaly(self):
        '''
        Returns true anomaly.
        '''
        return self._true_anomaly

    @property
    def direction_ratio(self):
        '''
        Returns direction ratio.
        '''
        return self._direction_ratio

    @property
    def id(self):
        '''
        Returns id.
        '''
        return self._id

    @property
    def orbit(self):
        '''
        Returns orbit.
        '''
        return self._orbit


    @direction_ratio.setter
    def direction_ratio(self, value : int):
        '''
        Sets direction ratio. It must be 1 or -1. 
        Direction ratio is a coefficient at angular velocity.
        '''
        if value == -1 or value == 1:
            self._direction_ratio = value
            pass
        else:
            raise ValueError("Direction ratio must be 1 or -1")

    @true_anomaly.setter
    def true_anomaly(self, value : float):
        '''
        Sets true anomaly. It must be 
        less than pi and greater than or equal to -pi.
        '''
        if isinstance(self._orbit, orbits.EllipticOrbit):
            if ellipse_check_angle(value):
                self._true_anomaly = value
                pass
            else:
                raise ValueError("True anomaly must be less then pi and \
                                  greater than or equal to -pi.")
            pass
        else:
            raise Warning("true_anomaly setter works only \
                           with EllipticalOrbit. If you want to use other \
                           orbit types, you should edit it.")

    @id.setter
    def id(self, value : str):
        '''
        Sets name. It must be string.
        '''
        if isinstance(value, str):
            self._id = value
            pass
        else:
            raise ValueError("Name must be a string")
        pass

    @orbit.setter
    def orbit(self, value):
        '''
        Sets orbit. It must be child class of Orbit.
        '''
        if isinstance(value, orbits.Orbit):
            self._orbit = value
            pass
        else:
            raise ValueError("orbit must be child class of Orbit")
        pass


    def change_true_anomaly(self, time_interval : float):
        '''
        Changes true anomaly by time interval.
        This method works correctly with eccentricity <= 0.8
        '''
        if isinstance(self._orbit, orbits.EllipticOrbit):
            self._true_anomaly = compute_elliptic_orbit_true_anomaly(self.parse(), time_interval)
            pass
        else:
            raise SatelliteMethodError("This method works only with \
            EllipticOrbit. If you want to use other orbit types, \
            you should edit it.")

    def time_interval(self, finish_true_anomaly : float):
        '''
        Returns time interval between two values of true anomaly.
        '''
        if not ellipse_check_angle(finish_true_anomaly):
            raise ValueError("finish_true_anomaly must be less then pi and \
                              greater than or equal to -pi.")
        if isinstance(self._orbit, orbits.EllipticOrbit):
            return speedmath.compute_elliptic_orbit_time_interval(self.parse(), 
                                                          finish_true_anomaly)
        else:
            raise SatelliteMethodError("time_interval works only with \
                           EllipticOrbit. If you want to use other \
                           orbit types, you should edit it.")

    pass


#class MobileSatellite(Satellite):



    #def __init__(self):
        #super().__init__()
        #self.

class SmartSatellite(aiomas.Agent, Satellite):

    '''
    aiomas documentation: 
    https://aiomas.readthedocs.io/en/2.0.1/overview.html
    In module agent, line 474 completed command 
    "super().__init__()" for the super() method to work correctly
    '''

    def __init__(self, container):
        super().__init__(container)
        can_contact = True
        pass

    @aiomas.expose
    def can_shoot(self, shoot_point):
        return can_shoot(self.parse())

    pass



class SatelliteGroup(object):

    '''
    Class SatelliteGroup describes group of satellites.

    Attributes:
        1) _satellite_list
        2) _id

    Properties:
        1) id

    Setters:
        1) id
        2) Lenth

    Methods:
        1) append(item)
        2) clear()
        3) index(item)
        4) remove(item)

    Others:
        1) indexers (__getitem__, __setitem__, __delitem__)
    '''


    def __init__(self):
        '''
        This constructor sets:
        _SatelliteList = list()
        _Name = "New group"
        '''
        super().__init__()
        self._satellite_list = list()
        self._id = "New group"
        pass


    @property
    def id(self):
        '''
        Returns name
        '''
        return self._id


    @id.setter
    def id(self, id):
        '''
        Sets name. It must be string
        '''
        if isinstance(id, str):
            self._id = id
            pass
        else:
            raise ValueError("Name must be string")
        pass


    def append(self, item):
        '''
        Appends new item to list. It must be Satellite or 
        SatelliteGroup object or their child
        '''
        if isinstance(item, Satellite) or isinstance(item, SatelliteGroup):
            self._satellite_list.append(item)
            pass
        else:
            raise ValueError("Item must be Satellite or \
                              SatelliteGroup object or their child")
        pass

    def clear(self):
        '''
        Does the same that list.clear()
        '''
        self._satellite_list.clear()
        pass

    def index(self, item):
        '''
        Does the same that list.index(item)
        '''
        return self._satellite_list.index(item)

    @property
    def lenth(self):
        '''
        Does the same that len(list)
        '''
        return len(self._satellite_list)
    
    def remove(self, item):
        '''
        Does the same that list.remove(item)
        '''
        self._satellite_list.remove(item)
        pass

    def __getitem__(self, key):
        return self._satellite_list[key]

    def __setitem__(self, key, item):
        if isinstance(item, Satellite) or isinstance(item, SatelliteGroup):
            self._satellite_list[key] = item
            pass
        else:
            raise ValueError("Item must be Satellite or \
                              SatelliteGroup object or their child")
        pass

    def __delitem__(self, key):
        del self._satellite_list[key]
        pass

    pass
