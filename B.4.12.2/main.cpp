#include <iostream>
#include <string>
#include "datum.h"
#include "tests.cpp"

using namespace std;

int Datum::monatslaenge[12] {31,28,31,30,31,30,31,31,30,31,30,31};
int Datum::instanzen {0};
bool Datum::plappern {true};

int main()
{
    tests();

    return 0;
}
