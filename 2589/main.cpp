#include <memory.h>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
char map[51][51];
bool visited[51][51];
bool done[51][51];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void bfs() {
  int max = 0;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < M; c++) {
      if (map[r][c] == 'L' && !done[r][c]) {
        done[r][c] = true;
        int dist = -1;
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        while (!q.empty()) {
          dist++;
          int size = (int)q.size();
          while (size--) {
            int curR = q.front().first;
            int curC = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
              int nr = curR + dr[i];
              int nc = curC + dc[i];
              if (0 > nr || nr >= N || 0 > nc || nc >= M) continue;
              if (map[nr][nc] == 'L' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc});
              }
            }
          }
        }
        if (dist > max) max = dist;
      }
    }
  }
  cout << max << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int r = 0; r < N; r++) cin >> map[r];
  bfs();
  return 0;
}
