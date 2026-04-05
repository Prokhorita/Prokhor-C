#include <stdio.h>

int main() {
    FILE *fp = fopen("seek.txt", "w+");
    if (fp) {
        fputs("ABCDEFGHIJ", fp);
        fseek(fp, 3, SEEK_SET); 
        printf("Символ на позиции 3: %c\n", getc(fp));
        fclose(fp);
    }
    return 0;
}
