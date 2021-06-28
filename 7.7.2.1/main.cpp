#include <iostream>
#include <thread>

int main(int argc, char const *argv[])
{
    std::cout << "Cores: " << std::thread::hardware_concurrency() << std::endl;
    return 0;
}
