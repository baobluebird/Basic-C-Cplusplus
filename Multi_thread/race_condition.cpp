#include <iostream>
#include <thread>

using namespace std;

int shared_counter = 0; 

void increment(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        ++shared_counter; 
    }
}

int main() {
    int iterations = 100000;

    thread t1(increment, iterations);
    thread t2(increment, iterations);

    t1.join();
    t2.join();

    cout << "Final counter value: " << shared_counter << endl;

    return 0;
}
