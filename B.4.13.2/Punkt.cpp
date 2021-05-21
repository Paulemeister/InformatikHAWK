#include "Punkt.h"
#include <iostream>
using namespace std;

C1DPunkt::C1DPunkt(int xi) : Punkt(), x{xi} {}

int  C1DPunkt::get_x() const{ return x; }

void  C1DPunkt::set_x(int xi) { x = xi; }

string C1DPunkt::toString()
{
    return "(" + to_string(x) + ")";
}

C2DPunkt::C2DPunkt(int xi, int yi) : C1DPunkt(xi), y{yi} {}

int C2DPunkt::get_y() const { return y; }

void C2DPunkt::set_y(int yi) { y = yi; }

string C2DPunkt::toString()
{
    return "(" + to_string(get_x()) + ", " + to_string(y) + ")";
}

C3DPunkt::C3DPunkt(int xi, int yi, int zi) : C2DPunkt(xi, yi), z{zi} {}

int C3DPunkt::get_z() const { return z; }

void C3DPunkt::set_z(int zi) { z = zi; }

string C3DPunkt::toString()
{
    return "(" + to_string(get_x()) + ", " + to_string(get_y()) + ", " + to_string(z) + ")";
}

void punkt_ausgeben(Punkt *p)
{
    cout << p->toString() << endl;
}
