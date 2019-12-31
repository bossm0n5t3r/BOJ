#include <cstdio>

using namespace std;

int N;
char grid[101][101];
bool visited[101][101];

void dfs(int r, int c, char color) {
  if (0 > r || r >= N || 0 > c || c >= N || visited[r][c]) return;
  if (color == ' ' && grid[r][c] == 'B') return;
  if (color != ' ' && grid[r][c] != color) return;
  visited[r][c] = true;
  dfs(r + 1, c, color);
  dfs(r - 1, c, color);
  dfs(r, c + 1, color);
  dfs(r, c - 1, color);
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%s", grid[i]);
  int cnt = 0;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (!visited[r][c]) {
        dfs(r, c, grid[r][c]);
        cnt++;
      }
    }
  }
  printf("%d ", cnt);
  cnt = 0;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) visited[r][c] = false;
  }
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (!visited[r][c]) {
        dfs(r, c, grid[r][c] == 'B' ? 'B' : ' ');
        cnt++;
      }
    }
  }
  printf("%d", cnt);
  return 0;
}
