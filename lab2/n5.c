#include <stdio.h>
#include <string.h>
enum Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };

struct Nedela {
    enum Day day;
    int task_id;
};

int main() {
    enum Day today = WEDNESDAY;

    switch (today) {
        case MONDAY:    printf("Monday\n"); break;
        case WEDNESDAY: printf("Wednesday\n"); break;
        case SUNDAY:    printf("Sunday\n"); break;
        default:        printf("Other\n"); break;
    }

    struct Nedela s = {MONDAY, 101};
    return 0;
}
