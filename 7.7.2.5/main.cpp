#include <iostream>
#include <chrono>
#include <thread>
#include <future>

using namespace std;
using namespace chrono;
// Funktion um eine Fibonacci-Folge zu bererchnen
int fibonacci(int n)
{
    if (n < 3) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void t_func(int i){
    time_point<system_clock> start, end;
    start = system_clock::now();
    int result = fibonacci(i);
    end = system_clock::now();
    cout << "thread: "<< result << endl;
    int elapsed_seconds = duration_cast<milliseconds>(end - start).count();
    cout << "thread finished computation, elapsed time:"<< elapsed_seconds << "ms" << endl;
}

int main()
{   
    int amount = 42;
    thread t1 (t_func,amount);

    time_point<system_clock> start, end;
    start = system_clock::now();
    int result = fibonacci(amount);
    end = system_clock::now();
    cout << "main: "<< result << endl;
    int elapsed_seconds = duration_cast<milliseconds>(end - start).count();
    cout << "main finished computation, elapsed time:"<< elapsed_seconds << "ms" << endl;
    t1.join();
    system("pause");
    return 0;
}

/*
Die beiden Threads sind ungefähr gleich schnell.
Die Zeit schwankt jedoch mit jeder Ausführung.
Warscheinlich ist die Zeit abhängig von den anderen
zur Zeit ausgeführten Threads
*/