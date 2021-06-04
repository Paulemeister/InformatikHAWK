#include "Stack.h"
#include <iostream>

int main()
{
    Stack<int> s = Stack<int>();

    for (int i=0; i< 10; i++){
        s.push(i);
    }
    std::cout << s.pop() << "\n";
    s.clear();
    try
    {
        s.peek();
    }
    catch(std::exception &e){
        std::cout << e.what() << "\n";
    }
    
    return 0;
}