#include <iostream>
using namespace std;

void addTen(int &x) {
    x = x + 10;  // Thay đổi giá trị của x, giá trị của a trong main cũng thay đổi
}

int main() {
    int a = 5;
    addTen(a);  // Truyền a vào hàm dưới dạng tham chiếu
    cout << "a after addTen: " << a << endl;  // a sẽ là 15
    return 0;
}
