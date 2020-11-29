#import aiomas
from Satellite import Satellite
import math

sat1 = Satellite(0, 64000000, 0, 0, 0, 0, 1, "sat1")
sat2 = Satellite(0, 64000000, 0, 0, 0, 0, -1, "sat2")

a = 2 * math.pi * math.sqrt(sat1.SemiMajorAxis * sat1.SemiMajorAxis * sat1.SemiMajorAxis / 3.986e14)

print(sat1.TimeInterval(math.pi / 4 * 3, -math.pi / 4 * 3) / a)
#print(sat1.TimeInterval(0, -math.pi / 2) / a)
#print(sat2.TimeInterval(0, math.pi / 2) / a)
print(sat2.TimeInterval(-math.pi / 4 * 3, math.pi / 4 * 3) / a)