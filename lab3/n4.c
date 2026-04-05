#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));

    scanf("%d", &m);
    arr = (int*)realloc(arr, m * sizeof(int));

    for (int i = n; i < m; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < m; i++) {
        printf("%d ", arr[i]);
    }

    int k;
    scanf("%d", &k);
    arr = (int*)realloc(arr, k * sizeof(int));

    free(arr);
    return 0;
}
