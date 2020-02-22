#include <iostream>

using namespace std;

int N;
int color[2];
int paper[129][129];

void recursive(int N, int r, int c) {
  if (N == 1) {
    color[paper[r][c]]++;
    return;
  }
  int half = N / 2;
  int check = paper[r][c];
  for (int curR = r; curR < r + N; curR++) {
    for (int curC = c; curC < c + N; curC++) {
      if (check != paper[curR][curC]) {
        recursive(half, r, c);
        recursive(half, r, c + half);
        recursive(half, r + half, c);
        recursive(half, r + half, c + half);
        return;
      }
    }
  }
  color[check]++;
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      cin >> paper[r][c];
    }
  }
  recursive(N, 0, 0);
  cout << color[0] << "\n" << color[1] << "\n";
  return 0;
}
