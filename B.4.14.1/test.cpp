//#include "Complex_template.cpp" //Implementation für beliebigen Datentyp (Template)
#include "Complex.cpp" //Implementation nur für int
#include <iostream>
using namespace std;

int main()
{
    // Complex<float> c1 {1,1};
    // Complex<float> c2 {9,9};
    // Complex<float> c3 = c1+c2;
    // Complex<float> c4 = c2-c1;
    Complex c1 {1,1};
    Complex c2 {9,9};
    Complex c3 = c1+c2;
    Complex c4 = c2-c1;

    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;
    cout << c4 << endl;
    cin >> c4;
    cout << c4 << endl;
    
    return 0;
}
