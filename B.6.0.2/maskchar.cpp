#include <iostream>
#include <cstring>

int main(int argc, char const *argv[])
{

    if (argc != 2){
        std::cout << "invalid amount of arguments: "<< argc <<"\n";
        return 1;
    }
    else if (strlen(argv[1])!= 1)
    {
        std::cout << "invalid length: "<< strlen(argv[1]) <<"\n";
        return 2;
    }
    
    char temp = argv[1][0] | 0b00100000;

    if ((97 <= temp)&&(temp <=122)){
        temp = argv[1][0] ^ 0b00100000;
        std::cout << temp << "\n";
    }
    else{
        std::cout << "argument is not a valid character\n";
        return  3;
    }
    
    return 0;
}
