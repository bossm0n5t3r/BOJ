#include <cstdio>
#include <queue>

using namespace std;

int N, max_rain, max_area;
int map[101][101];
bool visited[101][101];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void bfs(int rain) {
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) visited[r][c] = false;
  }
  int cnt = 0;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (!visited[r][c] && map[r][c] > rain) {
        cnt++;
        queue<pair<int, int>> q;
        q.push(make_pair(r, c));
        visited[r][c] = true;
        while (!q.empty()) {
          int r = q.front().first;
          int c = q.front().second;
          q.pop();
          for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || nr >= N || 0 > nc || nc >= N) continue;
            if (!visited[nr][nc] && map[r][c] > rain) {
              visited[nr][nc] = true;
              q.push(make_pair(nr, nc));
            }
          }
        }
      }
    }
  }
  if (cnt > max_area) max_area = cnt;
}

int main() {
  scanf("%d", &N);
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      scanf("%d", &map[r][c]);
      if (map[r][c] > max_rain) max_rain = map[r][c];
    }
  }
  for (int rain = 0; rain < max_rain; rain++) bfs(rain);
  printf("%d\n", max_area);
  return 0;
}
