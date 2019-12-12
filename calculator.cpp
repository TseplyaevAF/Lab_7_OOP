#include "calculator.h"

Calculator::Calculator()
{
    value = 0;
}

Calculator::Calculator(double value1) {
    value = value1;
}

void Calculator::setValue(double value1) {
    value = value1;
}

double Calculator::getValue() const {
    return value;
}

void Calculator::operator +=(double value1) {
    setValue(value + value1);
}

void Calculator::operator -=(double value1) {
    setValue(value - value1);
}

void Calculator::operator *=(double value1) {
    setValue(value * value1);
}

void Calculator::operator /=(double value1) {
    if (value1 == 0.0) throw divZero;
    setValue(value / value1);
}

double Calculator::exprValue() {
    return exp(value);
}

double Calculator::sqrtValue() {
    if (value < 0) throw negativeNumber;
    return sqrt(value);
}

double Calculator::lnValue() {
    if (value <= 0) throw negativeNumber;
    return log(value);
}

double Calculator::sinValue() {
    return sin(value * M_PI/180); // вернуть значение в градусах
}

double Calculator::cosValue() {
    value = value * M_PI/180;
    return cos(value); // вернуть значение в градусах
}

double Calculator::tgValue() {
    return tan(value * M_PI/180); // вернуть значение в градусах
}

double Calculator::powValue(double power) {
    return pow(value, power);
}

double Calculator::sqrValue() {
    return value *= value;
}
