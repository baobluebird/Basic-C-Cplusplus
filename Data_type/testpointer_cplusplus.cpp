#include <iostream>
using namespace std;

int main() {
    int arr[4] = {10, 20 ,30, 40};
    int *ptr = arr;

    // printf("Value at ptr = %p\n", ptr);
    // printf("Dia chi phan tu thu 2 trong mang: %p\n", arr + 1);
    // printf("Gia tri phan tu thu 2 trong mang: %d\n", *(arr + 1));

    cout << "Value at ptr = " << ptr << endl;
    cout << "Dia chi phan tu thu 2 trong mang: " << arr + 1 << endl;
    cout << "Gia tri phan tu thu 2 trong mang: " << *(arr + 1) << endl;

    return 0;
}