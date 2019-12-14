#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, n, i, escape;
  cin >> T;
  while (T--) {
    cin >> n;
    escape = 0;
    for (i = 1; i * i <= n; i++) {
      escape++;
    }
    cout << escape << "\n";
  }
  return 0;
}
