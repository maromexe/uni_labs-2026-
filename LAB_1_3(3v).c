#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, m, count = 0;
    int sum = 0, max = -1;

    do {
        printf("Enter n, m: \n(n <= 300, m <= 200)\n");
        scanf("%d %d", &n, &m);
    } while ((n > 300 || n <= 0) || (m > 200 || m <= 0));

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

    int freq[51] = {0};

    srand(time(NULL));

    printf("A: ");
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 51;
        printf("%d ", A[i]);

        freq[A[i]] = 1;
    }

    printf("\nB: ");
    for (int i = 0; i < m; i++) {
        B[i] = rand() % 51;
        printf("%d ", B[i]);
    }

    for (int i = 0; i < m; i++) {

        if (freq[B[i]] == 1) {

            C[count] = B[i];
            sum += B[i];

            if (count == 0 || B[i] > max) {
                max = B[i];
            }

            count++;

            freq[B[i]] = 0;
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
        printf("\nSum: %d", sum);
        printf("\nMax: %d", max);
    }

    free(A);
    free(B);
    free(C);

    return 0;
}