#include <stdio.h>

int main() {
    float num1, num2, result;
    char operation;
    
    printf("Введите первое число: ");
    scanf("%f", &num1);
    
    printf("Введите второе число: ");
    scanf("%f", &num2);
    
    printf("Введите операцию (+, -, *, /): ");
    scanf(" %c", &operation);  // Пробел перед %c нужен для игнорирования предыдущего ввода
    
    switch (operation) {
        case '+':
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            break;
            
        case '-':
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            break;
            
        case '*':
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            break;
            
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                printf("Ошибка: деление на ноль!\n");
            }
            break;
            
        default:
            printf("Ошибка: неизвестная операция '%c'\n", operation);
    }
    
    return 0;
}