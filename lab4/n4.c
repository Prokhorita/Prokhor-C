#include <stdio.h>

int main() {
    FILE *fp = fopen("format.txt", "w");
    if (fp) {
        fprintf(fp, "%d %f %s", 10, 3.14, "Lab");
        fclose(fp);
    }

    int i; float f; char s[20];
    fp = fopen("format.txt", "r");
    if (fp) {
        fscanf(fp, "%d %f %s", &i, &f, s);
        printf("Данные: %d, %.2f, %s\n", i, f, s);
        fclose(fp);
    }
    return 0;
}
