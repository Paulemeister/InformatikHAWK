class Complex
{
private:
    int Re;
    int Im;
public:
    Complex(int a,int b);
    int getRe() const;
    void setRe(int a);
    int getIm() const;
    void setIm(int b);
    Complex operator+(const Complex & C1) const;
    Complex operator-(const Complex & C1) const;
};

