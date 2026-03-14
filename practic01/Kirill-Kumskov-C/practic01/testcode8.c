#include <stdio.h>
int main () {
    int x;
    x = 10;
    printf("Значение x++: %d\n", x++); 
    printf("После x++ переменная стала: %d\n\n", x);
    x = 10;
    printf("Значение ++x: %d\n", ++x);
    printf("После ++x переменная стала: %d\n", x);
    return 0;

    
}