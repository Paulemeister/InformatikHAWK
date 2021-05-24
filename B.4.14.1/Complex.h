class Complex
{
private:
    float Re;
    float Im;
public:
    Complex(float a,float b);
    float getRe() const;
    void setRe(float a);
    float getIm() const;
    void setIm(float b);
    Complex operator+(const Complex & C1) const;
    Complex operator-(const Complex & C1) const;
};

