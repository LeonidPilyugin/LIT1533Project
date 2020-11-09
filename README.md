# Sputnik
Класс, отвечающий за спутник (dll библиотека)

namespace Sputnik

Класс Physics

Константы:

public const double G = 6.6743E-11; //гравитационная постоянная

public const double Em = 5.972E-11;  //масса Земли

public const double Ae = 6378200;   //большая полуось земного эллипсоида

public const double Be = 6356900;   //малая полуось земного эллипсоида

public const double Ee = 0.08166;   //эксцентриситет земного эллипсоида

Класс SputnikGroup

Поля:

List<SputnikGroup> SputnikList //список спутников и групп спутников, входящих в группу
  
public TypeOfGroup Type //тип группы

Тип:

public enum TypeOfGroup { Trawl, Web, Other, No }

Конструкторы:

public SputnikGroup()
{
    SputnikList = new List<SputnikGroup>();
    Type = TypeOfGroup.No;
}
  
public SputnikGroup(TypeOfGroup Type)
{
    SputnikList = new List<SputnikGroup>();
    this.Type = Type;
}
  
Свойства для чтения:

public List<SputnikGroup> SputnikList
  
Свойства для чтения и записи

public TypeOfGroup Type

Класс Sputnik : SputnikGroup

Поля:

private double a; //большая полуось орбиты

private double e; //эксцентриситет орбиты

private double i; //наклонение орбиты

private double l; //долгота восходящего узла

private double w; //аргумент перицентра

private double m; //средняя аномалия

Конструкторы:

public Sputnik(double a, double e, double i, double l, double w, double m)
{
    this.a = a;
    this.e = e;
    this.i = i;
    this.l = l;
    this.w = w;
    this.m = m;
}

public Sputnik()
{
    a = Physics.Ae;
    e = 0;
    i = 0;
    l = 0;
    w = 0;
    m = 0;
}

Методы:

public void ChangeTrueAnomaly(double t) //при вызове изменяет истинную аномалию, аргумент — время, прошедшее в симуляции с последнего вызова.

Свойства только для чтения:

public double AngularVelocity //угловая скорость

public double b //малая полуось орбиты

public double p //фокальный параметр орбиты

public double k //коэффициент сжатия орбиты

public double c //фокальное расстояние орбиты

public double Ra //апофокусное расстояние орбиты

public double Rp //перифокусное расстояние орбиты

Свойства для чтения и записи аналогичны полям

Абстрактный класс StaticObject

Поля:

protected double longitudes;//долгота

protected double latitudes;//широта

Конструкторы:

public StaticObject()
{
    latitudes = longitudes = 0;
}

public StaticObject(double latitudes, double longitudes)
{
    this.latitudes = latitudes;
    this.longitudes = longitudes;
}

Свойства для чтения и записи:

public double Longitudes //долгота

public double Latitudes //широта

Класс ShootPoint : StaticObject

Поля:

bool HasShot //снята ли точка

Конструкторы:

public ShootPoint() : base()
{
    HasShot = false;
}

public ShootPoint(double latitudes, double longitudes) : base(latitudes, longitudes)
{
    HasShot = false;
}

Свойства для чтения и записи

bool HasShot

Класс ResetInformationItem : StaticObject

Конструкторы:

public ResetInformationItem() : base() { }

public ResetInformationItem(double latitudes, double longitudes) : base(latitudes, longitudes) { }
