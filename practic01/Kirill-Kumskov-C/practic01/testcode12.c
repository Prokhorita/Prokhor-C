#include <stdio.h>

int main() {
    int a, b, c;

    printf("Введите три числа: ");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c) {
        printf("Максимум: %d\n", a);
    }
    else if (b >= a && b >= c) {
        printf("Максимум: %d\n", b);
    }
    else {
        printf("Максимум: %d\n", c);
    }

    return 0;
}