#include <iostream>
#include <stack>

using namespace std;

typedef pair<int, int> pii;

int arr[1000001];
int lis[1000001];
pii ans[1000001];
stack<int> s;

int _lower_bound(int start, int end, int target)
{
  int mid;
  while (start < end)
  {
    mid = (start + end) / 2;
    if (lis[mid] < target)
      start = mid + 1;
    else
      end = mid;
  }
  return end + 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, N, pLis = 0, pArr = 1, pos;
  cin >> N;
  for (i = 0; i < N; i++)
    cin >> arr[i];
  lis[pLis] = arr[0];
  ans[0].first = 0;
  ans[0].second = arr[0];
  while (pArr < N)
  {
    if (lis[pLis] < arr[pArr])
    {
      lis[++pLis] = arr[pArr];
      ans[pArr].first = pLis;
    }
    else
    {
      pos = _lower_bound(0, pLis, arr[pArr]);
      lis[pos - 1] = arr[pArr];
      ans[pArr].first = pos - 1;
    }
    ans[pArr].second = arr[pArr];
    pArr++;
  }
  cout << pLis + 1 << "\n";
  for (i = N - 1; i >= 0; i--)
  {
    if (ans[i].first == pLis)
    {
      s.push(ans[i].second);
      pLis--;
    }
  }
  while (!s.empty())
  {
    cout << s.top() << " ";
    s.pop();
  }
  return 0;
}
