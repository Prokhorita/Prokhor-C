#include <stdio.h>
int main () {
    int x;
    scanf("/d",x);
    if (x == 0)
        printf("это ноль");
    if (x % 2 == 1)
        printf("Нечетное");
    else if (x % 2 == 0)
        printf("четное");
    return 0;
    
}