#include <stdio.h>
#include <stdlib.h>

struct Student {
  char name[50];
  int group;
  int points[5];
  int n_a;
};

int main() {
  struct Student *s;
  struct Student temp;
  int n, i, j, k;

  printf("Введіть кількість студентів: ");
  scanf("%d", &n);

  s = (struct Student*)malloc(n * sizeof(struct Student));

  for(i = 0; i < n; i++) {
    printf("\nСтудент %d\n", i + 1);

    getchar();

    printf("Прізвище та ініціали: ");
    fgets(s[i].name, 50, stdin);

    for(k = 0; s[i].name[k] != '\0'; k++) {
      if(s[i].name[k] == '\n') {
        s[i].name[k] = '\0';
        break;
      }
    }

    printf("Номер групи: ");
    scanf("%d", &s[i].group);

    s[i].n_a = 0;

    printf("Атестація з 5 предметів: ");
    for(j = 0; j < 5; j++) {
      scanf("%d", &s[i].points[j]);
      if(s[i].points[j] == 0) {
        s[i].n_a++;
      }
    }
  }

  for(i = 0; i < n - 1; i++) {
    for(j = 0; j < n - i - 1; j++) {
      if(s[j].n_a > s[j+1].n_a) {
        temp = s[j];
        s[j] = s[j+1];
        s[j+1] = temp;
      }
    }
  }

  printf("\nСПИСОК СТУДЕНТІВ (за кількістю неатестацій)\n");
  for(i = 0; i < n; i++) {
    printf("ПІБ: %s \tГрупа: %d \tНеатестовано: %d\n",
           s[i].name, s[i].group, s[i].n_a);
  }

  free(s);

  return 0;
}