#include <stdio.h>
#include <string.h>
struct person
{
    char name[100];
    int age;
    float ball;
};
void printlist(struct person students[],int cou)
{
    for (int i = 0; i < cou - 1; i++) {
        for (int j = 0; j < cou - i - 1; j++) {
            if (students[j].ball < students[j + 1].ball) {
            struct person temp = students[j];
            students[j] = students[j + 1];
            students[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < cou; i++)
    {
        printf("name: %s, age: %d, ball: %.2f \n", 
        students[i].name, students[i].age, students[i].ball);
    }
}

void findname(struct person students[],int cou)
{
    char nam[100];
    scanf("%s", &nam);
    for (int i = 0; i<cou; i++)
    {
        if (strcmp(nam, students[i].name) == 0)
        {
            printf("name: %s, age: %d, ball: %.2f \n", students[i].name, students[i].age, students[i].ball);
            
        }

    }


}
void add_person(struct person students[], int index) {
    printf("Введите имя, возраст и средний балл:\n");
    scanf("%s", students[index].name);
    scanf("%d", &students[index].age);
    scanf("%f", &students[index].ball);
}

int main(){
    int choose = 0;
    int count = 5;
    struct person students[20] = {
    {"Иван",19,4.6},
    {"Миша",18,4.0},
    {"Олег",20,4.7},
    {"Прохор",10,2.0},
    {"Саня",20,3.2},
    };
    while (choose==0 | choose==1 | choose==2 | choose==3)
    {
    
        printf("\nВведите цифру: \n1 - Добавить студента \n2 - Вывести список студентов \n3 - Найти по имени   ");
        scanf("%d",&choose);
        
        if (choose==1)
        {
            add_person(students,count);
            count+=1;
            choose=0;
        }
        if (choose==2)
        {
            printlist(students,count);
            choose=0;
        }
        if (choose==3)
        {
            findname(students,count);
            choose=0;
        }
    }


    return 0;
}