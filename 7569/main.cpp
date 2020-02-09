#include <iostream>
#include <queue>

using namespace std;

int box[101][101][101];
bool visited[101][101][101];
int dh[] = {1, -1, 0, 0, 0, 0};
int dr[] = {0, 0, 1, -1, 0, 0};
int dc[] = {0, 0, 0, 0, 1, -1};

typedef struct Point {
  int h, r, c;
} Point;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int M, N, H, tomato;
  queue<Point> q;
  cin >> M >> N >> H;
  for (int h = 0; h < H; h++) {
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < M; c++) {
        cin >> tomato;
        box[h][r][c] = tomato;
        if (tomato == 1)
          q.push({h, r, c});
        else if (tomato == -1)
          visited[h][r][c] = true;
      }
    }
  }
  int day = -1;
  while (!q.empty()) {
    day++;
    int size = q.size();
    while (size--) {
      Point p = q.front();
      q.pop();
      visited[p.h][p.r][p.c] = true;
      for (int i = 0; i < 6; i++) {
        int nh = p.h + dh[i];
        int nr = p.r + dr[i];
        int nc = p.c + dc[i];
        if (0 > nh || nh >= H || 0 > nr || nr >= N || 0 > nc || nc >= M)
          continue;
        if (box[nh][nr][nc] == 0 && !visited[nh][nr][nc]) {
          visited[nh][nr][nc] = true;
          box[nh][nr][nc] = 1;
          q.push({nh, nr, nc});
        }
      }
    }
  }
  for (int h = 0; h < H; h++) {
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < M; c++) {
        if (box[h][r][c] == 0) {
          cout << -1 << "\n";
          return 0;
        }
      }
    }
  }
  cout << day << "\n";
  return 0;
}
