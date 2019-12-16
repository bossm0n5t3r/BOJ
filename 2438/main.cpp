#include <stdio.h>

int main() {
  int i, j, N;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) printf("*");
    printf("\n");
  }
  return 0;
}
