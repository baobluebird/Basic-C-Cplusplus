#include <stdio.h>
int main(void)
{
    char c[] = "ICRBCSIT17";  // Một mảng ký tự với chuỗi "ICRBCSIT17".
    char *p = c;              // Con trỏ `p` trỏ đến mảng `c`.
    printf("%s", c + 2[p] - 6[p] - 1);  // In ra chuỗi bắt đầu từ vị trí cụ thể.
    return 0;
}
