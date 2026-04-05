#include <stdio.h>
int main() {
    printf("char: %zu\nint: %zu\nfloat: %zu\ndouble: %zu\n", 
            sizeof(char), sizeof(int), sizeof(float), sizeof(double));
    return 0;
}
