#include <stdio.h>

int main() {
    int score;

    printf("Введите баллы: ");
    scanf("%d", &score);

    if (score >= 90) {
        printf("Отлично\n");
    }
    else if (score >= 75) {
        printf("Хорошо\n");
    }
    else if (score >= 60) {
        printf("Удовлетворительно\n");
    }
    else {
        printf("Неудовлетворительно\n");
    }

    return 0;
}