#include <iostream>
#include <queue>

using namespace std;

typedef struct Monkey {
  int r;
  int c;
  int dist;
  int curK;
} Monkey;

int K;
int W, H;
int map[201][201];
bool visited[201][201][31];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
int dhr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dhc[] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs() {
  queue<Monkey> q;
  q.push({0, 0, 0, K});
  visited[0][0][K] = true;
  while (!q.empty()) {
    int r = q.front().r;
    int c = q.front().c;
    int dist = q.front().dist;
    int curK = q.front().curK;
    q.pop();
    if (r == H - 1 && c == W - 1) {
      cout << dist << "\n";
      return;
    }
    if (curK > 0) {
      for (int i = 0; i < 8; i++) {
        int nr = r + dhr[i];
        int nc = c + dhc[i];
        if (0 > nr || nr >= H || 0 > nc || nc >= W) continue;
        if (map[nr][nc] != 1 && !visited[nr][nc][curK - 1]) {
          if (nr == H - 1 && nc == W - 1) {
            cout << dist + 1 << "\n";
            return;
          }
          visited[nr][nc][curK - 1] = true;
          q.push({nr, nc, dist + 1, curK - 1});
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (0 > nr || nr >= H || 0 > nc || nc >= W) continue;
      if (map[nr][nc] != 1 && !visited[nr][nc][curK]) {
        if (nr == H - 1 && nc == W - 1) {
          cout << dist + 1 << "\n";
          return;
        }
        visited[nr][nc][curK] = true;
        q.push({nr, nc, dist + 1, curK});
      }
    }
  }
  cout << -1 << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> K;
  cin >> W >> H;
  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      cin >> map[r][c];
    }
  }
  bfs();
  return 0;
}
