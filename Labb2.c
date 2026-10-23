#include <stdio.h>

int find_nok(int a, int b, int current) {
    if (current % b == 0) {
        return current;
    }
    return find_nok(a, b, current + a);
}

int main() {
    int N, M;
    
    printf("Введите натуральное число N: ");
    scanf("%i", &N);
    while (N <= 0) {
        printf("Ошибка. Введите N снова: ");
        scanf("%i", &N);
    }

    printf("Введите натуральное число M: ");
    scanf("%i", &M);
    while (M <= 0) {
        printf("Ошибка. Введите M снова: ");
        scanf("%i", &M);
    }
    
    int answer = find_nok(N, M, N);
    
    printf("НОК для %i и %i = %i\n", N, M, answer);
    
    return 0;
}
