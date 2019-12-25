#include <cstdio>

using namespace std;

int p[3][2];

int main() {
  for (int i = 0; i < 3; i++) scanf("%d %d", &p[i][0], &p[i][1]);
  int s = (p[1][0] - p[0][0]) * (p[2][1] - p[0][1]) -
          (p[1][1] - p[0][1]) * (p[2][0] - p[0][0]);
  if (s > 0)
    printf("1");
  else if (s < 0)
    printf("-1");
  else
    printf("0");
  return 0;
}
