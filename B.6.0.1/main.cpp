#include <fstream>

int main(){
    unsigned short int num = 42;
    std::fstream f;
    f.open("./number.bin",std::fstream::out | std::fstream::binary);
    f << num;
    f.close();
    return  1;
}