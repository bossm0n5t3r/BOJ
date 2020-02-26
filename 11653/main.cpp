#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  int sqrtN = 2;
  while (sqrtN * sqrtN <= N) {
    while (N % sqrtN == 0) {
      cout << sqrtN << "\n";
      N /= sqrtN;
    }
    sqrtN++;
  }
  if (N > 1) cout << N << "\n";
  return 0;
}
