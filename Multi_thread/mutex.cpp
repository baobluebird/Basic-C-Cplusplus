#include <bits/stdc++.h>

using namespace std;

mutex mtx;

void printf_safe(const string& messages){
    lock_guard<mutex> lock(mtx);
    cout << messages << endl;
}

int main(){
    thread t1(printf_safe, "Thread 1: Hello from thread1");
    thread t2(printf_safe, "Thread 2: Hello from thread2");

    t1.join();
    t2.join();

    return 0;
}