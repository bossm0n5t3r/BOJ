#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int tc, w, h;
char building[1001][1001];
bool visited[1001][1001];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int bfs() {
  queue<pair<int, int>> person;
  queue<pair<int, int>> fire;
  // 사람, 불 찾고
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      if (building[r][c] == '@') {
        person.push(make_pair(r, c));
      }
      if (building[r][c] == '*') {
        fire.push(make_pair(r, c));
      }
    }
  }
  int time = 0;
  while (int size = person.size()) {
    // 불 번지고
    int fireSize = fire.size();
    while (fireSize--) {
      int r = fire.front().first;
      int c = fire.front().second;
      fire.pop();
      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 > nr || nr >= h || 0 > nc || nc >= w) continue;
        if (building[nr][nc] == '.') {
          building[nr][nc] = '*';
          fire.push(make_pair(nr, nc));
        }
      }
    }
    // 사람 도망가고
    int personSize = person.size();
    while (personSize--) {
      int r = person.front().first;
      int c = person.front().second;
      person.pop();
      if (r == 0 || r == h - 1 || c == 0 || c == w - 1) return time + 1;
      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 > nr || nr >= h || 0 > nc || nc >= w) continue;
        if (!visited[nr][nc] && building[nr][nc] != '*' &&
            building[nr][nc] != '#') {
          visited[nr][nc] = true;
          person.push(make_pair(nr, nc));
        }
      }
    }
    time++;
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> tc;
  while (tc--) {
    memset(building, 0, sizeof(building));
    memset(visited, 0, sizeof(visited));
    cin >> w >> h;
    for (int r = 0; r < h; r++) cin >> building[r];
    int ans = bfs();
    if (ans == -1)
      cout << "IMPOSSIBLE\n";
    else
      cout << ans << "\n";
  }
  return 0;
}
