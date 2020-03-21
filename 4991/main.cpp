#include <memory.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int w, h;           // w: 가로의 길이, h: 세로의 길이
char room[21][21];  // 방
int dist[21][21][21];
bool visited[21][21][21];
vector<pair<pair<int, int>, int>> trash;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void bfs(int r, int c, int pos) {
  queue<pair<int, int>> q;
  q.push({r, c});
  dist[r][c][pos] = 0;
  visited[r][c][pos] = true;
  while (!q.empty()) {
    int curR = q.front().first;
    int curC = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = curR + dr[i];
      int nc = curC + dc[i];
      if (0 > nr || nr >= h || 0 > nc || nc >= w) continue;
      if (room[nr][nc] != 'x' && !visited[nr][nc][pos]) {
        visited[nr][nc][pos] = true;
        dist[nr][nc][pos] = dist[curR][curC][pos] + 1;
        q.push({nr, nc});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    // dist 초기화
    for (int r = 0; r < 21; r++) {
      for (int c = 0; c < 21; c++) {
        for (int pos = 0; pos < 21; pos++) {
          dist[r][c][pos] = 1e5;
        }
      }
    }
    memset(room, 0, sizeof(room));        // 방 초기화
    memset(visited, 0, sizeof(visited));  // 방문 초기화
    trash.clear();                        // 쓰레기 초기화
    int trashCnt = 1;
    int startR, startC;  // 로봇 청소기의 처음 위치
    for (int r = 0; r < h; r++) {
      cin >> room[r];
      for (int c = 0; c < w; c++) {
        if (room[r][c] == '*') trash.push_back({{r, c}, trashCnt++});
        if (room[r][c] == 'o') startR = r, startC = c;
      }
    }
    int ans = 1e5;
    int dirty = trash.size();
    if (dirty == 0) {
      puts("0");
      continue;
    }
    bfs(startR, startC, 0);
    sort(trash.begin(), trash.end());
    for (int i = 0; i < dirty; i++) {
      bfs(trash[i].first.first, trash[i].first.second, trash[i].second);
    }
    do {
      int tmp = dist[trash[0].first.first][trash[0].first.second][0];
      for (int i = 1; i < dirty; i++) {
        tmp += dist[trash[i].first.first][trash[i].first.second]
                   [trash[i - 1].second];
      }
      ans = min(ans, tmp);
    } while (next_permutation(trash.begin(), trash.end()));
    cout << (ans == 1e5 ? -1 : ans) << "\n";
  }
  return 0;
}
