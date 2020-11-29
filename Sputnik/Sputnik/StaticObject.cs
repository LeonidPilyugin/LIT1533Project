using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sputnik
{
    public abstract class StaticObject
    {
        protected double longitudes; //долгота
        protected double latitudes; //широта
        public StaticObject()
        {
            latitudes = longitudes = 0;
        }

        public StaticObject(double latitudes, double longitudes)
        {
            this.latitudes = latitudes;
            this.longitudes = longitudes;
        }
        public double Longitudes //долгота
        {
            get { return longitudes; }
            set { longitudes = value; }
        }

        public double Latitudes //широта
        {
            get { return latitudes; }
            set { latitudes = value; }
        }
    }
}
