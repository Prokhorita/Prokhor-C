#include <stdio.h>
#include <string.h>
struct Date
{
    int day;
    int month;
    int year;
};

struct person
{
    char name[100];
    struct Date birthdate;
    
};
int main(){
    float max=0;
    int abu=0;
    struct person students[5] = {
        {"Иван",{15, 5, 1999}},
        {"Миша",{18,4, 2012}},
        {"Прохор",{15,2,2022}},
    };
    for (int i = 0; i<5; i++){
        if (students[i].birthdate.year>2000)
        {
            printf(" name: %s, date: %d.%d.%d \n",
            students[i].name,
            students[i].birthdate.day,
            students[i].birthdate.month,
            students[i].birthdate.year
        );
        }
    }


    return 0;
}