#include "Stack.h"
#include <cstdarg>
#include <stdexcept>

template<class T> Stack<T>::Stack():pstart{nullptr},anzahl{0}{}

template<class T> unsigned int Stack<T>::size(){
    return anzahl;
}

template<class T> const T& Stack<T>::peek() const{
    if (anzahl==0){
        throw testClass();
    }
    return pstart->value;
}

template<class T> void Stack<T>::push(const T &x){
    Knoten * ptr = new Knoten {x,pstart};
    if (ptr != nullptr){
        throw std::bad_alloc();
    }
    pstart =  ptr;
    anzahl++;
}

template<class T> T Stack<T>::pop(){
    if (anzahl==0){
        throw std::length_error("stack empty");
    }
    T val = pstart->value;
    Knoten * ptr = pstart->pnext;
    delete pstart;
    pstart = ptr;
    anzahl--;
    return val;
}

template<class T> void Stack<T>::clear(){
    Knoten * ptr;
    while(pstart != nullptr){
        ptr = pstart->pnext;
        delete pstart;
        pstart = ptr;
    }
    anzahl = 0;
}
