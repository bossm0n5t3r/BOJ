#include <cstdio>

using namespace std;

int main() {
  int i, j, T, N, coin[21], M;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    for (i = 1; i <= N; i++) scanf("%d", &coin[i]);
    scanf("%d", &M);
    int dp[10001] = {1};
    for (i = 1; i <= N; i++) {
      for (j = coin[i]; j <= M; j++) {
        dp[j] += dp[j - coin[i]];
      }
    }
    printf("%d\n", dp[M]);
  }
  return 0;
}
