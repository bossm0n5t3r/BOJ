#include <iostream>

using namespace std;

int s[100001];
char p[400004];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, num = 1, pIdx = 0, sIdx = 0, pop;
  cin >> n;
  while (n--) {
    cin >> x;
    while (num <= x) {
      s[sIdx++] = num++;
      p[pIdx++] = '+';
      p[pIdx++] = '\n';
    }
    pop = s[--sIdx];
    p[pIdx++] = '-';
    p[pIdx++] = '\n';
    if (pop != x) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << p;
  return 0;
}
