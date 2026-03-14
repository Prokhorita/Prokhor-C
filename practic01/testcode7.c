#include <stdio.h>

int main() {
    int a,b;
    printf("enter 2 num: ");
    scanf("%d %d", &a, &b);
    double c = (double) a / b;
    printf("%2f\n",c);
    return 0;
}
