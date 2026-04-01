#include <stdio.h>
#include <string.h>
struct person
{
    char name[100];
    int age;
    float ball;
};
int main(){
    struct person n1;
    printf("введите имя возраст и средний балл: ");
    scanf ("%s",n1.name);
    scanf ("%d", &n1.age);
    scanf ("%2f", &n1.ball);
    printf("name: %s, age: %d, ball: %2f", n1.name, n1.age, n1.ball);
    return 0;
}