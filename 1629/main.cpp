#include <iostream>

using namespace std;

int pow(int A, int B, int C) {
  if (B == 0) return 1;
  int tmp = pow(A, B / 2, C);
  int result = (1LL * tmp * tmp) % C;
  if (B % 2) result = (1LL * (A % C) * result) % C;
  return result;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int A, B, C;
  cin >> A >> B >> C;
  cout << pow(A, B, C) << "\n";
  return 0;
}
