#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;
    int even = 0, odd = 0;

    do{
        printf("Enter N: ");
        scanf("%d", &N);
    }while(N <= 0);

    int *A = (int*) malloc((N * 2) * sizeof(int));
    int *B = (int*) malloc(N * sizeof(int));
    int *C = (int*) malloc(N * sizeof(int));

    if ((A==NULL) || (B == NULL) || (C == NULL)){
        free(A);
        free(B);
        free(C);
        printf("ERROR\n");
        return 1;
    }

    srand(time(NULL));

    printf("A: ");
    for (int i = 0; i < N * 2; i++) {
        A[i] = rand() % 100 - 50;
        printf("%d ", *(A + i));

        if (i % 2 == 0) {
            B[even] = A[i];
            even++;
        }

        else {
            C[odd] = A[i];
            odd++;
        }
    }

    printf("\nB: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", *(B + i));
    }

    printf("\nC: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", *(C + i));
    }

    free(A);
    free(B);
    free(C);

    return 0;
}