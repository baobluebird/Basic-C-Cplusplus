#include <stdio.h>

void modifyArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = arr[i] * 2;  // Thay đổi giá trị trong mảng thông qua con trỏ
    }
}

void test(int *ptr){
    *ptr = *ptr + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    int a = 1;

    int *p = &a;   

    test(p);

    printf("a after test: %d\n", a);  // Kết quả: 2

    modifyArray(arr, size);  // Truyền địa chỉ của mảng vào hàm
    
    // In ra mảng sau khi sửa
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);  // Kết quả: 2 4 6 8 10
    }
    return 0;
}
