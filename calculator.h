#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <math.h>

// Класс Калькулятор
class Calculator
{
    double value; // значение

public:
    // Исключения
    enum ERRORS {
     divZero, negativeNumber
    };

    Calculator();
    Calculator(double value1); // к. с параметром

    void setValue(double value1); // задать значение
    double getValue() const; // получить значение

    void operator +=(double value1); // Оператор сложения
    void operator -=(double value1); // Оператор вычитания
    void operator *=(double value1); // Оператор умножения
    void operator /=(double value1); // Оператор деления
    double exprValue(); // exp
    double sqrtValue(); // sqrt
    double lnValue(); // ln
    double sinValue(); // sin
    double cosValue(); // cos
    double tgValue(); // tg
    double powValue(double power); // Возведение в степень
    double sqrValue(); // Возведение в квадрат
};

#endif // CALCULATOR_H
