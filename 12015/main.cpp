#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, N, A, ans = 0;
  vector<int> vt;
  cin >> N;
  vt.push_back(0);
  for (i = 1; i <= N; i++)
  {
    cin >> A;
    if (vt.back() < A)
    {
      vt.push_back(A);
      ans++;
    }
    else
    {
      vector<int>::iterator it = lower_bound(vt.begin(), vt.end(), A);
      *it = A;
    }
  }
  cout << ans << "\n";
  return 0;
}
