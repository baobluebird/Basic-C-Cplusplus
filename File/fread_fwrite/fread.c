	#include <stdio.h>
	
	int main() {
	    FILE *fp;
	    int buffer[5] = {1, 2, 3, 4, 5};
	    
	    // Ghi dữ liệu vào file
	    fp = fopen("data.bin", "wb");
	    fwrite(buffer, sizeof(int), 5, fp);
	    fclose(fp);
	    
	    // Đọc dữ liệu từ file
	    int readBuffer[5] = {0};
	    fp = fopen("data.bin", "rb");
	    fread(readBuffer, sizeof(int), 5, fp);
	    fclose(fp);
	    
	    // In ra dữ liệu đã đọc
	    for (int i = 0; i < 5; i++) {
	        printf("%d ", readBuffer[i]);
	    }
	    
	    return 0;
	}
