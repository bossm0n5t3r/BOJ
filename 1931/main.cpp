#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
  return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, s, e, cnt = 0;
  vector<pair<int, int>> v;
  cin >> N;
  while (N--) {
    cin >> s >> e;
    v.push_back({s, e});
  }
  sort(v.begin(), v.end(), cmp);
  int last = 0;
  for (pair<int, int> p : v) {
    if (last <= p.first) {
      last = p.second;
      cnt++;
    }
  }
  cout << cnt << "\n";
  return 0;
}
