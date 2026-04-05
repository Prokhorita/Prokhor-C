#include <stdio.h>

typedef struct {
    char name[20];
    int age;
} Person;

int main() {
    Person p = {"Oleg", 22};
    FILE *fp = fopen("person.bin", "wb");
    if (fp) {
        fwrite(&p, sizeof(Person), 1, fp);
        fclose(fp);
    }

    Person read_p;
    fp = fopen("person.bin", "rb");
    if (fp) {
        fread(&read_p, sizeof(Person), 1, fp);
        printf("Имя: %s, Возраст: %d\n", read_p.name, read_p.age);
        fclose(fp);
    }
    return 0;
}
