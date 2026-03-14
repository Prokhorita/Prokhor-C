#include <stdio.h>

int main() {
    float a, b, c, result;
    
    printf("Введите три числа (a, b, c): ");
    scanf("%f %f %f", &a, &b, &c);
    
    result = ((a + b) * c) / 2;
    
    printf("((%.2f + %.2f) * %.2f) / 2 = %.2f\n", a, b, c, result);
    
    return 0;
}