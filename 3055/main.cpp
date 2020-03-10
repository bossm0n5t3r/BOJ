#include <iostream>
#include <queue>

using namespace std;

int R, C;
char map[51][51];
int visited[51][51];
queue<pair<int, int>> hedgehog;
queue<pair<int, int>> water;
pair<int, int> cave;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void bfs() {
  // 고슴도치가 움직일 수 있으면
  while (!hedgehog.empty()) {
    // 먼저 물이 범람한다.
    int waterSize = water.size();
    while (waterSize--) {
      int r = water.front().first;
      int c = water.front().second;
      water.pop();
      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 > nr || nr >= R || 0 > nc || nc >= C) continue;
        if (map[nr][nc] != '.') continue;
        map[nr][nc] = '*';
        water.push(make_pair(nr, nc));
      }
    }
    // 고슴도치가 이동한다.
    int hedgehogSize = hedgehog.size();
    while (hedgehogSize--) {
      int r = hedgehog.front().first;
      int c = hedgehog.front().second;
      hedgehog.pop();
      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 > nr || nr >= R || 0 > nc || nc >= C) continue;
        if (map[nr][nc] == 'D') {
          cout << visited[r][c] + 1 << "\n";
          return;
        } else if (!visited[nr][nc] && map[nr][nc] == '.') {
          visited[nr][nc] = visited[r][c] + 1;
          hedgehog.push(make_pair(nr, nc));
        }
      }
    }
  }
  cout << "KAKTUS\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C;
  for (int r = 0; r < R; r++) {
    cin >> map[r];
    for (int c = 0; c < C; c++) {
      if (map[r][c] == '*') {
        water.push(make_pair(r, c));
      } else if (map[r][c] == 'D') {
        cave = make_pair(r, c);
      } else if (map[r][c] == 'S') {
        hedgehog.push(make_pair(r, c));
      }
    }
  }
  bfs();
  return 0;
}
