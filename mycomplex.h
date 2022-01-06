/*!
   @file
   @brief Заголовочный файл класса Complex
*/
#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>

using namespace std;

/*!
   @brief Класс комплексного числа
*/
class Complex {
    /*!
        @brief Действительная составляющая
    */
    double Re;
    /*!
        @brief Мнимая составляющая
    */
    double Im;
    /*!
        @brief Список членов класса
    */
    public:
        Complex(double aRe = 0, double aIm = 0);
        Complex(const Complex&);
        ~Complex();
        /*!
            @brief Установление мнимой и действительной составляющей
        */
        void Set(double aRe, double aIm = 0);
        operator double();
        /*!
            @brief Модуль комплексного числа
        */
        double abs();
        /*!
            @brief Дружественный класс операции перегрузки ввода >>
        */
        friend istream& operator >> (istream&,Complex&);
        /*!
            @brief Дружественный класс операции перегрузки вsвода <<
        */
        friend ostream& operator << (ostream&, Complex&);
        Complex operator + (const Complex&);
        Complex operator - (const Complex&);
        Complex operator + (const double&);
        /*!
            @brief Дружественный класс операции сложения
        */
        friend Complex operator + (const double&, const Complex&);
        Complex operator - (const double&);
        /*!
            @brief Дружественный класс операции вычитания
        */
        friend Complex operator - (const double&, const Complex&);
        Complex operator * (const Complex&);
        Complex operator * (const double&);
        /*!
            @brief Дружественный класс операции умножения
        */
        friend Complex operator * (const double&, const Complex&);
        Complex operator / (const double&);
        Complex& operator += (const Complex&);
        Complex& operator -= (const Complex&);
        Complex& operator *= (const Complex&);
        Complex& operator += (const double&);
        Complex& operator -= (const double&);
        Complex& operator *= (const double&);
        Complex& operator /= (const double&);
        Complex& operator = (const Complex&);
        Complex& operator = (const double&);
};
#endif
