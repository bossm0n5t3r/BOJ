#include <cstdio>
#include <queue>

using namespace std;

int map[51][51];
bool visited[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
  int T, M, N, K, x, y, bug;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        map[i][j] = 0;
        visited[i][j] = false;
      }
    }
    while (K--) {
      scanf("%d %d", &x, &y);
      map[x][y] = 1;
    }
    bug = 0;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (!visited[i][j] && map[i][j] == 1) {
          bug++;
          queue<pair<int, int>> q;
          q.push(make_pair(i, j));
          visited[i][j] = true;
          while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
              int nx = x + dx[i];
              int ny = y + dy[i];
              if (0 > nx || nx >= M || 0 > ny || ny >= N || visited[nx][ny])
                continue;
              if (map[nx][ny]) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
              }
            }
          }
        }
      }
    }
    printf("%d\n", bug);
  }
  return 0;
}
