#include <stdio.h>

int main() {
    FILE *fp = fopen("n10.c", "r"); 
    if (fp) {
        fseek(fp, 0, SEEK_END);
        long size = ftell(fp);
        printf("Размер файла: %ld байт\n", size);
        fclose(fp);
    }
    return 0;
}
