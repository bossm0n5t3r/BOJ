#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

char map[26][26];
int N;
bool visited[26][26];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
vector<int> ans;

void bfs(int r, int c) {
  queue<pair<int, int>> q;
  q.push(make_pair(r, c));
  visited[r][c] = true;
  int cnt = 1;
  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (0 > ny || ny >= N || 0 > nx || nx >= N) continue;
      if (!visited[ny][nx] && map[ny][nx] == '1') {
        visited[ny][nx] = true;
        cnt++;
        q.push(make_pair(ny, nx));
      }
    }
  }
  ans.push_back(cnt);
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%s", map[i]);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j] && map[i][j] == '1') bfs(i, j);
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", ans.size());
  for (int n : ans) {
    printf("%d\n", n);
  }
  return 0;
}
