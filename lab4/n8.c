#include <stdio.h>

typedef struct {
    char name[20];
    int age;
} Person;

int main() {
    Person group[2] = {{"Ivan", 19}, {"Anna", 21}};
    FILE *fp = fopen("group.bin", "wb");
    if (fp) {
        fwrite(group, sizeof(Person), 2, fp);
        fclose(fp);
    }

    Person read_group[2];
    fp = fopen("group.bin", "rb");
    if (fp) {
        fread(read_group, sizeof(Person), 2, fp);
        for (int i = 0; i < 2; i++) {
            printf("%s: %d\n", read_group[i].name, read_group[i].age);
        }
        fclose(fp);
    }
    return 0;
}
