#include <stdio.h>

int main() {
    int x;

    printf("Введите x: ");
    scanf("%d", &x);

    if (x > 0) {
        printf("%d\n", x * x);
    }
    else if (x == 0) {
        printf("0\n");
    }
    else {
        printf("%d\n", -x);
    }

    return 0;
}