#include <stdio.h>
#include <string.h>
struct person
{
    char name[100];
    int age;
    float ball;
};
int main(){
    float max=0;
    int abu=0;
    struct person students[5] = {
        {"Иван",19,4.6},
        {"Миша",18,4.0},
        {"Олег",20,4.7},
        {"Прохор",15,2.0},
        {"Саня",20,3.2},
    };
    for (int i = 0; i<5; i++){
        printf("name: %s, age: %d, ball: %.1f \n", students[i].name, students[i].age, students[i].ball);
        if (students[i].ball>max)
        {
            max=students[i].ball;
            abu=i;
        }
    }
    printf("BEST STUDENT name: %s, ball: %.1f \n", students[abu].name, students[abu].ball);

    return 0;
}