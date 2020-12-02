import math

def EllipseAngleCheck(*params):
    '''
    Returns true if all parameters are less then pi and greater than or equal to -pi.
    Otherwise returns false.
    '''
    for value in params:
        if  not -math.pi <= value < math.pi:
            return False
        pass
    return True
    pass



