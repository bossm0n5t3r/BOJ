#include <iostream>

using namespace std;

long long save[68];

long long koong(int n) {
  if (!save[n])
    save[n] = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
  return save[n];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, n;
  save[0] = 1;
  save[1] = 1;
  save[2] = 2;
  save[3] = 4;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << koong(n) << "\n";
  }
  return 0;
}
