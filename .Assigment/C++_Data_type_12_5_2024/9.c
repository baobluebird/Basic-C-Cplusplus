#include <stdio.h>

int main()
{
    float x = 2.17;
    double y = 2.17;
    long double z = 2.17;

printf("%f\n", x);      // In kiểu float
printf("%f\n", y);      // In kiểu double (có thể dùng %lf thay vì %f, nhưng %f là đủ trong hầu hết trường hợp)
printf("%Lf\n", z);     // In kiểu long double


}