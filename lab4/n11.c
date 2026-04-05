#include <stdio.h>

int main() {
    FILE *fp = fopen("test.txt", "r");
    if (!fp) return 1;

    char ch;
    while (1) {
        ch = getc(fp);
        if (feof(fp)) {
            printf("\nДостигнут конец файла.\n");
            break;
        }
        if (ferror(fp)) {
            printf("\nОшибка чтения!\n");
            break;
        }
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}
