#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  for (int i = 1; i <= N; i++) {
    if (N % i == 0) {
      K--;
      if (K == 0) {
        cout << i << "\n";
        return 0;
      }
    }
  }
  cout << "0\n";
  return 0;
}
