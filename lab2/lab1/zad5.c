#include <stdio.h>
int main() {
    int a = 5;
    printf("Начальное a = %d\n", a);
    printf("a++: %d (сначала вывод, потом +1)\n", a++);
    printf("После a++: %d\n", a);
    printf("++a: %d (сначала +1, потом вывод)\n", ++a);
    printf("a--: %d (сначала вывод, потом -1)\n", a--);
    printf("--a: %d (сначала -1, потом вывод)\n", --a);
    return 0;
}
