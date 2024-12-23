// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main() {
//     // Cấp phát động cho mảng char
//     char *str = (char*) malloc(20 * sizeof(char));
    
//     if (str == NULL) {
//         printf("Memory allocation failed!\n");
//         return 1;  // Nếu cấp phát bộ nhớ thất bại, thoát chương trình
//     }

//     // Gán giá trị cho chuỗi
//     strcpy(str, "aaaa aaaa aaaa aaaa");
    
//     // In chuỗi ra
//     printf("Chuoi duoc tao ra: %s\n", str);
    
//     // Giải phóng bộ nhớ
//     free(str);
    
//     return 0;
// }

#include <stdio.h>

int main() {
    // Mảng các chuỗi
    char *arr[] = {"Hello", "World", "C Programming"};
    

    // Duyệt qua các ký tự trong chuỗi đầu tiên
    printf("Chuoi 1, ky tu dau tien: %c\n", arr[0][0]);  // In ký tự đầu tiên

    return 0;
}
