#include <stdio.h>

void capital(FILE *f) {
    char text[100];

    while (fscanf(f, "%99s", text) != EOF) {
        if (text[0] >= 'A' && text[0] <= 'Z') {
            printf("%s\n", text);
        }
    }
}

int main() {
    FILE *f = fopen("../input.txt", "r");

    if (!f) {
        printf("Unable to open file\n");
        return 1;
    }

    capital(f);

    fclose(f);

    return 0;
}