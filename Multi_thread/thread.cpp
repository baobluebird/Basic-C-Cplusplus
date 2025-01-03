#include <bits/stdc++.h>
#include <thread>
using namespace std;

void print_message() {
    cout << "Hello from thread!" << std::endl;
}

int main() {
    thread t(print_message); 
    t.join(); 
    cout << "Back to main thread!" << std::endl;
    return 0;
}
