#include <stdio.h>

int main() {
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL) {
        printf("Ошибка: не удалось открыть файл для записи.\n");
        return 1;
    }
    printf("Файл успешно открыт.\n");
    fclose(fp);
    printf("Файл закрыт.\n");
    return 0;
}
