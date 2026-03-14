#include <stdio.h>

int main() {
    char c;

    printf("Введите символ: ");
    scanf(" %c", &c);

    if (c >= '0' && c <= '9') {
        printf("Это цифра\n");
    }
    else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        printf("Это буква\n");
    }
    else {
        printf("Другой символ\n");
    }

    return 0;
}