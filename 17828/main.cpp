#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, X;
  string ans = "";
  cin >> N >> X;
  if (N > X || 26 * N < X) {
    cout << "!\n";
    return 0;
  }
  while (X > 0) {
    if (N - 1 + 26 >= X) {
      for (int i = 0; i < N - 1; i++) cout << "A";
      char c = 'A' - 1 + X - (N - 1);
      cout << c << ans << "\n";
      break;
    }
    ans += "Z";
    X -= 26;
    N--;
  }
  return 0;
}
