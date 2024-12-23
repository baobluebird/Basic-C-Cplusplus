// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// union Data {
//     int *i;           // Con trỏ đến int
//     float *f;         // Con trỏ đến float
//     char *str;        // Con trỏ đến chuỗi ký tự
// };

// int main() {
//     union Data data;

//     // Cấp phát bộ nhớ cho con trỏ int và gán giá trị
//     data.i = (int *)malloc(sizeof(int));
//     if (data.i == NULL) {
//         printf("Memory allocation failed!\n");
//         return 1;
//     }
//     *data.i = 10;
//     printf("data.i: %d\n", *data.i);

//     // Cấp phát bộ nhớ cho con trỏ float và gán giá trị
//     data.f = (float *)malloc(sizeof(float));
//     if (data.f == NULL) {
//         printf("Memory allocation failed!\n");
//         return 1;
//     }
//     *data.f = 3.14f;
//     printf("data.f: %.2f\n", *data.f);

//     // Ghi đè giá trị của con trỏ `i` khi gán giá trị cho con trỏ `str`
//     data.str = (char *)malloc(20 * sizeof(char));
//     if (data.str == NULL) {
//         printf("Memory allocation failed!\n");
//         return 1;
//     }
//     strcpy(data.str, "Hello, Union!");
//     printf("data.str: %s\n", data.str);

//     // Giải phóng bộ nhớ
//     free(data.i);
//     free(data.f);
//     free(data.str);

//     return 0;
// }

#include <stdio.h>

union Data {
    int *i;
    float *f;
    char *str;
};

int main() {
    union Data data;

    // Gán con trỏ int và lưu trữ giá trị
    int a = 10;
    data.i = &a;
    printf("data.i: %d\n", *data.i);  // Output: 10

    // Gán con trỏ float và lưu trữ giá trị
    float b = 3.14f;
    data.f = &b;
    printf("data.f: %.2f\n", *data.f);  // Output: 3.14

    // Gán con trỏ chuỗi và lưu trữ giá trị
    char *str = "Hello, Union!";
    data.str = str;
    printf("data.str: %s\n", data.str);  // Output: Hello, Union!

    // Lưu ý: Mỗi lần gán lại con trỏ sẽ ghi đè giá trị trước đó

    return 0;
}

