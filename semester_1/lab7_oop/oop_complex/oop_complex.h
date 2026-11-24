#pragma once

#include <cmath>
#include <iosfwd>
#include <iostream>
#include <stdexcept>

class Complex {
    double re = 0;
    double im = 0;

public:
    Complex();
    Complex(const double& re, const double& im = 0.0);
    Complex(const Complex& other);

    Complex& operator=(const Complex& other);

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    Complex operator+() const;
    Complex operator-() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex operator+(const double& scalar) const;
    Complex operator-(const double& scalar) const;
    Complex operator*(const double& scalar) const;
    Complex operator/(const double& scalar) const;

    friend Complex operator+(const double& scalar, const Complex& value);
    friend Complex operator-(const double& scalar, const Complex& value);
    friend Complex operator*(const double& scalar, const Complex& value);
    friend Complex operator/(const double& scalar, const Complex& value);

    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    Complex& operator*=(const Complex& other);
    Complex& operator/=(const Complex& other);

    Complex& operator+=(const double& scalar);
    Complex& operator-=(const double& scalar);
    Complex& operator*=(const double& scalar);
    Complex& operator/=(const double& scalar);

    friend std::istream& operator>>(std::istream& in, Complex& value);
    friend std::ostream& operator<<(std::ostream& out, const Complex& value);

    double Real() const;
    double Imag() const;
    double Abs() const;

    double Real(double re);
    double Imag(double im);
};