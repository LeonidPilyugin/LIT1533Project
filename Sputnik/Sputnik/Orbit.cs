using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;

namespace Sputnik
{
    public class Orbit : Ellips
    {
        public Orbit() : base()
        {
            i = 0;
            l = 0;
            w = 0;
        }

        public Orbit(double a, double e, double i, double l, double w) : base(a, e)
        {
            this.i = i;
            this.l = l;
            this.w = w;
        }
        public double i //наклонение орбиты
        {
            get; set;
        }
        public double l //долгота восходящего узла
        {
            get; set;
        }
        public double w //аргумент перицентра
        {
            get; set;
        }
    }
}
