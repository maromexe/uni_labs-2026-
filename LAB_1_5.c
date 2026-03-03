#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int m, n, S;

    printf("Enter n, m: ");
    scanf("%d%d", &m, &n);

    int **A = (int**) malloc(n * sizeof(int*));
    int **B = (int**) malloc(n * sizeof(int*));
    int **C = (int**) malloc(n * sizeof(int*));

    srand(time(NULL));

    for (int i = 0; i < m; i++) {
        A[i] = (int*) malloc(m * sizeof(int));
        B[i] = (int*) malloc(m * sizeof(int));
        C[i] = (int*) malloc(m * sizeof(int));
    }

    printf("A: \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = rand() % 11;
            printf("%d  ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("B: \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            B[i][j] = rand() % 11;
            printf("%d  ", B[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    printf("C: \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d  ", C[i][j]);
        }
        printf("\n");
    }

    free(A);
    free(B);
    free(C);

    return 0;
}