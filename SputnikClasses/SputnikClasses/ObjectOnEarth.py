class ObjectOnEarth(object): #класс объектов, расположенных на земной поверхности
    def __init__(self, Longitudes, Latitudes): #конструктор
        self.__Longitudes = Longitudes #долгота
        self.__Latitudes = Latitudes #широта
        pass

    @property
    def Longitudes(self): #свойство возвращает долготу
        return self.__Longitudes

    @property
    def Latitudes(self): #свойство возвращает широту
        return self.__Latitudes

    @Longitudes.setter #свойство задает долготу
    def Longitudes(self, Longitudes):
        if -180 < Longitudes <= 180:
            self.__Longitudes = Longitudes
            pass
        pass

    @Latitudes.setter #свойство задает широту
    def Latitudes(self, Latitudes):
        if -90 <= Latitudes <= 90:
            self.__Latitudes = Latitudes
            pass
        pass
    pass

