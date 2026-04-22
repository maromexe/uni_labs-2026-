#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    ROCK = 1,
    JAZZ,
    CLASSICAL,
    POP
} Genre;

Genre toGenre(char *text) {
    if (text == NULL || strlen(text) == 0) return 0;

    for (int i = 0; text[i]; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] += 32;
    }

    if (strcmp(text, "rock") == 0) return ROCK;
    if (strcmp(text, "jazz") == 0) return JAZZ;
    if (strcmp(text, "classical") == 0) return CLASSICAL;
    if (strcmp(text, "pop") == 0) return POP;

    return 0;
}

char** getArtists(Genre g, int *size) {
    char **artists = NULL;

    switch (g) {
        case ROCK:
            *size = 10;
            artists = malloc(*size * sizeof(char*));
            artists[0] = strdup("Red Hot Chili Peppers");
            artists[1] = strdup("Arctic Monkeys");
            artists[2] = strdup("Radiohead");
            artists[3] = strdup("Foo Fighters");
            artists[4] = strdup("The Black Keys");
            artists[5] = strdup("Nirvana");
            artists[6] = strdup("The Strokes");
            artists[7] = strdup("Muse");
            artists[8] = strdup("Linkin Park");
            artists[9] = strdup("Pink Floyd");
            break;

        case JAZZ:
            *size = 10;
            artists = malloc(*size * sizeof(char*));
            artists[0] = strdup("Miles Davis");
            artists[1] = strdup("John Coltrane");
            artists[2] = strdup("Louis Armstrong");
            artists[3] = strdup("Duke Ellington");
            artists[4] = strdup("Ella Fitzgerald");
            artists[5] = strdup("Herbie Hancock");
            artists[6] = strdup("Charles Mingus");
            artists[7] = strdup("Bill Evans");
            artists[8] = strdup("Chet Baker");
            artists[9] = strdup("Thelonious Monk");
            break;

        case CLASSICAL:
            *size = 8;
            artists = malloc(*size * sizeof(char*));
            artists[0] = strdup("Ludwig van Beethoven");
            artists[1] = strdup("Johann Sebastian Bach");
            artists[2] = strdup("Frédéric Chopin");
            artists[3] = strdup("Wolfgang Amadeus Mozart");
            artists[4] = strdup("Antonio Vivaldi");
            artists[5] = strdup("Edvard Grieg");
            artists[6] = strdup("Claude Debussy");
            artists[7] = strdup("Mykola Lysenko");
            break;

        case POP:
            *size = 8;
            artists = malloc(*size * sizeof(char*));
            artists[0] = strdup("Lana Del Rey");
            artists[1] = strdup("The Weeknd");
            artists[2] = strdup("Billie Eilish");
            artists[3] = strdup("Dua Lipa");
            artists[4] = strdup("Taylor Swift");
            artists[5] = strdup("Ariana Grande");
            artists[6] = strdup("Ed Sheeran");
            artists[7] = strdup("Harry Styles");
            break;

        default:
            *size = 0;
            return NULL;
    }

    return artists;
}

void ran(int *ind, int n, int max) {
  int *used = calloc(max, sizeof(int));

  for (int i = 0; i < n; ) {
    int r = rand() % max;

    if (!used[r]) {
      used[r] = 1;
      ind[i] = r;
      i++;
    }
  }

  free(used);
}

int main() {
    char input[50];
    Genre g = 0;
    char **artists = NULL;
    int size = 0;

    srand(time(NULL));

    do {
        printf("Enter genre (rock, jazz, classical, pop): ");

        if (!fgets(input, sizeof(input), stdin)) {
            printf("Input error.\n");
            return 1;
        }

        input[strcspn(input, "\n")] = 0;

        if (strchr(input, ' ') != NULL) {
            printf("Please enter only ONE genre.\n");
            continue;
        }

        g = toGenre(input);

        if (g == 0) {
            printf("Invalid genre. Try again.\n");
        }

    } while (g == 0);

    artists = getArtists(g, &size);

    if (!artists || size == 0) {
        printf("Memory error.\n");
        return 1;
    }

    int n;
    do {
        printf("How many recommendations? (1-%d): ", size);

        if (scanf("%d", &n) != 1) {
            printf("Input error.\n");
            return 1;
        }

        if (n < 1 || n > size) {
            printf("Invalid number.\n");
        }

    } while (n < 1 || n > size);

    int *ind = malloc(n * sizeof(int));

    ran(ind, n, size);

    printf("\nRecommended artists:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, artists[ind[i]]);
    }

    for (int i = 0; i < size; i++) {
        free(artists[i]);
    }
    free(artists);
    free(ind);

    return 0;
}