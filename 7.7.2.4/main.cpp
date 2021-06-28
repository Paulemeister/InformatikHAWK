#include <iostream>
#include <thread>

using namespace std;

void count(){
    for (int i = 1; i<31;i++){
        cout << i << " " << _getpid() << endl;
        _sleep(1000);
    }
}

void printId(){
    cout << _getpid() << endl;
}

int main()
{
    thread t1(count);
    thread t2(printId);

    t1.join();
    t2.join();
    return 0;
}
