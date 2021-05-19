#include "Complex.cpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    Complex<int> c1 {0,1};
    Complex<int> c2 {0,9};
    Complex<int> c3 = {3,0};
    Complex<int> c4 = {5,0};

    try {
        std::cout << c1/c2 << std::endl;
    }
    catch(const std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        std::cout << c1/c4 << std::endl;
    }
    catch(const std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        std::cout << c3/c4 << std::endl;
    }
    catch(const std::invalid_argument& e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
