#include <iostream>

using namespace std;

int rollCake[1001];
int cnt[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int L, N, from, to;
  int expected_max = 0, expected_max_idx = 0;
  int actual_max_idx = 0;
  cin >> L;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> from >> to;
    int expected = to - from + 1;
    if (expected > expected_max) {
      expected_max = expected;
      expected_max_idx = i;
    }
    for (int x = from; x <= to; x++) {
      if (rollCake[x] == 0) {
        rollCake[x] = i;
        cnt[i]++;
      }
    }
  }
  for (int i = 1; i <= N; i++) {
    if (cnt[i] > cnt[actual_max_idx]) actual_max_idx = i;
  }
  cout << expected_max_idx << "\n";
  cout << actual_max_idx << "\n";
  return 0;
}
