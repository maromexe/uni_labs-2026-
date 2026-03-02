#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int n, k = 0, s = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    float sn = sqrt(n);
    printf("%f",sn);

    while ((int)sn != sn){ /*пробдєма тут*/

        n--;
        k++;
        sn = sqrt(n);

        printf("\nSn: %f\nSn: %d", sn, (int)sn);
        printf("\nn: %d", n);
        printf("\nk: %d", k);
    }



    for (int i = 1; i <= sn; i++) {
        s += i * 4;
    }

    printf("\nRes %d", s);

    for (int i = 1; i <= k; i++) {
        printf("\ni: %d", i);
        printf("\nSn: %d", (int)sn);
        printf("\nk: %d", k);
        if (i % (int)sn == 0) {
            s += 3;
            k--;
            printf("\nS=%d",s);
        }

        else if ((k % (int)sn > 0 && (k % (int)sn <= k)) ){
            s += 2;
            k--;
            printf("\nS1=%d",s);
        }

        printf("\n");
    }


    printf("\nRes %d", s);


    return 0;
}