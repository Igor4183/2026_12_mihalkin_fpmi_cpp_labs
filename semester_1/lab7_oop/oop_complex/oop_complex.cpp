#include "oop_complex.h"

Complex::Complex() = default;

Complex::Complex(const double& re, const double& im) : re(re), im(im) {
}

Complex::Complex(const Complex& other) : re(other.re), im(other.im) {
}

Complex& Complex::operator=(const Complex& other) {
    if (this != &other) {
        re = other.re;
        im = other.im;
    }
    return *this;
}

bool Complex::operator==(const Complex& other) const {
    return re == other.re && im == other.im;
}

bool Complex::operator!=(const Complex& other) const {
    return re != other.re || im != other.im;
}

Complex Complex::operator+() const {
    return *this;
}

Complex Complex::operator-() const {
    return Complex(-re, -im);
}

Complex Complex::operator+(const Complex& other) const {
    return Complex(re + other.re, im + other.im);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(re - other.re, im - other.im);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(re * other.re - im * other.im, re * other.im + im * other.re);
}

Complex Complex::operator/(const Complex& other) const {
    const double den = other.re * other.re + other.im * other.im;
    if (den == 0)
        throw std::domain_error("division by zero complex number");

    return Complex((re * other.re + im * other.im) / (other.re * other.re + other.im * other.im),
                   (other.re * im - re * other.im) / (other.re * other.re + other.im * other.im));
}

Complex Complex::operator+(const double& scalar) const {
    return Complex(re + scalar, im);
}

Complex Complex::operator-(const double& scalar) const {
    return Complex(re - scalar, im);
}

Complex Complex::operator*(const double& scalar) const {
    return Complex(re * scalar, im * scalar);
}

Complex Complex::operator/(const double& scalar) const {
    if (scalar == 0)
        throw std::domain_error("division by zero complex number");
    return Complex(re / scalar, im / scalar);
}

Complex operator+(const double& scalar, const Complex& value) {
    return value + scalar;
}

Complex operator-(const double& scalar, const Complex& value) {
    return -value + scalar;
}

Complex operator*(const double& scalar, const Complex& value) {
    return value * scalar;
}

Complex operator/(const double& scalar, const Complex& value) {
    const double den = value.re * value.re + value.im * value.im;
    if (den == 0)
        throw std::domain_error("division by zero complex number");
    return Complex(scalar * value.re / den, -scalar * value.im / den);
}

Complex& Complex::operator+=(const Complex& other) {
    *this = *this + other;
    return *this;
}

Complex& Complex::operator-=(const Complex& other) {
    *this = *this - other;
    return *this;
}

Complex& Complex::operator*=(const Complex& other) {
    *this = *this * other;
    return *this;
}

Complex& Complex::operator/=(const Complex& other) {
    *this = *this / other;
    return *this;
}

Complex& Complex::operator+=(const double& scalar) {
    *this = *this + scalar;
    return *this;
}
Complex& Complex::operator-=(const double& scalar) {
    *this = *this - scalar;
    return *this;
}
Complex& Complex::operator*=(const double& scalar) {
    *this = *this * scalar;
    return *this;
}
Complex& Complex::operator/=(const double& scalar) {
    *this = *this / scalar;
    return *this;
}

std::istream& operator>>(std::istream& in, Complex& value) {
    in >> value.re >> value.im;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Complex& value) {
    out << value.re << (value.im < 0.0 ? '-' : '+') << std::abs(value.im) << 'j';
    return out;
}

double Complex::Real() const {
    return re;
}

double Complex::Imag() const {
    return im;
}

double Complex::Abs() const {
    return std::sqrt(re * re + im * im);
}

double Complex::Real(double re){  
    this->re = re;
    return this->re;
}

double Complex::Imag(double im){
    this->im = im;
    return this->im;
}