#include <stdio.h>

int main() {
    int a, b, c;

    printf("Введите три числа: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a + b == c) {
        printf("Магическая тройка\n");
    } else {
        printf("Не магическая тройка\n");
    }

    return 0;
}