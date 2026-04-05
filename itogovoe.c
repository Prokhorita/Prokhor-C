#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define START_SIZE 2

struct Person {
    char name[100];
    int age;
    float height;
    int birth_year;
};

struct Person *db = NULL;
int total = 0;
int capacity = 0;

int check_name(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') continue;
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) continue;
        return 0;
    }
    return 1;
}

int calc_age(int year) {
    time_t now;
    struct tm *tm_info;
    time(&now);
    tm_info = localtime(&now);
    return (tm_info->tm_year + 1900) - year;
}

void add_person() {
    struct Person new_p;
    char buf[200];
    int ok;
    
    if (total >= capacity) {
        if (capacity == 0) capacity = START_SIZE;
        else capacity = capacity * 2;
        db = realloc(db, capacity * sizeof(struct Person));
    }
    
    while (getchar() != '\n');
    
    do {
        printf("Имя: ");
        fgets(buf, 200, stdin);
        buf[strlen(buf)-1] = '\0';
        ok = check_name(buf);
        if (!ok) printf("Только буквы!\n");
    } while (!ok);
    strcpy(new_p.name, buf);
    
    do {
        printf("Возраст: ");
        ok = scanf("%d", &new_p.age);
        while (getchar() != '\n');
        if (!ok || new_p.age <= 0) {
            printf("Возраст должен быть больше 0!\n");
            ok = 0;
        }
    } while (!ok);
    
    do {
        printf("Рост: ");
        ok = scanf("%f", &new_p.height);
        while (getchar() != '\n');
        if (!ok || new_p.height <= 0) {
            printf("Рост должен быть больше 0!\n");
            ok = 0;
        }
    } while (!ok);
    
    do {
        printf("нод рождения: ");
        ok = scanf("%d", &new_p.birth_year);
        while (getchar() != '\n');
        if (!ok || new_p.birth_year < 1900 || new_p.birth_year > 2025) {
            printf("нормальный год (1900-2025)!\n");
            ok = 0;
        }
    } while (!ok);
    
    db[total] = new_p;
    total++;
    printf("Добавлено!!!!\n");
}

void print_all() {
    int i;
    if (total == 0) {
        printf("нет записей\n");
        return;
    }
    for (i = 0; i < total; i++) {
        printf("%s | Возраст: %d | Рост: %.2f | Год рождения: %d\n", 
               db[i].name, db[i].age, db[i].height, db[i].birth_year);
    }
}

void sort_by_name() {
    int i, j;
    struct Person temp;
    
    if (total == 0) {
        printf("Нет записей\n");
        return;
    }
    
    for (i = 0; i < total - 1; i++) {
        for (j = 0; j < total - i - 1; j++) {
            if (strcmp(db[j].name, db[j+1].name) > 0) {
                temp = db[j];
                db[j] = db[j+1];
                db[j+1] = temp;
            }
        }
    }
    printf("отсортировано по имени\n");
}

void sort_by_age() {
    int i, j;
    struct Person temp;
    
    if (total == 0) {
        printf("Нет записей\n");
        return;
    }
    
    for (i = 0; i < total - 1; i++) {
        for (j = 0; j < total - i - 1; j++) {
            if (db[j].age > db[j+1].age) {
                temp = db[j];
                db[j] = db[j+1];
                db[j+1] = temp;
            }
        }
    }
    printf("отсортировано по возрасту\n");
}

void stats() {
    int i;
    float sum_age = 0, max_h = 0;
    
    if (total == 0) {
        printf("Нет записей\n");
        return;
    }
    
    for (i = 0; i < total; i++) {
        sum_age += db[i].age;
        if (db[i].height > max_h) max_h = db[i].height;
    }
    
    printf("средний возраст: %.1f\n", sum_age / total);
    printf("максимальный рост: %.2f\n", max_h);
    printf("реальный возраст: %d\n", calc_age(db[0].birth_year));
}

void search_by_name() {
    char search_name[100];
    int found = 0;
    
    while (getchar() != '\n');
    printf("Введите имя: ");
    fgets(search_name, 100, stdin);
    search_name[strlen(search_name)-1] = '\0';
    
    for (int i = 0; i < total; i++) {
        if (strcmp(search_name, db[i].name) == 0) {
            printf("%s | Возраст: %d | Рост: %.2f | Год рождения: %d\n", 
                   db[i].name, db[i].age, db[i].height, db[i].birth_year);
            found = 1;
        }
    }
    if (!found) printf("Не найдено\n");
}

void search_by_age_range() {
    int min_age, max_age, found = 0;
    
    printf("мин возраст: ");
    scanf("%d", &min_age);
    printf("Макс ворзарст: ");
    scanf("%d", &max_age);
    
    for (int i = 0; i < total; i++) {
        if (db[i].age >= min_age && db[i].age <= max_age) {
            printf("%s | Возраст: %d | Рост: %.2f | Год рождения: %d\n", 
                   db[i].name, db[i].age, db[i].height, db[i].birth_year);
            found = 1;
        }
    }
    if (!found) printf("никого нет\n");
}

void save_binary() {
    FILE *f = fopen("people.dat", "wb");
    if (f == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }
    fwrite(&total, sizeof(int), 1, f);
    fwrite(db, sizeof(struct Person), total, f);
    fclose(f);
    printf("Сохранено %d записей\n", total);
}

void load_binary() {
    FILE *f = fopen("people.dat", "rb");
    if (f == NULL) {
        return;
    }
    int saved_total;
    fread(&saved_total, sizeof(int), 1, f);
    if (saved_total > capacity) {
        capacity = saved_total;
        db = realloc(db, capacity * sizeof(struct Person));
        if (db == NULL) {
            printf("Память кончилась\n");
            fclose(f);
            return;
        }
    }
    fread(db, sizeof(struct Person), saved_total, f);
    total = saved_total;
    fclose(f);
    printf("Загружено %d записей\n", total);
}

void save_text() {
    FILE *f = fopen("people.txt", "w");
    if (f == NULL) {
        printf("Ошибка открытия файла\n");
        return;
    }
    fprintf(f, "%d\n", total);
    for (int i = 0; i < total; i++) {
        fprintf(f, "%s\n%d\n%.2f\n%d\n", 
                db[i].name, db[i].age, db[i].height, db[i].birth_year);
    }
    fclose(f);
    printf("Сохранено %d записей в people.txt\n", total);
}

void save_menu() {
    int ch;
    printf("1 - Бинарный\n2 - Текстовый\nВыбор: ");
    scanf("%d", &ch);
    if (ch == 1) save_binary();
    else if (ch == 2) save_text();
    else printf("Неверно\n");
}

void exit_prog() {
    printf("Пока!\n");
    free(db);
}

int main() {
    void (*menu[])(void) = {
        add_person,
        print_all,
        sort_by_name,
        sort_by_age,
        stats,
        search_by_name,
        search_by_age_range,
        save_menu,
        load_binary,
        exit_prog
    };
    
    int choice;
    
    while (1) {
        printf("\n=== МЕНЮ ===\n");
        printf("1. Добавить\n");
        printf("2. Показать всех\n");
        printf("3. Сортировка по имени \n");
        printf("4. Сортировка по возрасту \n");
        printf("5. Статистика\n");
        printf("6. Поиск по имени\n");
        printf("7. Поиск по возрасту\n");
        printf("8. Сохранить\n");
        printf("9. Загрузить\n");
        printf("10. Выйти\n");
        printf("Выбор: ");
        
        scanf("%d", &choice);
        
        if (choice >= 1 && choice <= 10) {
            menu[choice - 1]();
            if (choice == 10) break;
        } else {
            printf("Неверный выбор\n");
        }
    }
    return 0;
}