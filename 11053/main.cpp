#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, j, N, A[1001], dp[1001], max, min;
  max = 0;
  cin >> N;
  for (i = 1; i <= N; i++)
  {
    cin >> A[i];
    dp[i] = 0;
  }
  for (i = 1; i <= N; i++)
  {
    min = 0;
    for (j = 0; j < i; j++)
    {
      if (A[j] < A[i] && min < dp[j])
        min = dp[j];
    }
    dp[i] = min + 1;
    if (max < dp[i])
      max = dp[i];
  }
  cout << max << "\n";
  return 0;
}
