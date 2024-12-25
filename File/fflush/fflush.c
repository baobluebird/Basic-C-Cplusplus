#include <stdio.h>

int main()
{
    FILE *fp = fopen("output.txt", "w");
    fprintf(fp, "This is a test.");
    fflush(fp); // Đảm bảo dữ liệu được ghi vào file ngay lập tức
    fclose(fp);

    return 0;
}
