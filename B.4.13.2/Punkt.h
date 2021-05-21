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
    C1DPunkt(int xi);
    int get_x() const;
    void set_x(int xi);
    string toString();
};

class C2DPunkt : public C1DPunkt
{
private:
    int y;

public:
    C2DPunkt(int xi, int yi);
    int get_y() const;
    void set_y(int yi);
    string toString();
};

class C3DPunkt : public C2DPunkt
{
private:
    int z;

public:
    C3DPunkt(int xi, int yi,int zi);
    int get_z() const;
    void set_z(int zi);
    string toString();
};

void punkt_ausgeben  (Punkt *p);


