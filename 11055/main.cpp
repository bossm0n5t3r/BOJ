#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, j, N, arr[1000], dp[1000], max = 0;
  cin >> N;
  for (i = 0; i < N; i++)
    cin >> arr[i];
  for (i = 0; i < N; i++)
  {
    dp[i] = arr[i];
    for (j = 0; j < i; j++)
    {
      if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
        dp[i] = dp[j] + arr[i];
    }
    if (max < dp[i])
      max = dp[i];
  }
  cout << max << "\n";
  return 0;
}
