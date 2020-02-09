#include <iostream>

using namespace std;

int cnt[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, L, max = 0, cur = 0, totalCnt = -1;
  cin >> N >> M >> L;
  while (true) {
    if (max == 0) cur = 1;
    cnt[cur]++;
    totalCnt++;
    if (max < cnt[cur]) max = cnt[cur];
    if (max == M) break;
    if (cnt[cur] % 2) {
      cur = (cur + L) % N;
      if (cur == 0) cur = N;
    } else {
      cur = (cur - L + N) % N;
      if (cur == 0) cur = N;
    }
  }
  cout << totalCnt << "\n";
  return 0;
}
