#include<iostream>
using namespace std;
int main() {
    cout << "Current file: " << __FILE__ << "\n";
    cout << "Current line: " << __LINE__ << "\n";
    return 0;
}

/*
gcc -o output gcc.cpp  error // bởi vì GCC không tự động liên kết thư viện chuẩn trong quá trình biên dịch
gcc -o output gcc.cpp -lstdc++ // thêm thư viện chuẩn vào quá trình biên dịch

GCC được sử dụng để biên dịch C/C++ và các ngôn ngữ khác. 
Với GCC, nếu tệp được lưu với phần mở rộng .c, trình biên dịch sẽ diễn giải tệp đó thành mã C và với .cpp, tệp đó sẽ được diễn giải thành mã C++. 
Ngoài ra, GCC không tự động liên kết thư viện chuẩn trong quá trình biên dịch.


G++ được sử dụng riêng cho việc biên dịch ngôn ngữ C++. Nó xử lý việc liên kết, biên dịch, 
tiền xử lý và lắp ráp mã nguồn để tạo tệp thực thi. 
Đối với cả định dạng tệp .c và .cpp, G++ mặc định xử lý mã như C++. Hơn nữa, thư viện chuẩn được liên kết tự động.

*/