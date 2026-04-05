#include <stdio.h>

int main() {
    FILE *fp = fopen("test.txt", "w");
    if (fp) {
        putc('C', fp);
        putc('o', fp);
        putc('d', fp);
        putc('e', fp);
        fclose(fp);
    }

    fp = fopen("test.txt", "r");
    if (fp) {
        char ch;
        printf("Содержимое файла: ");
        while ((ch = getc(fp)) != EOF) {
            printf("%c", ch);
        }
        printf("\n");
        fclose(fp);
    }
    return 0;
}
