#include <stdio.h>

int main() {
    long long n;

    if (scanf("%lld", &n) != 1) return 0;

    if (n == 0) {
        printf("0\n");
        return 0;
    }
    if (n == 1) {
        printf("4\n");
        return 0;
    }

    long long s = 4;
    long long a = 1;

    for (long long i = 2; i <= n; i++) {
        if (i > (a + 1) * (a + 1)) {
            a++;
        }

        if (i == a * a + 1 || i == a * a + a + 1) {
            s += 3;
        }
        else {
            s += 2;
        }
    }

    printf("%lld\n", s);

    return 0;
}