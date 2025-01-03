#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <mutex>

template <typename Func>
class ThreadManager {
private:
    std::vector<std::thread> threads; 
    std::mutex mtx;                  

public:
    ThreadManager() = default;

    template <typename... Args>
    void addThread(Func&& func, Args&&... args) {
        threads.emplace_back(std::forward<Func>(func), std::forward<Args>(args)...);
    }

    void joinAll() {
        for (auto& thread : threads) {
            if (thread.joinable()) {
                thread.join();
            }
        }
    }

    void printStatus() {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Number of threads: " << threads.size() << std::endl;
    }

    ~ThreadManager() {
        joinAll();
    }
};

void exampleTask(int id, int delay) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    std::cout << "Task " << id << " completed after " << delay << " ms" << std::endl;
}

int main() {
    ThreadManager<void(*)(int, int)> manager;

    manager.addThread(exampleTask, 1, 1000);
    manager.addThread(exampleTask, 2, 500);
    manager.addThread(exampleTask, 3, 1500);

    manager.printStatus();

    manager.joinAll();

    std::cout << "All tasks completed!" << std::endl;
    return 0;
}
