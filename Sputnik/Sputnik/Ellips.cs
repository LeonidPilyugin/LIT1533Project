using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;

namespace Sputnik
{
    public class Ellips
    {
        protected double eccentricity; //эксцентриситет
        protected double A; //большая полуось

        public Ellips()
        {
            A = Constants.Ae;
            eccentricity = 0;
        }

        public Ellips(double a, double e)
        {
            this.A = a;
            this.eccentricity = e;
        }

        public double b //малая полуось
        {
            get { return Sqrt(a * a * (1 - eccentricity * eccentricity)); }
        }
        public double p //фокальный параметр
        {
            get { return b * b / a; }
        }
        public double k //коэффициент сжатия
        {
            get { return 1 - eccentricity * eccentricity; }
        }
        public double c //фокальное расстояние
        {
            get { return a * eccentricity; }
        }
        public double Ra //апофокусное расстояние
        {
            get { return a * (1 + eccentricity); }
        }
        public double Rp //перифокусное расстояние
        {
            get { return a * (1 - eccentricity); }
        }
        public double a //большая полуось орбиты
        {
            get { return a; }
            set { a = value; }
        }
        public double e //эксцентриситет
        {
            get { return eccentricity; }
            set { eccentricity = value; }
        }

        /*
         * A a — большая полуось
         * B b — малая полуось
         * E e — эксцентриситет
         * C c — фокальное расстояние
         * P p — фокальный параметр
         * Rp — перифокусное расстояние
         * Ra — апофокусное расстояние
         * Функции ниже строятся по типу: [Возвращаемый параметр]By[параметр 1][параметр2]([параметр1], [параметр2])
          */

        public static double EByCA(double c, double a) 
        {
            return c / a;
        }

        public static double EByAB(double a, double b)
        {
            return Sqrt(1 - b * b / a / a);
        }

        public static double CByAE(double a, double e)
        {
            return a * e;
        }

        public static double CByBE(double b, double e)
        {
            return b * e / Sqrt(1 - e * e);
        }

        public static double CByPE(double p, double e)
        {
            return p * e / (1 - e * e);
        }

        public static double CByRpE(double Rp, double e)
        {
            return Rp * e / (1 - e);
        }

        public static double CByRaE(double Ra, double e)
        {
            return Ra * e / (1 + e);
        }

        public static double PByAE(double a, double e)
        {
            return a * (1 - e * e);
        }

        public static double PByBE(double b, double e)
        {
            return b * Sqrt(1 - e * e);
        }

        public static double PByCE(double c, double e)
        {
            return c * (1 - e * e) / e;
        }

        public static double PByRpE(double Rp, double e)
        {
            return Rp * (1 + e);
        }

        public static double PByRaE(double Ra, double e)
        {
            return Ra * (1 - e);
        }

        public static double RpByAE(double a, double e)
        {
            return a * (1 - e);
        }

        public static double RaByAE(double a, double e)
        {
            return a * (1 + e);
        }

        public static double RpByBE(double b, double e)
        {
            return b * Sqrt((1 - e)/(1 + e));
        }

        public static double RaByBE(double b, double e)
        {
            return b * Sqrt((1 + e) / (1 - e));
        }

        public static double RpByCE(double c, double e)
        {
            return c * (1 - e) / e;
        }

        public static double RaByCE(double c, double e)
        {
            return c * (1 + e) / e;
        }

        public static double RpByPE(double p, double e)
        {
            return p / (1 + e);
        }

        public static double RaByPE(double p, double e)
        {
            return p / (1 - e);
        }

        public static double RpByRaE(double Ra, double e)
        {
            return Ra * (1 - e) / (1 + e);
        }

        public static double RaByRpE(double Rp, double e)
        {
            return Rp * (1 + e) / (1 - e);
        }

        public static double AByBE(double b, double e)
        {
            return b / Sqrt(1 - e * e);
        }

        public static double BByAE(double a, double e)
        {
            return a * Sqrt(1 - e * e);
        }

        public static double AByCE(double c, double e)
        {
            return c / e;
        }

        public static double BByCE(double c, double e)
        {
            return c / e * Sqrt(1 - e * e);
        }

        public static double AByPE(double p, double e)
        {
            return p / (1 - e * e);
        }

        public static double BByPE(double p, double e)
        {
            return p / Sqrt(1 - e * e);
        }

        public static double AByRpE(double Rp, double e)
        {
            return Rp/(1 - e);
        }

        public static double BByRpE(double Rp, double e)
        {
            return Rp * Sqrt((1 + e) / (1 - e));
        }

        public static double AByRaE(double Ra, double e)
        {
            return Ra / (1 + e);
        }

        public static double BByRaE(double Ra, double e)
        {
            return Ra * Sqrt((1 - e) / (1 + e));
        }

        public static double K(double e) // коэффициент сжатия
        {
            return 1 - e * e;
        }
    }
}
