#include <memory.h>

#include <iostream>

using namespace std;

char stars[3073][6145];

void printing_stars(int N, int r, int c) {
  if (N == 3) {
    stars[r + 0][c + 2] = '*';
    stars[r + 1][c + 1] = '*';
    stars[r + 1][c + 3] = '*';
    stars[r + 2][c + 0] = '*';
    stars[r + 2][c + 1] = '*';
    stars[r + 2][c + 2] = '*';
    stars[r + 2][c + 3] = '*';
    stars[r + 2][c + 4] = '*';
    return;
  }
  printing_stars(N / 2, r, c + N / 2);
  printing_stars(N / 2, r + N / 2, c);
  printing_stars(N / 2, r + N / 2, c + N);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset(stars, ' ', sizeof(stars));
  int N;
  cin >> N;
  printing_stars(N, 0, 0);
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < 2 * N; c++) {
      cout << stars[r][c];
    }
    cout << "\n";
  }
  return 0;
}
