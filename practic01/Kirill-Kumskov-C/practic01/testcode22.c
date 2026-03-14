#include <stdio.h>

int main() {
    float celsius, fahrenheit, kelvin;
    
    printf("Введите температуру в градусах Цельсия: ");
    scanf("%f", &celsius);
    
    fahrenheit = (celsius * 9 / 5) + 32;
    kelvin = celsius + 273.15;
    
    printf("%.2f°C = %.2f°F\n", celsius, fahrenheit);
    printf("%.2f°C = %.2f K\n", celsius, kelvin);
    
    return 0;
}