from Satellites.Satellite import Satellite

class SatelliteGroup(object):
    def __init__(self, *params):
        self._SatelliteList = list()
        self._Name = "New group"
        for n in params:
            self._SatelliteList.append(n)
            pass
        pass

    @property
    def List(self):
        return self._SatelliteList

    @property
    def Name(self):
        return self._Name

    @Name.setter
    def Name(self, Name):
        if isinstance(Name, str):
            self._Name = Name
            pass
        else:
            raise ValueError("Name must be a string")

    def Append(self, item):
        if isinstance(item, Satellite):
            self.__SatelliteList.append(item)
            pass
        else:
            raise ValueError("Item must be ")

    def Clear(self):
        self._SatelliteList.clear()
        pass

    def Index(self, item):
        return self._SatelliteList.index(item)

    @property
    def Len(self):
        return len(self._SatelliteList)

    def Remove(self, item):
        self.Remove(item)
        pass
    pass



