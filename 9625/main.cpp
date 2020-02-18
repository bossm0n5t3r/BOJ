#include <iostream>

using namespace std;

int K;
int save[50];

int fibo(int K) {
  if (K <= 1) return save[K];
  if (save[K] == 0) save[K] = fibo(K - 1) + fibo(K - 2);
  return save[K];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> K;
  save[0] = 1;
  save[1] = 0;
  fibo(K + 1);
  cout << save[K] << " " << save[K + 1] << "\n";
  return 0;
}
