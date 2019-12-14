#include <stdio.h>

int main() {
  int i, N, call, Y = 0, M = 0;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &call);
    Y += ((call / 30) + 1) * 10;
    M += ((call / 60) + 1) * 15;
  }
  if (Y < M)
    printf("Y %d", Y);
  else if (M < Y)
    printf("M %d", M);
  else
    printf("Y M %d", Y);
  return 0;
}
