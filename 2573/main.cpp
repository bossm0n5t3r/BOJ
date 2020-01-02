#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int iceberg[301][301];
int melting_info[301][301];
bool visited[301][301];
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

void melt() {
  memcpy(melting_info, iceberg, sizeof(iceberg));
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      if (melting_info[r][c]) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
          int nr = r + dr[i];
          int nc = c + dc[i];
          if (0 > nr || nr >= N || 0 > nc || nc >= M) continue;
          if (melting_info[nr][nc] == 0) cnt++;
        }
        iceberg[r][c] = melting_info[r][c] - cnt;
        if (iceberg[r][c] < 0) iceberg[r][c] = 0;
      }
    }
  }
}

void dfs(int r, int c) {
  visited[r][c] = true;
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (0 > nr || nr >= N || 0 > nc || nc >= M) continue;
    if (iceberg[nr][nc] && !visited[nr][nc]) dfs(nr, nc);
  }
}

void bfs(int r, int c) {
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
      if (0 > nr || nr >= N || 0 > nc || nc >= M) continue;
      if (iceberg[nr][nc] && !visited[nr][nc]) {
        visited[nr][nc] = true;
        q.push(make_pair(nr, nc));
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      cin >> iceberg[r][c];
    }
  }
  int year = 0;
  while (1) {
    int cnt = 1;
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < M; c++) {
        if (iceberg[r][c] && !visited[r][c]) {
          if (cnt > 1) {
            cout << year << "\n";
            return 0;
          }
          // bfs(r, c);
          dfs(r, c);
          cnt++;
        }
      }
    }
    memset(visited, false, sizeof(visited));
    if (cnt == 1) {
      cout << 0 << "\n";
      return 0;
    }
    melt();
    year++;
  }
  return 0;
}
