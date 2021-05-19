#include "Complex.h"
#include <iostream>
#include <string>

template<class C> Complex<C>:: Complex(C a,C b) :Re{a},Im{b} {}

template<class C> C Complex<C>::getRe() const {return Re;}

template<class C> void Complex<C>::setRe(C a){Re = a;}

template<class C> C Complex<C>::getIm() const {return Im;}

template<class C> void Complex<C>::setIm(C b){Im = b;}

template<class C> Complex<C> Complex<C>::operator+ (const Complex<C>& C1) const {
    Complex<C> c {Re+C1.getRe(),Im+C1.getIm()};
    return c;
}

template<class C> Complex<C> Complex<C>::operator- (const Complex<C>& C1) const {
    Complex<C> c {Re-C1.getRe(),Im-C1.getIm()};
    return c;
}

template<class C> Complex<C> Complex<C>::operator/ (const Complex<C>& C1) const {
    bool t1 = (Im==0 && C1.getIm()==0) || (Re==0 && C1.getRe()==0);
    if ((Im==0 && C1.getIm()==0) || (Re==0 && C1.getRe()==0)){
        throw std::invalid_argument("Can't divide by 0");
    }
    
    C a = (Re * C1.getRe() + Im * C1.getIm()) / (C1.getRe() * C1.getRe() + C1.getIm() * C1.getIm());
    C b = (Im * C1.getRe() - Re * C1.getIm()) / (C1.getRe() * C1.getRe() + C1.getIm() * C1.getIm());

    Complex<C> c {Re,Im};
    
    return c;
}

template <class C> std::ostream& operator<< (std::ostream& s, const Complex<C>& c1){
    s << c1.getRe() << " + " << c1.getIm() << "*i";
    return s;
}

template <class C> std::istream& operator>> (std::istream& s, Complex<C>& c1){
    C temp;
    std::cout << "Re: ";
    s >> temp;
    c1.setRe(temp);
    std::cout << "Im: ";
    s >> temp;
    c1.setIm(temp);
    return s;
}