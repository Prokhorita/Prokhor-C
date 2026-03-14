#include <stdio.h>

int main() {
    int n;

    printf("Введите число: ");
    scanf("%d", &n);

    if (n % 2 == 0)
        printf("Делится на 2\n");

    if (n % 3 == 0)
        printf("Делится на 3\n");

    if (n % 5 == 0)
        printf("Делится на 5\n");

    return 0;
}