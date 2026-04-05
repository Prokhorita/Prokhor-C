#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
} Student;

int main() {
    int n;
    scanf("%d", &n);
    Student *s = (Student*)malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        printf("Имя Возраст ");
        scanf("%s %d", s[i].name, &s[i].age);
    }

    for (int i = 0; i < n; i++) {
        printf("%s: %d\n", s[i].name, s[i].age);
    }

    int old = 0;
    for (int i = 1; i < n; i++) {
        if (s[i].age > s[old].age) old = i;
    }
    printf("Oldest: %s\n", s[old].name);

    free(s);
    return 0;
}
