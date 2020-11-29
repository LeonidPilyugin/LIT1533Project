from ObjectOnEarth import ObjectOnEarth

class ShootPoint(ObjectOnEarth): #точка для съемки наследуется от ObjectOnEarth
    def __init__(self, Longitudes, Latitudes): #конструктор
        ObjectOnEarth.__init__(Longitudes, Latitudes)
        self.__IsShot = False #снята ли точка
        pass

    @property #свойство возвращаетЮ снята ли точка
    def IsShot(self):
        return self.__IsShot

    def Shoot(self): #метод делает точку снятой
        self.IsShot = True
        pass
    pass