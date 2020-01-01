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
  Point p;
  p.r = 0;
  p.c = 0;
  p.isBroken = false;
  q.push(p);
  dist[p.r][p.c][p.isBroken] = 1;
  while (!q.empty()) {
    int r = q.front().r;
    int c = q.front().c;
    bool isBroken = q.front().isBroken;
    if (r == N - 1 && c == M - 1) {
      cout << dist[r][c][isBroken];
      return;
    }
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (0 > nr || nr >= N | 0 > nc || nc >= M) continue;
      if (dist[nr][nc][isBroken] == 0) {
        if (map[nr][nc] == '0') {
          dist[nr][nc][isBroken] = dist[r][c][isBroken] + 1;
          Point p;
          p.r = nr;
          p.c = nc;
          p.isBroken = isBroken;
          q.push(p);
        }
        if (map[nr][nc] == '1' && isBroken == 0) {
          dist[nr][nc][1] = dist[r][c][isBroken] + 1;
          Point p;
          p.r = nr;
          p.c = nc;
          p.isBroken = 1;
          q.push(p);
        }
      }
    }
  }
  cout << -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int r = 0; r < N; r++) cin >> map[r];
  bfs();
  return 0;
}
