#pragma once
#include <exception>

template <class T> class Stack
{
    private:
    struct Knoten
    {
        T value;
        Knoten *pnext;
    };
    Knoten *pstart;
    unsigned int anzahl;
    public:
    Stack();
    unsigned int size();
    const T& peek() const;
    void push(const T &x);
    T pop();
    void clear();
};

class StackError: public std::exception {
    const char * description;
    public:
    StackError(const char * d): description{d}{}
    const char * what() const noexcept{
        return description;
    }
};

