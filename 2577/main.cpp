#include <stdio.h>

int cnt[10];
int main() {
  int i, a, b, c, m;
  scanf("%d %d %d", &a, &b, &c);
  m = a * b * c;
  while (m) {
    cnt[m % 10]++;
    m /= 10;
  }
  for (i = 0; i < 10; i++) printf("%d\n", cnt[i]);
  return 0;
}
