#include <stdio.h>
int main() {
    int x, y;
    printf("Введите два числа: ");
    scanf("%d %d", &x, &y);
    printf("Остаток от деления %d на %d = %d\n", x, y, x % y);
    return 0;
}
