#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*завдання 1*/

int main() {

    int n;

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
            A[i][j] = rand() % 11;
            printf("%d  ", A[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < n; i++) {
        int max = A[i][0];
        for (int j = 0; j < n; j++) {
            if (A[i][j] > max) {
                max = A[i][j];
            }
        }
        printf("\n max of %d row - %d", i, max);
    }



    free(A);

    return 0;
}