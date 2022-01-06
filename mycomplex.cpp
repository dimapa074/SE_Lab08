/*!
   @file
   @brief Файл с описанием методов класса Complex
*/
#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

/*!
   @brief Коструктор класса
   @param aRe Действительная часть
   @param aIm Мнимая часть
*/
Complex::Complex(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}
/*!
   @brief Конструктор класса
   @param aRval комплексное число
*/
Complex::Complex(const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
}
/*!
   @brief Деструктор класса
*/
Complex::~Complex() {
    Re = 0.0;
    Im = 0.0;
}
/*!
   @brief Установление мнимой и действительной частей
*/
void Complex::Set(double aRe, double aIm) {
    Re = aRe;
    Im = aIm;
}
/*!
   @brief Возвращает модуль комплексного числа
   @return Модуль комплексного числа
*/
Complex::operator double() {
    return abs();
}
/*!
   @brief Возвращает модуль выражения комплексного числа
   @return Модуль выражения комплексного числа
*/
double Complex::abs() {
    return sqrt(Re * Re + Im * Im);
}
/*!
   @brief Возвращает результат сложения комплексного числа
   @return Результат сложения комплексного числа
*/
Complex Complex::operator + (const Complex& aRval ) {
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im ;
    return Result;
}
/*!
   @brief Возвращает результат вычитания комплексного числа
   @return Результат Вычитания комплексного числа
*/
Complex Complex::operator - (const Complex& aRval) {
    Complex Result;
    Result.Re = Re - aRval.Re;
    Result.Im = Im - aRval.Im;
    return Result;
}
/*!
   @brief Возвращает результат сложения действительного числа
   @return Результат сложения действительного числа
*/
Complex Complex::operator + (const double& aval) {
    Complex result;
    result.Re = Re + aval;
    result.Im = Im;
    return result;
}
/*!
   @brief Возвращает результат вычитания действительного числа
   @return Результат вычитания действительного числа
*/
Complex Complex::operator - (const double& aRval) {
    Complex Result(*this);
    Result.Re = Re - aRval;
    return Result;
}
/*!
   @brief Возвращает результат умножения комплексного числа
   @return Результат умножения комплексного числа
*/
Complex Complex::operator * (const Complex& aRval) {
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;
}
/*!
   @brief Возвращает результат умножения действительного числа
   @return Результат умножения действительного числа
*/
Complex Complex::operator * (const double& aRval) {
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;
}
/*!
   @brief Возвращает результат деления действительного числа
   @return Результат деления действительного числа
*/
Complex Complex::operator / (const double& aRval){
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;
}
/*!
   @brief Ссылаемся на результат сложения комплексного числа
   @return Возврат по значению сложения
*/
Complex& Complex::operator += (const Complex& arval) {
    Re += arval.Re;
    Im += arval.Im;
    return *this;
}
/*!
   @brief Ссылаемся на результат вычитания комплексного числа
   @return Возврат по значению вычитания
*/
Complex& Complex::operator -= (const Complex& aRval) {
    Re -= aRval.Re;
    Im -= aRval.Im;
    return *this;
}
/*!
   @brief Ссылаемся на результат умножения комплексного числа
   @return Возврат по значению умножения
*/
Complex& Complex::operator *= (const Complex& aRval) {
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return *this;
}
/*!
   @brief Ссылаемся на результат сложения действительного числа
   @return Возврат по значению сложения
*/
Complex& Complex::operator += (const double& aRval) {
    Re += aRval;
    return *this;
}
/*!
   @brief Ссылаемся на результат вычитания действительного числа
   @return Возврат по значению вычитания
*/
Complex& Complex::operator -= (const double& aRval) {
    Re -= aRval;
    return *this;
}
/*!
   @brief Ссылаемся на результат умножения действительного числа
   @return Возврат по значению умножения
*/
Complex& Complex::operator *= (const  double&  aRval) {
    Re *= aRval;
    Im *= aRval;
    return *this;
}
/*!
   @brief Ссылаемся на результат деления действительного числа
   @return Возврат по значению деления
*/
Complex& Complex::operator /= (const double& aRval) {
    Re /= aRval;
    Im /= aRval;
    return *this;
}
/*!
   @brief Ссылаемся на результат равенства комплексного числа
   @return Возврат по значению равенства
*/
Complex& Complex::operator = (const Complex& aRval) {
    Re = aRval.Re;
    Im = aRval.Im;
    return *this;
}
/*!
   @brief Ссылаемся на результат равенства действительного числа
   @return Возврат по значению равенства
*/
Complex& Complex::operator = (const double& aRval) {
    Re = aRval;
    Im = 0.0;
    return *this;
}
/*!
   @brief Извлекаем действительную и мнимую составляющие
   @return Извлечение
*/
istream& operator >> (istream& stream, Complex& a) {
    char tmp[256];
    stream >> a.Re >> a.Im >> tmp;
    return stream;
}
/*!
   @brief Вставляем действительную и мнимую составляющие
   @return Вставка
*/
ostream& operator << (ostream& stream, Complex& a) {
    stream << a.Re;
    if ( !(a.Im < 0) ) stream << '+';
    stream << a.Im << 'i';
    return stream;
}
/*!
   @brief Возвращает результат сложения действительного и комплексного чисел
   @param aLval Действительно число
   @return Результат сложения
*/
Complex operator + (const double& aLval, const Complex& aRval) {
    Complex Result;
    Result.Re = aLval + aRval.Re;
    Result.Im = aRval.Im;
    return Result;
}
/*!
   @brief Возвращает результат вычитания действительного и комплексного чисел
   @return Результат вычитания
*/
Complex operator - (const double& aLval, const Complex& aRval){
    Complex Result;
    Result.Re = aLval - aRval.Re;
    Result.Im = - aRval.Im;
    return Result;
}
/*!
   @brief Возвращает результат умножения действительного и комплексного чисел
   @return Результат умножения
*/
Complex operator * (const double& aLval, const Complex& a) {
    Complex r;
    r.Re = aLval * a.Re;
    r.Im = aLval * a.Im;
    return r;
}
