#include <iostream>
#include <string>

using namespace std;

int C[1001][1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string a, b;
  cin >> a;
  cin >> b;
  int m = a.length();
  int n = b.length();
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i - 1] == b[j - 1])
        C[i][j] = C[i - 1][j - 1] + 1;
      else
        C[i][j] = max(C[i][j - 1], C[i - 1][j]);
    }
  }
  cout << C[m][n] << "\n";
  return 0;
}
