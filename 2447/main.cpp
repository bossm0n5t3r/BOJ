#include <memory.h>

#include <iostream>

using namespace std;

char stars[2188][2188];

void printing_stars(int N, int r, int c) {
  if (N == 3) {
    stars[r][c] = '*';
    stars[r][c + 1] = '*';
    stars[r][c + 2] = '*';
    stars[r + 1][c] = '*';
    stars[r + 1][c + 1] = ' ';
    stars[r + 1][c + 2] = '*';
    stars[r + 2][c] = '*';
    stars[r + 2][c + 1] = '*';
    stars[r + 2][c + 2] = '*';
    return;
  }
  printing_stars(N / 3, r, c);
  printing_stars(N / 3, r, c + N / 3);
  printing_stars(N / 3, r, c + (N / 3 * 2));
  printing_stars(N / 3, r + N / 3, c);
  printing_stars(N / 3, r + N / 3, c + (N / 3 * 2));
  printing_stars(N / 3, r + (N / 3 * 2), c);
  printing_stars(N / 3, r + (N / 3 * 2), c + N / 3);
  printing_stars(N / 3, r + (N / 3 * 2), c + (N / 3 * 2));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  memset(stars, ' ', sizeof(stars));
  printing_stars(N, 0, 0);
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      cout << stars[r][c];
    }
    cout << "\n";
  }
  return 0;
}
