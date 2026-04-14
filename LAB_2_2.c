#include <stdio.h>

void heritage(int current_gen, int total_gens, float money) {
  if (current_gen <= total_gens) {
    if (money < 10.0) {
      int left_without = total_gens - current_gen + 1;
      printf("Спадку вистачило тільки до %d-го покоління.\n", current_gen - 1);
      printf("%d поколінь залишились без спадку.\n", left_without);
    }
    else {
      printf("Покоління %d отримає: %.2f$\n", current_gen, money);
      heritage(current_gen + 1, total_gens, money / 2.0);
    }
  }
}

int main() {
  int n;
  float s;

  do {
    printf("Введіть кількість поколінь та суму спадку: ");
    scanf("%d%f", &n, &s);
  } while (n <= 0 || s <= 0);

  printf("\nРозподіл спадку\n");
  heritage(1, n, s);

  return 0;
}