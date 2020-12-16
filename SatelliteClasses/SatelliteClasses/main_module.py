import aiomas
import time
import math

#class Caller(aiomas.Agent):
    #async def run(self, callee_addr):
        #print(self, 'connecting to', callee_addr)
        # Ask the container to make a connection to the other agent:
        #callee = await self.container.connect(callee_addr)
        #print(self, 'connected to', callee)
        # "callee" is a proxy to the other agent.  It allows us to call
        # the exposed methods:
        #result1 = await callee.ExposeTimeInterval(-3.1415926)
        #print(self, 'got', result)

import satellites
sat = satellites.Satellite()
sat.Eccentricity = 0.4
sat.TrueAnomaly = 3
Time = 2 * math.pi / math.sqrt(3.986e14 / math.pow(6400000, 3))
print(time.clock())
for i in range(100000):
    sat.change_true_anomaly(Time/100000)
print(time.clock())

