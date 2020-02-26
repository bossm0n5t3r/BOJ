#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int cnt = 0;
  char map[9][9];
  for (int r = 0; r < 8; r++) cin >> map[r];
  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      if ((r + c) % 2 == 0 && map[r][c] == 'F') cnt++;
    }
  }
  cout << cnt << "\n";
  return 0;
}
