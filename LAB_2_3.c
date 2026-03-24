#include <stdio.h>

double a(int k) {
    if (k == 1) return 10;
    if (k == 2) return 14;

    return a(k - 1) + 3 * a(k - 2);
}

double sum(int n) {
    if (n == 1) {
        return a(1) / 1;
    }

    return sum(n - 1) + a(n) / n;
}

int main() {
    int n;

    do {
        printf("Enter n: ");
        scanf("%d", &n);
    } while (n <= 0);

    double res = sum(n);

    printf("Sum = %.2f\n", res);

    return 0;
}