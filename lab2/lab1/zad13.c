#include <stdio.h>
int main() {
    int total_sec, h, m, s;
    scanf("%d", &total_sec);
    h = (total_sec / 3600) % 24;
    m = (total_sec / 60) % 60;
    s = total_sec % 60;
    printf("%02d:%02d:%02d\n", h, m, s);
    return 0;
}
