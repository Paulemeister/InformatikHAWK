#include "Stack.cpp"
#include <iostream>

int main()
{
    Stack<int> s = Stack<int>();
    try
    {
        s.push(1);
    }
    catch(std::bad_alloc& e){
        std::cout << s.pop() << "\n";
    }
    
    
    
    return 0;
}