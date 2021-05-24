#include "Complex.h"
#include <iostream>
#include <string>

Complex:: Complex(float a,float b) :Re{a},Im{b} {}

float Complex::getRe() const {return Re;}

float Complex::getIm() const {return Im;}

void Complex::setRe(float a){Re = a;}

void Complex::setIm(float b){Im = b;}

Complex Complex::operator+ (const Complex& C1) const {
    return Complex (Re+C1.Re,Im+C1.Im);
}

Complex Complex::operator- (const Complex& C1) const {
    return Complex(Re-C1.Re,Im-C1.Im);
}

std::ostream& operator<< (std::ostream& s, const Complex& c1){
    s << c1.getRe() << " + " << c1.getIm() << "*i";
    return s;
}

std::istream& operator>> (std::istream& s, Complex& c1){
    float temp;
    std::cout << "Re: ";
    s >> temp;
    c1.setRe(temp);
    std::cout << "Im: ";
    s >> temp;
    c1.setIm(temp);
    return s;
}