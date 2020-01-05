#include <cstdio>
#include <queue>

using namespace std;

int N;
int map[101][101];
int bridge[101][101];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

// 섬 numbering
void numbering() {
  int islandIdx = 2;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (map[r][c] == 1) {
        map[r][c] = islandIdx;
        queue<pair<int, int>> q;
        q.push(make_pair(r, c));
        while (!q.empty()) {
          int r = q.front().first;
          int c = q.front().second;
          q.pop();
          for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || nr >= N || 0 > nc || nc >= N) continue;
            if (map[nr][nc] == 1) {
              map[nr][nc] = islandIdx;
              q.push(make_pair(nr, nc));
            }
          }
        }
        islandIdx++;
      }
    }
  }
}

// 다리 만들기
void makeBridge() {
  int min = N * N + 1;
  queue<pair<int, int>> q;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (map[r][c] != 0) q.push(make_pair(r, c));
    }
  }
  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (0 > nr || nr >= N || 0 > nc || nc >= N) continue;
      if (map[nr][nc] == 0) {
        map[nr][nc] = map[r][c];
        bridge[nr][nc] = bridge[r][c] + 1;
        q.push(make_pair(nr, nc));
      } else if (map[nr][nc] != map[r][c]) {
        int totalBridge = bridge[nr][nc] + bridge[r][c];
        min = (min > totalBridge) ? totalBridge : min;
      }
    }
  }
  printf("%d\n", min);
}

int main() {
  scanf("%d", &N);
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) scanf("%d", &map[r][c]);
  }
  numbering();
  makeBridge();
  return 0;
}
