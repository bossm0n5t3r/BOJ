#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int M, N, K;
int map[101][101];
bool visited[101][101];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
vector<int> ans;

void bfs(int r, int c) {
  queue<pair<int, int>> q;
  q.push(make_pair(r, c));
  visited[r][c] = true;
  int cnt = 1;
  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = r + dy[i];
      int nc = c + dx[i];
      if (0 > nr || nr >= M || 0 > nc || nc >= N) continue;
      if (!visited[nr][nc] && map[nr][nc] == 0) {
        visited[nr][nc] = true;
        cnt++;
        q.push(make_pair(nr, nc));
      }
    }
  }
  ans.push_back(cnt);
}

int main() {
  int x1, y1, x2, y2;
  scanf("%d %d %d", &M, &N, &K);
  while (K--) {
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    for (int c = x1; c < x2; c++) {
      for (int r = y1; r < y2; r++) {
        if (map[r][c] != 1) map[r][c] = 1;
      }
    }
  }
  for (int r = 0; r < M; r++) {
    for (int c = 0; c < N; c++) {
      if (!visited[r][c] && map[r][c] == 0) bfs(r, c);
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int n : ans) printf("%d ", n);
  return 0;
}
