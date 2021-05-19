#include "Complex.cpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    Complex<int> c1 {1,1};
    Complex<int> c2 {9,9};
    Complex<int> c3 = c1+c2;
    Complex<int> c4 = c2-c1;

    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;
    std::cout << c4 << std::endl;
    std::cin >> c4;
    std::cout << c4 << std::endl;
    
    return 0;
}
