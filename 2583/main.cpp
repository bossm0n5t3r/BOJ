#include <algorithm>
#include <cstdio>

using namespace std;

int M, N, K, cnt;
bool map[101][101];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void dfs(int r, int c) {
  map[r][c] = true;
  cnt++;
  for (int i = 0; i < 4; i++) {
    int nr = r + dy[i];
    int nc = c + dx[i];
    if (0 > nr || nr >= M || 0 > nc || nc >= N) continue;
    if (!map[nr][nc]) dfs(nr, nc);
  }
}

int main() {
  int ans[5000];
  int x1, y1, x2, y2, size = 0;
  scanf("%d %d %d", &M, &N, &K);
  while (K--) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for (int c = x1; c < x2; c++) {
      for (int r = y1; r < y2; r++) {
        map[r][c] = 1;
      }
    }
  }
  for (int r = 0; r < M; r++) {
    for (int c = 0; c < N; c++) {
      if (!map[r][c]) {
        dfs(r, c);
        ans[size++] = cnt;
        cnt = 0;
      }
    }
  }
  sort(ans, ans + size);
  printf("%d\n", size);
  for (int i = 0; i < size; i++) printf("%d ", ans[i]);
  return 0;
}
