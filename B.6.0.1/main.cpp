#include <fstream>

int main(){
    float num = 42;
    std::fstream f;
    f.open("./number.bin", std::ios::binary | std::ios::out);
    f.write(num,sizeof(num));
    f.close();
    return  1;
}