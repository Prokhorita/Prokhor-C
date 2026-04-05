#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) arr[i] = i + 1;

    int pos = 1, val = 99;
    n++;
    arr = (int*)realloc(arr, n * sizeof(int));

    for (int i = n - 1; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    free(arr);
    return 0;
}
