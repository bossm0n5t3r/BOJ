#include <iostream>

using namespace std;

int map[101][101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int area = 0;
  int x0, y0, x1, y1;
  for (int i = 0; i < 4; i++) {
    cin >> x0 >> y0 >> x1 >> y1;
    for (int r = y0; r < y1; r++) {
      for (int c = x0; c < x1; c++) {
        if (map[r][c] == 0) {
          map[r][c] = 1;
          area++;
        }
      }
    }
  }
  cout << area << "\n";
  return 0;
}
