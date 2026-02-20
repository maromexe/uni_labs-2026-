#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, count = 0;

    do{
        printf("Enter n, m: \n(n <= 300, m <= 200)\n");
        scanf("%d %d", &n, &m);
    }while((n > 300 || n <= 0) || (m > 200 || m <= 0));

    int *A = (int*) malloc(n * sizeof(int));
    int *B = (int*) malloc(m * sizeof(int));
    int *C = (int*) malloc(((n < m) ? n : m) * sizeof(int));

    if (!A || !B || !C) {
        free(A);
        free(B);
        free(C);
        printf("ERROR\n");
        return 1;
    }

    srand(time(NULL));

    printf("A: ");
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 11;
        printf("%d ", A[i]);
    }

    printf("\nB: ");
    for (int i = 0; i < m; i++) {
        B[i] = rand() % 11;
        printf("%d ", B[i]);
    }

    for (int i = 0; i < n; i++) {

        int foundInB = 0;
        int j = 0;

        while (j < m && foundInB == 0) {
            if (A[i] == B[j]) {
                foundInB = 1;
            }
            j++;
        }

        if (foundInB == 1) {

            int alreadyInC = 0;
            int k = 0;

            while (k < count && alreadyInC == 0) {
                if (C[k] == A[i]) {
                    alreadyInC = 1;
                }
                k++;
            }

            if (alreadyInC == 0) {
                C[count] = A[i];
                count++;
            }
        }
    }

    if (!count) {
        printf("\nNo shared elements in A and B");
    }
    else {
        printf("\nC: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", C[i]);
        }
    }

    free(A);
    free(B);
    free(C);

    return 0;
}