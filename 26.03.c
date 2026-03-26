/*Рекурсивні функції
 * Вкористовуючи рекурсивні функцї обчислити
 * V(n) = sqrt (n + sqrt((n - 1) + sqrt((n - 2 + ... ))
 * W(n) = sqrt (1 + sqrt(2 + ... + sqrt(n - 1 + sqrt(n)))
 * a(n) = b(n - 1) + 3a(n - 1), a1 = 3
 * b(n) = 2a(n - 1) - 5b(n - 1), b1 = 3
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float V(int n) {
    if (n == 1) return 1;
    return sqrt(n + V(n - 1));
}

float W(int n, int k) {
    if (n == k) return sqrt(n);
    return sqrt(k + W(n, k + 1));

}

int A(int n);
int B(int n);

int main(){
    int a;
    printf("Enter n: ");
    scanf("%d", &a);

    printf("\nRez V(%d) is: %.3f",a, V(a));
    printf("\nRez W(%d) is: %.3f",a, W(a,1));
    printf("\nRez A(%d) is: %d \nRez B(%d) is: %d", a, A(a), a, B(a));
}

int A(int n) {
    if (n == 1) return 1;
    return B(n - 1) + 3 * A(n - 1);
}

int B(int n) {
    if (n == 1) return 3;
    return 2 * A(n - 1) - 5 * B(n - 1);

}
