from ObjectOnEarth import ObjectOnEarth
class InformationBase(ObjectOnEarth): #класс пункта сброса информации наследуется от ObjectOnEarth
    def __init__(self, Longitudes, Latitudes):
        ObjectOnEarth.__init__(Longitudes, Latitudes)
        pass
    pass