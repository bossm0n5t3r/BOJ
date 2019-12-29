#include <iostream>
#include <queue>

using namespace std;

typedef struct Point {
  int z;
  int y;
  int x;
} Point;

int box[101][101][101];
int date[101][101][101];
bool visited[101][101][101];
int dz[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 1, 0, -1, 0, 0};
int dx[] = {1, 0, -1, 0, 0, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int M, N, H, check = 0, max_date = 0;
  queue<Point> q;
  cin >> M >> N >> H;
  for (int z = 0; z < H; z++) {
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        cin >> box[z][y][x];
        if (box[z][y][x] == 1) {
          Point p;
          p.z = z;
          p.y = y;
          p.x = x;
          q.push(p);
        }
        if (box[z][y][x] != 0) visited[z][y][x] = true;
      }
    }
  }
  while (!q.empty()) {
    int z = q.front().z;
    int y = q.front().y;
    int x = q.front().x;
    q.pop();
    for (int i = 0; i < 6; i++) {
      int nz = z + dz[i];
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (0 > nz || nz >= H || 0 > ny || ny >= N || 0 > nx || nx >= M) continue;
      if (!visited[nz][ny][nx] && box[nz][ny][nx] == 0) {
        visited[nz][ny][nx] = true;
        date[nz][ny][nx] = date[z][y][x] + 1;
        if (date[nz][ny][nx] > max_date) max_date = date[nz][ny][nx];
        Point p;
        p.z = nz;
        p.y = ny;
        p.x = nx;
        q.push(p);
      }
    }
  }
  bool notVisited = false;
  for (int z = 0; z < H; z++) {
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < M; x++) {
        if (!visited[z][y][x] && box[z][y][x] == 0) {
          notVisited = true;
          break;
        }
      }
    }
  }
  if (notVisited)
    cout << -1 << "\n";
  else
    cout << max_date << "\n";
  return 0;
}
