#include <stdio.h>

float h(int n, float s) {
    if (n == 1) {
        return s;
    }
    return 0.5 * h(n - 1, s);
}

void print_h(int n, float s) {
    for (int i = 1; i <= n; i++) {
        printf("Amount of heritage %d generation will get: %.2f$\n", i, h(i, s));
    }
}

int main() {
    int n;
    float s;

    do {
        printf("Enter a number of generations and amount of heritage: ");
        scanf("%d%f", &n, &s);
    }while (n <= 0 || s <= 0);

    print_h(n, s);

    return 0;
}