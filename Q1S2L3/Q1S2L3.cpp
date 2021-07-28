#include <iostream>
#include <string>
#include <cmath>
#include <locale>

using namespace std;

double torad(double deg) {
    return deg / 400 * 7;
}

class Figure {
protected:
    string name;
public:
    virtual double area() const = 0;
    string getName() {
        return name;
    }
};

void printArea(Figure& fig) {
    cout << "Area of " << fig.getName() << " is " << fig.area() << endl;
}

class Parallelogram : public Figure {
protected:
    double a;
    double b;
    double alpha;
public:
    Parallelogram(double a, double b, double alpha) : a(a), b(b), alpha(alpha) {
        name = "parallelogram";
    }
    double area() const override {
        return a * b * sin(torad(alpha));
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(double a, double b) : Parallelogram(a, b, 90) {
        name = "rectangle";
    }
    double area() const override {
        return a * b;
    }
};

class Square : public Parallelogram {
public:
    Square(double a) : Parallelogram(a, a, 90) {
        name = "square";
    }
    double area() const override {
        return a * a;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double a, double alpha) : Parallelogram(a, a, alpha) {
        name = "rhombus";
    }
    double area() const override {
        return a * a * sin(torad(alpha));
    }
};

class Circle : public Figure {
protected:
    double r;
public:
    Circle(double r) : r(r) {
        name = "circle";
    }
    double area() const override {
        return 3.1415926535 * r * r;
    }
};

class Car {
protected:
    string company;
    string model;
public:
    Car(string c, string m) : company(c), model(m) {
        cout << "Создание экземпляра класса Car" << endl;
    }
    Car() : Car("", "") {

    }
    ~Car() {
        cout << "Удаление экземпляра класса Car" << endl;
    }
};

class PassengerCar : virtual public Car {
public:
    PassengerCar() {
        cout << "Создание экземпляра класса PassengerCar" << endl;
    }
    ~PassengerCar() {
        cout << "Удаление экземпляра класса PassengerCar" << endl;
    }
};

class Bus : virtual public Car {
public:
    Bus() {
        cout << "Создание экземпляра класса Bus" << endl;
    }
    ~Bus() {
        cout << "Удаление экземпляра класса Bus" << endl;
    }
};

class Minivan : public Bus, public PassengerCar {
public:
    Minivan() {
        cout << "Создание экземпляра класса Minivan" << endl;
    }
    ~Minivan() {
        cout << "Удаление экземпляра класса Minivan" << endl;
    }
};

class Fraction {
protected:
    int chisl;
    int znam;
public:
    int getChisl() const {
        return chisl;
    }
    int getZnam() const {
        return znam;
    }
    void norm() {
        for (int k = 2; k <= chisl && k <= znam; ++k) {
            while (chisl % k == 0 && znam % k == 0) {
                chisl /= k;
                znam /= k;
            }
        }
    }
    Fraction(int c = 0, int z = 1) : chisl(c), znam(z) {
        if (znam == 0) {
            cout << "Ошибка! Знаменатель не может быть равен нулю" << endl;
            znam = 1;
        }
        norm();
    }
    Fraction operator+(const Fraction& b) const {
        return Fraction(b.chisl * znam + chisl * b.znam, b.znam * znam);
    }
    Fraction operator-(const Fraction& b) const {
        return Fraction(chisl * b.znam - b.chisl * znam, b.znam * znam);
    }
    Fraction operator*(const Fraction& b) const {
        return Fraction(b.chisl * chisl, b.znam * znam);
    }
    Fraction operator/(const Fraction& b) const {
        return Fraction(chisl * b.znam, znam * b.chisl);
    }
    Fraction operator-() const {
        return Fraction(-chisl, znam);
    }
    bool operator>(const Fraction& b) const {
        return (chisl * b.znam) > (b.chisl * znam);
    }
    bool operator<(const Fraction& b) const {
        return (chisl * b.znam) < (b.chisl * znam);
    }
    bool operator>=(const Fraction& b) const {
        return !(*this < b);
    }
    bool operator<=(const Fraction& b) const {
        return !(*this > b);
    }
    bool operator==(const Fraction& b) const {
        return (chisl == b.chisl && znam == b.znam);
    }
    bool operator!=(const Fraction& b) const {
        return !(*this == b);
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");

    // #1
    Parallelogram a(1, 2, 45);
    Rectangle b(1, 2);
    Square c(1);
    Rhombus d(1, 60);
    Circle e(1);

    printArea(a);
    printArea(b);
    printArea(c);
    printArea(d);
    printArea(e);

    cout << endl << endl;

    // #2
    Minivan* m = new Minivan();

    cout << endl << endl;

    // #3
    Fraction f(1, 4);
    Fraction g(2, 5);
    Fraction h = f - g;
    cout << h.getChisl() << '/' << h.getZnam() << endl;
    cout << (f <= g);

    cout << endl << endl;
    return 0;
}
