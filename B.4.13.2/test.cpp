#include "Punkt.cpp"
#include <iostream>
using namespace std;

int main()
{
    C1DPunkt p1 = C1DPunkt(1);
    C2DPunkt p2 = C2DPunkt(2, 3);
    C3DPunkt p3 = C3DPunkt(4, 5, 6);
    punkt_ausgeben(&p1);
    punkt_ausgeben(&p2);
    punkt_ausgeben(&p3);
    return 0;
}