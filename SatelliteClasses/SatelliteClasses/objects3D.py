
class Point3D(object):
    """
    """

    def __init__(self):
        super().__init__()
        self._x = 0.0
        self._y = 0.0
        self._z = 0.0

    def parse(self):
        return _x, _y, _z

    @property
    def x(self):
        return self._x
    
    @property
    def y(self):
        return self._y

    @property
    def z(self):
        return self._z
    
    @x.setter
    def x(self, value):
        if isinstance(value, float):
            self._x = value
            pass
        else:
            raise ValueError("x must be a number")
    
    @y.setter
    def y(self, value):
        if isinstance(value, float):
            self._y = value
            pass
        else:
            raise ValueError("y must be a number")
        
    @z.setter
    def z(self, value):
        if isinstance(value, float):
            self._z = value
            pass
        else:
            raise ValueError("z must be a number")
    pass



class Segment3D(object):
    def __init__(self):
        super().__init__()
        self._first = Point3D()
        self._last = Point3D()
        pass

    def parse(self):
        return _first.parse() + _last.parse()

    @property
    def first(self):
        return self._first
    
    @property
    def last(self):
        return self._last

    pass



class Object3D(object):

    """
    Now it is a sphere with radius 10m
    """

    def __init__():
        super().__init__()
        self._center = Point3D()
        self._radius = 10.0
        pass

    def parse(self):
        return _center.parse() + _radius

    @property
    def center(self):
        return self._center

    @property
    def radius(self):
        return self._radius

    @radius.setter
    def radius(self, value):
        if value > 0:
            self._radius = value
        else:
            raise ValueError("Radius must be more than 0")
        pass

    def is_crossed(self, segment):
