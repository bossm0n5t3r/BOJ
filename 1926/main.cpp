#include <iostream>
#include <queue>

using namespace std;

int n, m, cnt, max_area;
bool map[500][500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> q;

void bfs(int px, int py) {
  q.push(make_pair(px, py));
  map[px][py] = false;
  int area = 1;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny]) {
        map[nx][ny] = false;
        area++;
        q.push(make_pair(nx, ny));
      }
    }
  }
  if (max_area < area) max_area = area;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> map[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j]) {
        bfs(i, j);
        cnt++;
      }
    }
  }
  cout << cnt << "\n";
  cout << max_area << "\n";
  return 0;
}
