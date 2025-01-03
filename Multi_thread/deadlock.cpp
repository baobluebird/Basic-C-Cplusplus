#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx1, mtx2;

// void thread1_func() {
//     lock_guard<mutex> lock1(mtx1); 
//     this_thread::sleep_for(chrono::milliseconds(100));

//     lock_guard<mutex> lock2(mtx2); 
//     cout << "Thread 1 executed" << endl;
// }

// void thread2_func() {
//     lock_guard<mutex> lock2(mtx2); 
//     this_thread::sleep_for(chrono::milliseconds(100));

//     lock_guard<mutex> lock1(mtx1); 
//     cout << "Thread 2 executed" << endl;
// }

// void thread1_func() {
//     lock_guard<mutex> lock1(mtx1);
//     this_thread::sleep_for(chrono::milliseconds(100));

//     lock_guard<mutex> lock2(mtx2); 
//     cout << "Thread 1 executed" << endl;
// }

// void thread2_func() {
//     lock_guard<mutex> lock1(mtx1); 
//     this_thread::sleep_for(chrono::milliseconds(100));

//     lock_guard<mutex> lock2(mtx2); 
//     cout << "Thread 2 executed" << endl;
// }

void thread1_func() {
    lock(mtx1, mtx2); 
    lock_guard<mutex> lock1(mtx1, adopt_lock);

    this_thread::sleep_for(chrono::milliseconds(100)); 

    lock_guard<mutex> lock2(mtx2, adopt_lock);
    cout << "Thread 1 executed" << endl;
}

void thread2_func() {
    lock(mtx1, mtx2); 
    lock_guard<mutex> lock2(mtx2, adopt_lock);

    this_thread::sleep_for(chrono::milliseconds(100));

    lock_guard<mutex> lock1(mtx1, adopt_lock);
    cout << "Thread 2 executed" << endl;
}



int main() {
    thread t1(thread1_func);
    thread t2(thread2_func);

    t1.join();
    t2.join();

    return 0;
}
