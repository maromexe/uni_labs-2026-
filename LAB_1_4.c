#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;

    do {
        printf("Enter n: ");
        if (scanf("%d", &n) != 1) return 1;
    } while (n <= 0);

    float *A = (float*) malloc(n * sizeof(float));
    float *B = (float*) malloc(n * sizeof(float));
    if (!A || !B) return 1;

    srand(time(NULL));
    printf("Original A: ");
    for (int i = 0; i < n; i++) {
        A[i] = (rand() % 51) / 10.0;
        printf("%.1f  ", A[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                float k = A[j];
                A[j] = A[j + 1];
                A[j + 1] = k;
            }
        }
    }

    printf("\nSorted A:   ");
    for (int i = 0; i < n; i++) {
        printf("%.1f  ", A[i]);
    }

    int c = 0, d = 0, e = 0;

    printf("\n\n - Results - \n");
    printf("a) Appearing only once: ");

    int i = 0;
    while (i < n) {
        int size = 1;
        while (i + size < n && A[i] == A[i + size]) {
            size++;
        }

        if (size == 1) {
            printf("%.1f ", A[i]);
        } else {
            B[c] = A[i];
            c++;
            e += size;
        }

        d++;
        i += size;
    }

    printf("\nb) Taken one from each duplicate group (B): ");
    for (int j = 0; j < c; j++) {
        printf("%.1f ", B[j]);
    }

    printf("\nc) Number of groups of identical elements: %d", c);
    printf("\nd) Number of distinct elements: %d", d);
    printf("\ne) Total elements appearing more than once: %d\n", e);

    free(A);
    free(B);

    return 0;
}