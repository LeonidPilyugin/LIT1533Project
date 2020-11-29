from Satellite import Satellite

class SatelliteGroup(object): #класс группы спутников
    def __init__(self, *params): #конструктор принимает спутники и группы спутников
        self.__SatelliteList = list() #список спутников
        for n in params:
            self.__SatelliteList.append(n)
            pass
        pass

    @property #свойство возвращает список спутников
    def List(self):
        return self.__SatelliteList

    def Append(self, item): #метод добавляет элемент
        if object(Satellite, item) or object(SatelliteGroup, item):
            self.__SatelliteList.append(item)

    def Clear(self): #метод очищает список
        self.__SatelliteList.clear()
        pass

    def Index(self, item): #метод возвращает индекс элемента
        if item in self.__SatelliteList:
            return self.__SatelliteList.index(item)
        pass

    @property
    def Len(self): #свойство возвращает длину списка
        return len(self.__SatelliteList)

    def Remove(self, item): #метод удаляет элемент
        if item in self.__SatelliteList:
            self.Remove(item)
            pass
        pass
    pass
