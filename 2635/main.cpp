#include <iostream>

using namespace std;

int N, maxCnt, maxNum;

void generate(int num, int cur, int next, int cnt, bool print) {
  if (print) cout << cur << " ";
  if (next < 0) {
    if (maxCnt < cnt) {
      maxCnt = cnt;
      maxNum = num;
    }
    return;
  }
  generate(num, next, cur - next, cnt + 1, print);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) generate(i, N, i, 1, false);
  cout << maxCnt << "\n";
  generate(maxNum, N, maxNum, 1, true);
  return 0;
}
