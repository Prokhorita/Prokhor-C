#include <stdio.h>

int main() {
    char input[100];
    printf("Введите текст: ");
    fgets(input, 100, stdin);

    FILE *fp = fopen("user_input.txt", "w");
    if (fp) {
        fputs(input, fp);
        fclose(fp);
    }

    fp = fopen("user_input.txt", "r");
    if (fp) {
        char ch;
        while ((ch = getc(fp)) != EOF) printf("%c", ch);
        fclose(fp);
    }
    return 0;
}
