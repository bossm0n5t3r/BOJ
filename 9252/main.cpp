#include <iostream>
#include <string>

using namespace std;

string a, b;
int C[1001][1001];

void LCSLength(int m, int n) {
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i - 1] == b[j - 1])
        C[i][j] = C[i - 1][j - 1] + 1;
      else
        C[i][j] = max(C[i - 1][j], C[i][j - 1]);
    }
  }
}

string backtrack(int i, int j) {
  if (i == 0 || j == 0) return "";
  if (a[i - 1] == b[j - 1]) return backtrack(i - 1, j - 1) + a[i - 1];
  if (C[i][j - 1] > C[i - 1][j]) return backtrack(i, j - 1);
  return backtrack(i - 1, j);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> a;
  cin >> b;
  int m = a.length();
  int n = b.length();
  LCSLength(m, n);
  string lcs = backtrack(m, n);
  cout << C[m][n] << "\n" << lcs << "\n";
  return 0;
}
