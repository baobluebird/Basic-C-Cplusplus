#include <stdio.h>

void main()
{
    FILE *fp = fopen("example.txt", "r+");
    fseek(fp, 0, SEEK_END); // Di chuyển tới byte thứ 5
    
    //overwrite
    fwrite("123", 3, 1, fp); // Ghi đè lên 3 byte từ vị trí thứ 5
    //append
    fwrite("New Data", 8, 1, fp);  // Luôn ghi thêm vào cuối file
    long pos = ftell(fp);
    printf("Current position: %ld\n", pos);
    fclose(fp);
}