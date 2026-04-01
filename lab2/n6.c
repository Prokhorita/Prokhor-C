#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

struct TaggedData {
    int type; 
    union Data value;
};

int main() {
    union Data data;

    data.i = 10;
    data.f = 220.5f;
    data.c = 'A';

    printf("%d\n", data.i);
    printf("%f\n", data.f);
    printf("%c\n", data.c);

    struct TaggedData td;
    td.type = 1;
    td.value.i = 100;

    if (td.type == 1) {
        printf("%d\n", td.value.i);
    }

    return 0;
}
