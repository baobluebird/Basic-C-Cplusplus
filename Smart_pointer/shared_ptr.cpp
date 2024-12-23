#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(200);
    std::shared_ptr<int> sharedPtr2 = sharedPtr1; 
    std::cout <<sharedPtr2.use_count()<<std::endl;
    std::cout << "Value: " << *sharedPtr1 << std::endl;
    std::cout << "Value: " << *sharedPtr2 << std::endl;
    *sharedPtr1 = 100;
    std::cout << "Value: " << *sharedPtr1 << std::endl;
    std::cout << "Value: " << *sharedPtr2 << std::endl;
    std::cout << "Number of reference counting : " << sharedPtr2.use_count() << std::endl;
    std::cout << "Number of reference counting : " << sharedPtr1.use_count() << std::endl;
    return 0;
}
