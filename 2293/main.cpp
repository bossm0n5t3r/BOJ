#include <iostream>

using namespace std;

int dp[10001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  int coins[101];
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> coins[i];
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j >= coins[i]) dp[j] += dp[j - coins[i]];
    }
  }
  cout << dp[k] << "\n";
  return 0;
}
