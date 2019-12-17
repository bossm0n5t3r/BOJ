#include <algorithm>
#include <cstring>
#include <iostream>
#include <list>

using namespace std;

const int MAXN = 6e5 + 10;
const int MAXM = 5e5 + 10;
char L[MAXN];
char R[MAXM];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, Lidx, Ridx;
  char cmd, x;
  cin >> L;
  cin >> N;
  Lidx = strlen(L);
  Ridx = 0;
  while (N--) {
    cin >> cmd;
    if (cmd == 'L') {
      if (!Lidx) continue;
      R[Ridx++] = L[Lidx - 1];
      Lidx--;
    } else if (cmd == 'D') {
      if (!Ridx) continue;
      L[Lidx++] = R[Ridx - 1];
      Ridx--;
    } else if (cmd == 'B') {
      if (!Lidx) continue;
      Lidx--;
    } else if (cmd == 'P') {
      cin >> x;
      L[Lidx++] = x;
    }
  }
  reverse(R, R + Ridx);
  L[Lidx] = 0;
  R[Ridx] = 0;
  cout << L << R << "\n";
  return 0;
}
