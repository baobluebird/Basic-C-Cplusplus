#include <stdio.h>

union Data {
    int i;//4
    float f;//4
    char str[20];//20
};

struct MyStruct {
    union Data data;  // 20
    int type;         // 4 
    double d;         // 8 
    //int + double = 12
};

int main() {
    struct MyStruct s1;
    s1.type = 1;
    s1.data.i = 10;  // Gán giá trị cho int

    printf("Type: %d, Data: %d\n", s1.type, s1.data.i);

    s1.type = 2;
    s1.data.f = 3.14;  // Gán giá trị cho float

    printf("Type: %d, Data: %f\n", s1.type, s1.data.f);

    printf("Size of MyStruct: %ld\n", sizeof(s1));
    printf("Size of Data: %ld\n", sizeof(s1.data));
    printf("Size of Union: %ld\n", sizeof(union Data));

    return 0;
}
