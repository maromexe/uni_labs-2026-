#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*завдання 4*/

int main() {

    int n, k = 0;

    do {
        printf("Enter n: ");
        scanf("%d", &n);
    }while (n <= 0);

    int **A = (int**) malloc(n * sizeof(int*));

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        A[i] = (int*) malloc(n * sizeof(int));
    }

    printf("A: \n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 21 - 10;
            printf("%d  ", A[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((A[i][j] % 2 == 0) && (A[i][j] != 0)) {
                k++;
            }
        }
    }

    printf("\nAmount of even elements: %d", k);

    free(A);

    return 0;
}