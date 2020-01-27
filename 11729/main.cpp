#include <iostream>

using namespace std;

int pow(int n, int p) {
  if (p == 1) return n;
  return n * pow(n, p - 1);
}

void hanoi(int N, int from, int to, int by) {
  if (N == 1) {
    cout << from << " " << to << "\n";
    return;
  }
  hanoi(N - 1, from, by, to);
  cout << from << " " << to << "\n";
  hanoi(N - 1, by, to, from);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  cout << pow(2, N) - 1 << "\n";
  hanoi(N, 1, 3, 2);
  return 0;
}
