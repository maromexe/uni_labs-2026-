#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void capital(char *text) {
  char *word = strtok(text, " \t\n");
  while (word != NULL) {
    if (word[0] >= 'A' && word[0] <= 'Z') {
      printf("%s\n", word);
    }
    word = strtok(NULL, " \t\n");
  }
}

int main() {
  int capacity = 10;
  int length = 0;
  char c;

  char *text = (char*)malloc(capacity * sizeof(char));

  printf("Enter: ");

  while ((c = getchar()) != '\n' && c != EOF) {
    text[length] = c;
    length++;

    if (length == capacity) {
      capacity *= 2;
      text = (char*)realloc(text, capacity * sizeof(char));
    }
  }

  text[length] = '\0';

  printf("\nResult:\n");
  capital(text);

  free(text);
  return 0;
}