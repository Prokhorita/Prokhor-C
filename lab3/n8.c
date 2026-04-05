#include <stdio.h>
#include <stdlib.h>

int *list = NULL;
int size = 0;

void quit() {
    free(list);
    printf("Программа завершена.\n");
    exit(0);
}

void add() {
    int value;
    printf("Введите число: ");
    scanf("%d", &value);
    int *temp = (int*)realloc(list, (size + 1) * sizeof(int));
    if (temp) {
        list = temp;
        list[size++] = value;
        printf("Элемент %d добавлен.\n", value);
    }
}

void del() {
    if (size > 0) {
        size--;
        if (size == 0) {
            free(list);
            list = NULL;
        } else {
            list = (int*)realloc(list, size * sizeof(int));
        }
        printf("Элемент удален.\n");
    } else {
        printf("Ошибка: список пуст.\n");
    }
}

void show() {
    if (size == 0) {
        printf("Список пуст.\n");
        return;
    }
    printf("Текущий список: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    void (*menu[])() = {quit, add, del, show, show};
    int choice;

    while (1) {
        printf("\n[0] Выход\n[1] Добавить\n[2] Удалить\n[3] Вывести\nВыбор: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        if (choice >= 0 && choice <= 3) {
            menu[choice]();
        }
    }
    return 0;
}
