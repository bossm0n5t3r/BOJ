#include <cstdio>
#include <queue>

using namespace std;

char map[101][101];
int dist[101][101];
bool visited[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) scanf("%s", map[i]);
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  visited[0][0] = true;
  dist[0][0] = 1;
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    if (x == N - 1 && y == M - 1) break;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (0 <= nx && nx < N && 0 <= ny && ny <= M && !visited[nx][ny] &&
          map[nx][ny] == '1') {
        visited[nx][ny] = true;
        dist[nx][ny] = dist[x][y] + 1;
        q.push(make_pair(nx, ny));
      }
    }
  }
  printf("%d\n", dist[N - 1][M - 1]);
  return 0;
}
