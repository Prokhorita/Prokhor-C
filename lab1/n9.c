#include <stdio.h>
int main() {
    int x;
    printf("Введите x: ");
    scanf("%d", &x);
    printf("x^2 + 2x + 1 = %d\n", x*x + 2*x + 1);
    printf("(x+1)^2 - (x-1)^2 = %d\n", (x+1)*(x+1) - (x-1)*(x-1));
    return 0;
}
