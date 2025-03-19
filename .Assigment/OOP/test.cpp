#include <iostream>
#include <map>
#include <string>

int main() {
    // Khởi tạo map với kiểu key là std::string và kiểu value là int
    std::map<std::string, int> myMap;

    // Thêm một số phần tử vào map
    myMap["apple"] = 10;
    myMap["banana"] = 20;
    myMap["cherry"] = 30;

    // Key cần tìm
    std::string key = "banana";

    // Tìm key trong map
    auto it = myMap.find(key);

    if (it != myMap.end()) {
        // Xóa phần tử có key tìm thấy
        myMap.erase(it);
        std::cout << "Key " << key << " and its value have been erased." << std::endl;
    } else {
        std::cout << "Key not found: " << key << std::endl;
    }

    // Hiển thị nội dung của map sau khi xóa
    std::cout << "Remaining elements in map:" << std::endl;
    for (const auto &pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
