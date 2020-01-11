#include <memory.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int trace[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, K, pos;
  cin >> N >> K;
  memset(trace, -1, sizeof(trace));
  queue<pair<int, int>> q;
  q.push(make_pair(N, 0));
  while (!q.empty()) {
    int cur = q.front().first;
    int sec = q.front().second;
    if (cur == K) {
      cout << sec << "\n";
      break;
    }
    q.pop();
    if (cur * 2 <= 100000 && trace[cur * 2] == -1) {
      trace[cur * 2] = cur;
      q.push(make_pair(cur * 2, sec + 1));
    }
    if (cur - 1 >= 0 && trace[cur - 1] == -1) {
      trace[cur - 1] = cur;
      q.push(make_pair(cur - 1, sec + 1));
    }
    if (cur + 1 <= 100000 && trace[cur + 1] == -1) {
      trace[cur + 1] = cur;
      q.push(make_pair(cur + 1, sec + 1));
    }
  }
  pos = K;
  vector<int> v;
  v.push_back(pos);
  while (pos != N) {
    v.push_back(trace[pos]);
    pos = trace[pos];
  }
  for (int i = (int)v.size() - 1; i >= 0; i--) {
    cout << v[i] << " ";
  }
  return 0;
}
