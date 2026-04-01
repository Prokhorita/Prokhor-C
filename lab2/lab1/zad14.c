#include <stdio.h>
int main() {
    int a, b, c;
    printf("Addresses:\na: %p\nb: %p\nc: %p\n", (void*)&a, (void*)&b, (void*)&c);
    printf("Разница b-a: %ld байт\n", (char*)&b - (char*)&a);
    return 0;
}
