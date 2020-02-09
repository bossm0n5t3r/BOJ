#include <memory.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int max_safety, safety;
int cnt[3];
int lab[9][9];
bool visited[9][9];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
queue<pair<int, int>> originQ;
vector<pair<int, int>> v;

int bfs(int i, int j, int k, int infected) {
  queue<pair<int, int>> q = originQ;
  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    infected++;
    visited[r][c] = true;
    q.pop();
    for (int x = 0; x < 4; x++) {
      int nr = r + dr[x];
      int nc = c + dc[x];
      if (0 > nr || nr >= N || 0 > nc || nc >= M) continue;
      if (nr == v[i].first && nc == v[i].second) continue;
      if (nr == v[j].first && nc == v[j].second) continue;
      if (nr == v[k].first && nc == v[k].second) continue;
      if (lab[nr][nc] == 0 && !visited[nr][nc]) {
        visited[nr][nc] = true;
        q.push({nr, nc});
      }
    }
  }
  return infected;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      cin >> lab[r][c];
      if (lab[r][c] == 0) {
        v.push_back({r, c});
        cnt[0]++;
      } else if (lab[r][c] == 2) {
        originQ.push({r, c});
        cnt[2]++;
      } else
        cnt[1]++;
    }
  }
  int vSize = (int)v.size();
  for (int i = 0; i < vSize - 2; i++) {
    for (int j = i + 1; j < vSize - 1; j++) {
      for (int k = j + 1; k < vSize; k++) {
        memset(visited, 0, sizeof(visited));
        int infected = bfs(i, j, k, 0);
        safety = N * M - cnt[1] - 3 - infected;
        if (max_safety < safety) max_safety = safety;
      }
    }
  }
  cout << max_safety << "\n";
  return 0;
}
