#include <cstdio>
#include <queue>

using namespace std;

int cnt;
int chess[301][301];
bool visited[301][301];
int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

void bfs(int I, int start_r, int start_c, int end_r, int end_c) {
  queue<pair<int, int>> q;
  q.push(make_pair(start_r, start_c));
  chess[start_r][start_c] = 0;
  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    if (r == end_r && c == end_c) {
      printf("%d\n", chess[end_r][end_c]);
      break;
    }
    q.pop();
    for (int i = 0; i < 8; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (0 > nr || nr >= I || 0 > nc || nc >= I) continue;
      if (!visited[nr][nc]) {
        visited[nr][nc] = true;
        chess[nr][nc] = chess[r][c] + 1;
        q.push(make_pair(nr, nc));
      }
    }
  }
}

int main() {
  int tc, I, start_r, start_c, end_r, end_c;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &I);
    for (int r = 0; r < I; r++) {
      for (int c = 0; c < I; c++) {
        chess[r][c] = 0;
        visited[r][c] = false;
      }
    }
    scanf("%d %d", &start_r, &start_c);
    scanf("%d %d", &end_r, &end_c);
    bfs(I, start_r, start_c, end_r, end_c);
  }
  return 0;
}
