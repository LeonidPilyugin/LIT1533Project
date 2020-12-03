from Satellites.Satellite import Satellite

class SatelliteGroup(object):

    '''
    Class SatelliteGroup describes group of satellites.

    Attributes:
        1) _SatelliteList
        2) _Name

    Properties:
        1) Name

    Setters:
        1) Name
        2) Lenth

    Methods:
        1) Append(item)
        2) Clear()
        3) Index(item)
        4) Remove(item)

    Others:
        1) indexers (__getitem__, __setitem__, __delitem__)
    '''

    __slots__ = ("_SatelliteList", "_Name")

    def __init__(self):
        '''
        This constructor sets:
        _SatelliteList = list()
        _Name = "New group"
        '''
        self._SatelliteList = list()
        self._Name = "New group"
        pass

    @property
    def Name(self):
        '''
        Returns name
        '''
        return self._Name

    @Name.setter
    def Name(self, Name):
        '''
        Sets name. It must be string
        '''
        if isinstance(Name, str):
            self._Name = Name
            pass
        else:
            raise ValueError("Name must be string")
        pass

    def Append(self, item):
        '''
        Appends new item to list. It must be Satellite or SatelliteGroup object or their child
        '''
        if isinstance(item, Satellite) or isinstance(item, SatelliteGroup):
            self._SatelliteList.append(item)
            pass
        else:
            raise ValueError("Item must be Satellite or SatelliteGroup object or their child")
        pass

    def Clear(self):
        '''
        Does the same that list.clear()
        '''
        self._SatelliteList.clear()
        pass

    def Index(self, item):
        '''
        Does the same that list.index(item)
        '''
        return self._SatelliteList.index(item)
    @property
    def Lenth(self):
        '''
        Does the same that len(list)
        '''
        return len(self._SatelliteList)
    
    def Remove(self, item):
        '''
        Does the same that list.remove(item)
        '''
        self._SatelliteList.remove(item)
        pass

    def __getitem__(self, key):
        return self._SatelliteList[key]

    def __setitem__(self, key, item):
        if isinstance(item, Satellite) or isinstance(item, SatelliteGroup):
            self._SatelliteList[key] = item
            pass
        else:
            raise ValueError("Item must be Satellite or SatelliteGroup object or their child")
        pass

    def __delitem__(self, key):
        del self._SatelliteList[key]
        pass
    pass



