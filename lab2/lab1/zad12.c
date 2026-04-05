#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    printf("Сотни: %d, Десятки: %d, Единицы: %d\n", n/100, (n/10)%10, n%10);
    return 0;
}
