using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;

namespace Sputnik
{
    public class Sputnik : TypeInList
    {
        public Sputnik(double a, double e, double i, double l, double w, double m)
        {
            orbit = new Orbit(a, e, i, l, w);
            this.m = m;
        }

        public Sputnik()
        {
            orbit = new Orbit();
            m = 0;
        }

        public void ChangeTrueAnomaly(double t) //при вызове изменяет истинную аномалию, аргумент — время, прошедшее в симуляции с последнего вызова
        {
            m += AngularVelocity * t;
            while (m >= 2 * PI)
                m -= 2 * PI;
        }

        public double AngularVelocity //угловая скорость
        {
            get { return Sqrt(Constants.G * Constants.Em * orbit.a * orbit.k) / orbit.p / orbit.p * (1 + orbit.e * Cos(m)) * (1 + orbit.e * Cos(m)); }
        }
        public double m //истинная аномалия
        {
            get; set;
        }
        public Orbit orbit//орбита
        {
            get; set;
        }
    }
}
