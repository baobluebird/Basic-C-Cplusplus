#include <stdio.h>
#include <stdlib.h>

int main() {
    int **arr;  // Mảng con trỏ động, arr là con trỏ đến mảng con trỏ
    int n = 5;

    // Cấp phát bộ nhớ cho mảng con trỏ
    arr = (int**) malloc(n * sizeof(int*));  // Cấp phát bộ nhớ cho 5 con trỏ đến int

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Cấp phát bộ nhớ cho mỗi phần tử trong mảng con trỏ
    for (int i = 0; i < n; i++) {
        arr[i] = (int*) malloc(sizeof(int));  // Cấp phát bộ nhớ cho mỗi phần tử trong mảng
        *(arr[i]) = i;  // Gán giá trị cho mỗi phần tử
    }

    // In giá trị
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, *(arr[i]));
    }

    // Giải phóng bộ nhớ đã cấp phát
    for (int i = 0; i < n; i++) {
        free(arr[i]);  // Giải phóng bộ nhớ cho mỗi con trỏ
    }
    free(arr);  // Giải phóng bộ nhớ cho mảng con trỏ

    return 0;
}
