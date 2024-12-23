#include <iostream>
using namespace std;

void addTen(int x) {
    x = x + 10;  // Thay đổi giá trị của x trong hàm, nhưng không ảnh hưởng đến giá trị của a
}

int main() {
    int a = 5;
    addTen(a);  // Truyền a vào hàm
    cout << "a after addTen: " << a << endl;  // a vẫn là 5
    return 0;
}
