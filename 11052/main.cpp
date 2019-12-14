#include <cstdio>

using namespace std;

int main() {
  int i, j, N, tmp;
  int p[1001] = {0};
  int dp[1001] = {0};
  scanf("%d", &N);
  for (i = 1; i <= N; i++) scanf("%d", &p[i]);
  for (i = 1; i <= N; i++) {
    for (j = 1; j <= i; j++) {
      tmp = dp[i - j] + p[j];
      if (dp[i] < tmp) dp[i] = tmp;
    }
  }
  printf("%d", dp[N]);
  return 0;
}
