#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int *arr, int n);      // сортировка пузырьком
void inser(int *arr, int n);       // сортировка вставками
void merge_sort(int *arr, int n);  // сортировка слиянием

void random_filler(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
}

void copy_arr(int *imp, int *out, int n) {
    for (int i = 0; i < n; i++) {
        out[i] = imp[i];
    }
}

int main() {
    int sizes[] = {10, 1000, 10000, 100000};
    int num_size = 4;

    srand(time(NULL));

    printf("-------------------------------------------------------------\n");
    printf("| ArrSize    |  bubble(sec) | insertion(sec) | merge(sec)   |\n");
    printf("-------------------------------------------------------------\n");

    for (int a = 0; a < num_size; a++) {
        int n = sizes[a];
        int *arr = (int *)malloc(n * sizeof(int));
        int *arr_b = (int *)malloc(n * sizeof(int));
        int *arr_i = (int *)malloc(n * sizeof(int));
        int *arr_m = (int *)malloc(n * sizeof(int));

        random_filler(arr, n);
        copy_arr(arr, arr_b, n);
        copy_arr(arr, arr_i, n);
        copy_arr(arr, arr_m, n);

        double t_b = 0.0, t_i = 0.0, t_m = 0.0;
        clock_t start, end;

        // Замер: сортировка пузырьком
        start = clock();
        bubble(arr_b, n);
        end = clock();
        t_b = (double)(end - start) / CLOCKS_PER_SEC;

        // Замер: сортировка вставками
        start = clock();
        inser(arr_i, n);
        end = clock();
        t_i = (double)(end - start) / CLOCKS_PER_SEC;

        // Замер: сортировка слиянием
        start = clock();
        merge_sort(arr_m, n);
        end = clock();
        t_m = (double)(end - start) / CLOCKS_PER_SEC;

        printf("| %-10d | %-12f | %-14f | %-12f |\n", n, t_b, t_i, t_m);

        free(arr);
        free(arr_b);
        free(arr_i);
        free(arr_m);
    }
    printf("-------------------------------------------------------------\n");
    return 0;
}

// Сортировка пузырьком
void bubble(int *arr, int n) {
    for (int i = 1; i <= n - 1; i++) {
        int f = 0;
        for (int j = 0; j <= n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                f = 1;
            }
        }
        if (f == 0) break;
    }
}

// Сортировка вставками
void inser(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Сортировка слиянием
void merge_sort(int *arr, int n) {
    if (n < 2) return;

    int mid = n / 2;
    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((n - mid) * sizeof(int));

    for (int i = 0; i < mid; i++) left[i] = arr[i];
    for (int i = mid; i < n; i++) right[i - mid] = arr[i];

    merge_sort(left, mid);
    merge_sort(right, n - mid);

    int i = 0, j = 0, k = 0;
    while (i < mid && j < n - mid) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < mid) arr[k++] = left[i++];
    while (j < n - mid) arr[k++] = right[j++];

    free(left);
    free(right);
}
