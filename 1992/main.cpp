#include <iostream>

using namespace std;

char pic[65][65];

void quadtree(int N, int r, int c) {
  if (N == 1) {
    cout << pic[r][c];
    return;
  }
  char find = pic[r][c];
  int half = N / 2;
  for (int curR = r; curR < r + N; curR++) {
    for (int curC = c; curC < c + N; curC++) {
      if (find != pic[curR][curC]) {
        cout << "(";
        quadtree(half, r, c);
        quadtree(half, r, c + half);
        quadtree(half, r + half, c);
        quadtree(half, r + half, c + half);
        cout << ")";
        return;
      }
    }
  }
  cout << find;
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int r = 0; r < N; r++) cin >> pic[r];
  quadtree(N, 0, 0);
  return 0;
}
