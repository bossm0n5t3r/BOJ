#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int L, R, C;
char building[31][31][31];
int visited[31][31][31];
int dh[] = {1, -1, 0, 0, 0, 0};
int dr[] = {0, 0, 1, -1, 0, 0};
int dc[] = {0, 0, 0, 0, 1, -1};

int bfs() {
  queue<tuple<int, int, int>> q;
  for (int h = 0; h < L; h++) {
    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        if (building[h][r][c] == 'S') {
          q.push(make_tuple(h, r, c));
          break;
        }
      }
    }
  }
  while (!q.empty()) {
    int h, r, c;
    tie(h, r, c) = q.front();
    if (building[h][r][c] == 'E') return visited[h][r][c];
    q.pop();
    for (int i = 0; i < 6; i++) {
      int nh = h + dh[i];
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (0 > nh || nh >= L || 0 > nr || nr >= R || 0 > nc || nc >= C) continue;
      if (building[nh][nr][nc] != '#' && visited[nh][nr][nc] == 0) {
        visited[nh][nr][nc] = visited[h][r][c] + 1;
        q.push(make_tuple(nh, nr, nc));
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (1) {
    cin >> L >> R >> C;
    if (L == 0 && R == 0 && C == 0) return 0;
    memset(building, 0, sizeof(building));
    memset(visited, 0, sizeof(visited));
    for (int h = 0; h < L; h++) {
      for (int r = 0; r < R; r++) {
        cin >> building[h][r];
      }
    }
    int ans = bfs();
    if (ans != -1)
      cout << "Escaped in " << ans << " minute(s).\n";
    else
      cout << "Trapped!\n";
  }
  return 0;
}
