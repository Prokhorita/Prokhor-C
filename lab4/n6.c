#include <stdio.h>

int main() {
    int nums[] = {10, 20, 30, 40, 50};
    FILE *fp = fopen("data.bin", "wb");
    if (fp) {
        fwrite(nums, sizeof(int), 5, fp);
        fclose(fp);
    }

    int res[5];
    fp = fopen("data.bin", "rb");
    if (fp) {
        fread(res, sizeof(int), 5, fp);
        for (int i = 0; i < 5; i++) printf("%d ", res[i]);
        printf("\n");
        fclose(fp);
    }
    return 0;
}
