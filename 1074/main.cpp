#include <iostream>

using namespace std;

int pow(int n, int p) {
  if (p == 1) return n;
  return n * pow(n, p - 1);
}

void index(int N, int r, int c, int base) {
  if (N == 1) {
    cout << base + r * 2 + c << "\n";
    return;
  }
  int new_base = pow(4, N - 1);
  int half_length = pow(2, N - 1);
  base += new_base * ((r / half_length) * 2 + (c / half_length));
  if (r >= half_length) r -= half_length;
  if (c >= half_length) c -= half_length;
  index(N - 1, r, c, base);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, r, c;
  cin >> N >> r >> c;
  index(N, r, c, 0);
  return 0;
}
