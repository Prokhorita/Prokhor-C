#include <stdio.h>

int main() {
    float a, b;
    
    printf("Введите два числа (a и b): ");
    scanf("%f %f", &a, &b);
    
    if (a > b) {
        printf("%.2f больше чем %.2f\n", a, b);
    } else if (a < b) {
        printf("%.2f меньше чем %.2f\n", a, b);
    } else {
        printf("Числа равны: %.2f = %.2f\n", a, b);
    }
    
    return 0;
}