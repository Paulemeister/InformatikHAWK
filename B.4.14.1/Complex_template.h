template <typename C> class Complex
{
private:
    C Re; //Re
    C Im; // Im
public:
    Complex(C a,C b);
    C getRe() const;
    void setRe(C a);
    C getIm() const;
    void setIm(C b);
    Complex<C> operator+(const Complex<C> & C1) const;
    Complex<C> operator-(const Complex<C> & C1) const;
};


