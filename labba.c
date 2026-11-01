#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int N, M;

    printf("Введите N (строки): ");
    scanf("%d", &N);
    printf("Введите M (столбцы): ");
    scanf("%d", &M);

    float *Matrix = malloc(M * N * sizeof(*Matrix));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("Введите элемент [%d][%d]: ", i, j);
            scanf("%f", &Matrix[i * M + j]);
        }
    }

    printf("\nИсходная матрица:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("| %f |", Matrix[i * M + j]);
        }
        printf("\n");
    }

    float min_neg = 0;
    int min_i = -1;
    int min_j = -1;
    int found_neg = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (Matrix[i * M + j] < 0) {
                if (found_neg == 0 || Matrix[i * M + j] < min_neg) {
                    min_neg = Matrix[i * M + j];
                    min_i = i;
                    min_j = j;
                    found_neg = 1;
                }
            }
        }
    }

    if (found_neg == 0) {
        printf("\nОтрицательных элементов нет.\n");
    } else {
        printf("\nМинимальный отрицательный: %f (строка %d, столбец %d)\n", min_neg, min_i, min_j);

        float S = 0;
        for (int j = 0; j < M; j++) {
            float a = Matrix[min_i * M + j];
            S = S + (sin(a) + cos(3.0 * a));
        }
        printf("Сумма S в строке %d: %f\n", min_i, S);

        if (N >= 3 && M >= 4) {
            int index_a34 = 2 * M + 3;
            float temp = Matrix[min_i * M + min_j];
            Matrix[min_i * M + min_j] = Matrix[index_a34];
            Matrix[index_a34] = temp;

            printf("\nИтоговая матрица:\n");
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    printf("| %f |", Matrix[i * M + j]);
                }
                printf("\n");
            }
        } else {
            printf("\nМатрица слишком мала для замены a34 (нужно N>=3 и M>=4).\n");
        }
    }

    free(Matrix);
    return 0;
}
