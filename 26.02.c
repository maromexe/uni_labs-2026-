#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int m, n, S;

    printf("Enter n, m: ");
    scanf("%d%d", &m, &n);

    int **A = (int**) malloc(n * sizeof(int*));

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        A[i] = (int*) malloc(m * sizeof(int));
    }

    printf("A: \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = rand() % 11;
            printf("%d  ", A[i][j]);
        }

        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        S = 0;
        for (int j = 0; j < n; j++) {
            S += *(*(A+j)+i);
        }
        printf("\nAverage of %d: %.2f", i, (float)S / n);
    }
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }

    free(A);

    return 0;
}