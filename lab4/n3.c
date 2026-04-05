#include <stdio.h>

int main() {
    FILE *fp = fopen("strings.txt", "w");
    if (fp) {
        fputs("Hello World\n", fp);
        fputs("Programming in C\n", fp);
        fclose(fp);
    }

    char buffer[100];
    fp = fopen("strings.txt", "r");
    if (fp) {
        while (fgets(buffer, 100, fp)) {
            printf("Считано: %s", buffer);
        }
        fclose(fp);
    }
    return 0;
}
