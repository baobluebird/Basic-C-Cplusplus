#include <stdio.h>
#define AREA(x, y)((x) * (y))
#define MIN(a, b)((a) < (b) ? (a) : (b))

int main() {
    int x = 2;
    int y = 6;
    int min_val = MIN(x, y);
    printf("Min: %d\n", min_val);
    int area = AREA(x, y);
    printf("Area: %d\n", area);
    return 0;
}
