#include <cstdio>
#include <queue>

using namespace std;

int N, cnt;
char grid[101][101];
bool visited[101][101];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void bfs(int r, int c, bool isColorBlindness) {
  queue<pair<int, int>> q;
  q.push(make_pair(r, c));
  char color = grid[r][c];
  cnt++;
  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (0 > nr || nr >= N || 0 > nc || nc >= N) continue;
      if (isColorBlindness) {
        if (color == 'R' || color == 'G') {
          if (!visited[nr][nc]) {
            if (grid[nr][nc] == 'R' || grid[nr][nc] == 'G') {
              visited[nr][nc] = true;
              q.push(make_pair(nr, nc));
            }
          }
        } else {
          if (!visited[nr][nc] && grid[nr][nc] == color) {
            visited[nr][nc] = true;
            q.push(make_pair(nr, nc));
          }
        }
      } else {
        if (!visited[nr][nc] && grid[nr][nc] == color) {
          visited[nr][nc] = true;
          q.push(make_pair(nr, nc));
        }
      }
    }
  }
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%s", grid[i]);
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (!visited[r][c]) bfs(r, c, false);
    }
  }
  printf("%d ", cnt);
  cnt = 0;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) visited[r][c] = false;
  }
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (!visited[r][c]) bfs(r, c, true);
    }
  }
  printf("%d", cnt);
  return 0;
}
