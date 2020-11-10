# Sputnik
Классы, отвечающий за спутник (dll библиотека).

namespace Sputnik

* public static class Constants

*константы:

public const double G = 6.6743E-11; //гравитационная постоянная

public const double Em = 5.972E24;  //масса Земли

public const double Ae = 6378200;   //большая полуось земного эллипсоида

public const double Be = 6356900;   //малая полуось земного эллипсоида

* public class Ellips

*поля:

protected double eccentricity; //эксцентриситет

protected double A; //большая полуось

*конструкторы:

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

*свойства только для чтения:

public double b //малая полуось

public double p //фокальный параметр

public double k //коэффициент сжатия

public double c //фокальное расстояние

public double Ra //апофокусное расстояние

public double Rp //перифокусное расстояние

*свойства для чтения и записи:

public double a //большая полуось орбиты

public double e //эксцентриситет

*статические методы:


  A a — большая полуось
  B b — малая полуось
  E e — эксцентриситет
  C c — фокальное расстояние
  P p — фокальный параметр
  Rp — перифокусное расстояние
  Ra — апофокусное расстояние
  Функции ниже строятся по типу: [Возвращаемый параметр]By[параметр 1][параметр2]([параметр1], [параметр2])


Например, EByCA — возвращает эксцентриситет, принимает параметры фокальное расстояние и большая полуось

public static double EByCA(double c, double a) 

public static double EByAB(double a, double b)

public static double CByAE(double a, double e)

public static double CByBE(double b, double e)

public static double CByPE(double p, double e)

public static double CByRpE(double Rp, double e)

public static double CByRaE(double Ra, double e)

public static double PByAE(double a, double e)

public static double PByBE(double b, double e)

public static double PByCE(double c, double e)

public static double PByRpE(double Rp, double e)

public static double PByRaE(double Ra, double e)

public static double RpByAE(double a, double e)

public static double RaByAE(double a, double e)

public static double RpByBE(double b, double e)

public static double RaByBE(double b, double e)

public static double RpByCE(double c, double e)

public static double RaByCE(double c, double e)

public static double RpByPE(double p, double e)

public static double RaByPE(double p, double e)

public static double RpByRaE(double Ra, double e)

public static double RaByRpE(double Rp, double e)

public static double AByBE(double b, double e)

public static double BByAE(double a, double e)

public static double AByCE(double c, double e)

public static double BByCE(double c, double e)

public static double AByPE(double p, double e)

public static double BByPE(double p, double e)

public static double AByRpE(double Rp, double e)

public static double BByRpE(double Rp, double e)

public static double AByRaE(double Ra, double e)

public static double BByRaE(double Ra, double e)

public static double K(double e) // коэффициент сжатия
        
* public class Orbit : Ellips

*поля:

private double i //наклонение орбиты

private double l //долгота восходящего узла

private double w //аргумент перицентра

*конструкторы:

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

*свойства для чтения и записи:

public double i //наклонение орбиты

public double l //долгота восходящего узла

public double w //аргумент перицентра

* public abstract class TypeInList (нужен для того, чтобы можно было создать список из производных классов)

* public class Sputnik : TypeInList

*поля:

private Orbit orbit //орбита:

*конструкторы:

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

*методы:

public void ChangeTrueAnomaly(double t) //при вызове изменяет истинную аномалию, аргумент — время, прошедшее в симуляции с последнего вызова

*свойства для чтения:

public double AngularVelocity //угловая скорость

*свойства для чтения и записи:

public double m //истинная аномалия

public Orbit orbit//орбита

* public class SputnikGroup : TypeInList

*типы:

public enum TypeOfGroup { Trawl, Web, Other, No }

*поля:

private List<TypeInList> SputnikList//список спутников

private TypeOfGroup Type//тип группы

*конструкторы:

public SputnikGroup()
{
    SputnikList = new List<TypeInList>();
    Type = TypeOfGroup.No;
}

public SputnikGroup(TypeOfGroup Type)
{
    SputnikList = new List<TypeInList>();
    this.Type = Type;
}
  
*свойства для чтения и записи:

public TypeOfGroup Type//тип группы

*свойства для чтения:

public List<TypeInList> SputnikList//список спутников
  
*методы:

public void Add(TypeInList sputnikgroup)//добавить элемент

public void Clear()//удалить все элементы

public void Remove(TypeInList sputnikgroup)//удалить элемент

* public abstract class StaticObject

*поля:

protected double longitudes; //долгота

protected double latitudes; //широта

*конструкторы:

public StaticObject()
{
    latitudes = longitudes = 0;
}

public StaticObject(double latitudes, double longitudes)
{
    this.latitudes = latitudes;
    this.longitudes = longitudes;
}

*свойства для чтения и записи:

public double Longitudes //долгота

public double Latitudes //широта

* public class ResetInformationItem : StaticObject

* public class ShootPoint : StaticObject

*поля:

private bool HasShot //снята ли точка

*конструкторы:

public ShootPoint() : base()
{
    HasShot = false;
}

public ShootPoint(double latitudes, double longitudes) : base(latitudes, longitudes)
{
    HasShot = false;
}

*свойства для чтения и записи:

public bool HasShot //снята ли точка
