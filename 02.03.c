#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int n, k = 0, s = 0;

    scanf("%d", &n);

    float sn = sqrt(n);

    while ((int)sn != sn){
        n--;
        k++;
        sn = sqrt(n);
    }

    for (int i = 1; i < sn + 1; i++) {
        s += i * 4;
    }

    for (int i = 1; i < (k + 1); i++) {
        if ((k % (int)sn == 0)){
            s += 3;
        }
        else {
            s += 2;
        }
    }


    printf("%d", s);


    return 0;
}
