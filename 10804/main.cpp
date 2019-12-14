#include <stdio.h>

int main() {
  int i, j, a, b, num[21], sum, tmp;
  for (i = 1; i <= 20; i++) num[i] = i;
  for (i = 1; i <= 10; i++) {
    scanf("%d %d", &a, &b);
    sum = a + b;
    for (j = a; j <= sum / 2; j++) {
      tmp = num[j];
      num[j] = num[sum - j];
      num[sum - j] = tmp;
    }
  }
  for (i = 1; i <= 20; i++) printf("%d ", num[i]);
  return 0;
}
