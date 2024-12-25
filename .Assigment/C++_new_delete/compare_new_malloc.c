#include <stdio.h>
#include <stdlib.h>

int main() {
    // Dùng malloc cấp phát bộ nhớ cho 5 phần tử kiểu int
    int* arr = (int*)malloc(5 * sizeof(int));  // malloc trả về con trỏ kiểu void*

    if (arr == NULL) {  // Kiểm tra xem malloc có cấp phát thành công không
        printf("Memory allocation failed\n");
        return 1;  // Nếu malloc thất bại, thoát chương trình
    }

    // Mảng arr được cấp phát, nhưng không được khởi tạo giá trị, giá trị sẽ là rác
    printf("Mảng arr sau khi cấp phát: \n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);  // Giá trị ở đây là rác (chưa được khởi tạo)
    }

    // Khởi tạo giá trị cho mảng
    for (int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 10;  // Gán giá trị cho các phần tử trong mảng
    }

    printf("\nMảng arr sau khi khởi tạo giá trị: \n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);  // In giá trị đã được khởi tạo
    }

    // Giải phóng bộ nhớ
    free(arr);
    return 0;
}
