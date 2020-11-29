using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sputnik
{
    public class ShootPoint : StaticObject
    {
        public ShootPoint() : base()
        {
            HasShot = false;
        }

        public ShootPoint(double latitudes, double longitudes) : base(latitudes, longitudes)
        {
            HasShot = false;
        }
        public bool HasShot //снята ли точка
        {
            get; set;
        }
    }
}
