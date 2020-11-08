# Physics
Классы, отвечающие за физику

Класс Physics
Константы:
public const double G = 6.6743E-11; //гравитационная постоянная
public const double M = 5.972E-11;  //масса Земли
public const double Ae = 6378200;   //большая полуось земного эллипсоида
public const double Be = 6356900;   //малая полуось земного эллипсоида
public const double Ee = 0.08166;   //эксцентриситет земного эллипсоида

Класс Sputnik
Поля:
private double a; //большая полуось орбиты
private double e; //эксцентриситет орбиты
private double i; //наклонение орбиты
private double l; //долгота восходящего узла
private double w; //аргумент перицентра
private double m; //средняя аномалия
Конструкторы:
public Sputnik(double a, double e, double i, double l, double w, double m)
public Sputnik() //задаёт значение большой полуоси, равной экваториальному радиусу Земли, остальные значения зануляет
Методы:
public void ChangeTrueAnomaly(double t) //при вызове изменяет истинную аномалию, аргумент — время, прошедшее в симуляции с последнего вызова.
Свойства только для чтения:
public double b //малая полуось орбиты
public double p //фокальный параметр орбиты
public double k //коэффициент сжатия орбиты
public double c //фокальное расстояние орбиты
public double Ra //апофокусное расстояние орбиты
public double Rp //перифокусное расстояние орбиты
Свойства для чтения и записи:
public double A //большая полуось орбиты
public double E //эксцентриситет орбиты
public double I //наклонение орбиты
public double L //долгота восходящего узла орбиты
public double W //аргумент перицентра орбиты
public double M //средняя аномалия
