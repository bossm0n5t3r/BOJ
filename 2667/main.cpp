#include <algorithm>
#include <cstdio>

using namespace std;

int N, cnt;
int map[26][26];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void dfs(int r, int c) {
  map[r][c] = 0;
  cnt++;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (0 <= nr && nr < N && 0 <= nc && nc < N && map[nr][nc]) dfs(nr, nc);
  }
}

int main() {
  int size = 0;
  int ans[500];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%1d", &map[i][j]);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (map[i][j]) {
        dfs(i, j);
        ans[size++] = cnt;
        cnt = 0;
      }
    }
  }
  sort(ans, ans + size);
  printf("%d\n", size);
  for (int i = 0; i < size; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}
