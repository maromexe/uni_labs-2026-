#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*завдання 6*/

int main() {

    int n;

    do {
        printf("Enter n: ");
        scanf("%d", &n);
    }while (n <= 1);

    int **A = (int**) malloc(n * sizeof(int*));

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        A[i] = (int*) malloc(n * sizeof(int));
    }

    printf("A: \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 11;
            printf("%d  ", A[i][j]);
        }
        printf("\n");
    }

    int temp;

    for (int i = 0; i < n; i++) {
        temp = A[0][i];
        A[0][i] = A[n-1][i];
        A[n-1][i] = temp;
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d  ", A[i][j]);
        }
        printf("\n");
    }

    free(A);

    return 0;
}