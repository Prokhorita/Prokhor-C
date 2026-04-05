#include <stdio.h>

typedef struct {
    char name[20];
    int age;
} Person;

int main() {
    Person p;
    FILE *fp = fopen("base.bin", "ab+");
    if (!fp) return 1;

    printf("Введите имя: "); scanf("%s", p.name);
    printf("Введите возраст: "); scanf("%d", &p.age);
    
    fwrite(&p, sizeof(Person), 1, fp);
    rewind(fp); 

    printf("\nСодержимое базы:\n");
    while (fread(&p, sizeof(Person), 1, fp)) {
        printf("Имя: %s, Возраст: %d\n", p.name, p.age);
    }
    fclose(fp);
    return 0;
}
