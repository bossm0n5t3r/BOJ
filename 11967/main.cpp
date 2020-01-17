#include <memory.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int rooms[101][101];
int visited[101][101];
int saveVisited[101][101];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
vector<pair<int, int>> v[101][101];

bool bfs() {
  bool flag = false;
  queue<pair<int, int>> q;
  q.push({1, 1});
  visited[1][1] = true;
  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();
    if (!saveVisited[r][c] && !v[r][c].empty()) {
      for (pair<int, int> to : v[r][c]) rooms[to.first][to.second] = 1;
      saveVisited[r][c] = 1;
      flag = true;
    }
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (1 > nr || nr > N || 1 > nc || nc > N) continue;
      if (rooms[nr][nc] == 1 && !visited[nr][nc]) {
        visited[nr][nc] = 1;
        q.push({nr, nc});
      }
    }
  }
  return flag;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  int x, y, a, b;
  while (M--) {
    cin >> x >> y >> a >> b;
    v[x][y].push_back({a, b});
  }
  while (1) {
    memset(visited, 0, sizeof(visited));
    rooms[1][1] = 1;
    if (!bfs()) break;
  }
  int light = 0;
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= N; c++) {
      if (rooms[r][c]) light++;
    }
  }
  cout << light << "\n";
  return 0;
}
