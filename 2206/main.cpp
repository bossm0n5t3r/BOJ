#include <iostream>
#include <queue>

using namespace std;

typedef struct Point {
  int r;
  int c;
  bool isBroken;
} Point;

int N, M;
char map[1001][1001];
int dist[1001][1001][2];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void bfs() {
  queue<Point> q;
  q.push({0, 0, 0});
  dist[0][0][0] = 1;
  while (!q.empty()) {
    int r = q.front().r;
    int c = q.front().c;
    bool isBroken = q.front().isBroken;
    if (r == N - 1 && c == M - 1) {
      cout << dist[r][c][isBroken] << "\n";
      return;
    }
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (0 > nr || nr >= N || 0 > nc || nc >= M) continue;
      if (dist[nr][nc][isBroken] == 0) {
        if (map[nr][nc] == '0') {
          dist[nr][nc][isBroken] = dist[r][c][isBroken] + 1;
          q.push({nr, nc, isBroken});
        }
        if (map[nr][nc] == '1' && isBroken == 0) {
          dist[nr][nc][1] = dist[r][c][isBroken] + 1;
          q.push({nr, nc, 1});
        }
      }
    }
  }
  cout << -1 << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int r = 0; r < N; r++) cin >> map[r];
  bfs();
  return 0;
}
