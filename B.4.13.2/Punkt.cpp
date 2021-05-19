

#include <string>
#include <iostream>
using namespace std;

class Punkt
{
public:
    virtual string toString()=0;
};

class C1DPunkt : public Punkt
{
private:
    int x;

public:
    C1DPunkt(int xi) : Punkt(), x{xi} {}
    int const get_x() { return x; }
    void const set_x(int xi) { x = xi; }
    string toString() {
        return "(" + to_string(get_x()) + ")";
    }
};

class C2DPunkt : public C1DPunkt
{
private:
    int y;

public:
    C2DPunkt(int xi, int yi) : C1DPunkt(xi), y{yi} {}
    int const get_y() { return y; }
    void const set_y(int yi) { y = yi; }
    string toString() {
        return "(" + to_string(get_x()) + ", " + to_string(get_y()) + ")";
    }
};

class C3DPunkt : public C2DPunkt
{
private:
    int z;

public:
    C3DPunkt(int xi, int yi,int zi) : C2DPunkt(xi,yi), z{zi} {}
    int  get_z() { return z; }
    void  set_z(int zi) { z = zi; }
    string toString() { 
        return "(" + to_string(get_x()) + ", " + to_string(get_y()) + ", " +to_string(get_z()) + ")";
    }
};

void punkt_ausgeben (Punkt*p){
    cout << p->toString () << endl;
}

int main()
{
    int i =0;
    cout << i++ << (i==0);
    Punkt * p1 = new C1DPunkt(1);
    Punkt * p2 = new C2DPunkt(2,3);
    Punkt * p3 = new C3DPunkt(4,5,6);
    punkt_ausgeben(p1);
    punkt_ausgeben(p2);
    punkt_ausgeben(p3);
    return 0;
}
