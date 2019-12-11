#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, j, N, series[1000], result[1000], max = 0;
  cin >> N;
  for (i = 0; i < N; i++)
    cin >> series[i];
  for (i = 0; i < N; i++)
  {
    result[i] = series[i];
    for (j = 0; j < i; j++)
    {
      if (series[j] < series[i] && result[i] < result[j] + series[i])
        result[i] = result[j] + series[i];
    }
    if (max < result[i])
      max = result[i];
  }
  cout << max << "\n";
  return 0;
}
