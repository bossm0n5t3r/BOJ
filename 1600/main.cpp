#include <cstdio>

using namespace std;

typedef struct Monkey {
  int r, c, d, k;
} Monkey;

int map[201][201];
int visited[31][201][201];
int mdr[] = {0, 0, 1, -1};
int mdc[] = {1, -1, 0, 0};
int hdr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hdc[] = {1, 2, 2, 1, -1, -2, -2, -1};

Monkey q[100001];

int main() {
  int K, W, H;
  scanf("%d", &K);
  scanf("%d %d", &W, &H);
  for (int r = 0; r < H; r++) {
    for (int c = 0; c < W; c++) {
      scanf("%d", &map[r][c]);
    }
  }
  int s = 0, e = 0;
  q[e++] = {0, 0, 0, 0};
  visited[0][0][0] = 1;
  while (s < e) {
    Monkey cur = q[s++];
    if (cur.r == H - 1 && cur.c == W - 1) {
      printf("%d\n", cur.d);
      return 0;
    }
    if (cur.k < K) {
      for (int i = 0; i < 8; i++) {
        int nr = cur.r + hdr[i];
        int nc = cur.c + hdc[i];
        if (0 > nr || nr >= H || 0 > nc || nc >= W) continue;
        if (!visited[cur.k + 1][nr][nc] && !map[nr][nc]) {
          if (nr == H - 1 && nc == W - 1) {
            printf("%d\n", cur.d + 1);
            return 0;
          }
          visited[cur.k + 1][nr][nc] = 1;
          q[e++] = {nr, nc, cur.d + 1, cur.k + 1};
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      int nr = cur.r + mdr[i];
      int nc = cur.c + mdc[i];
      if (0 > nr || nr >= H || 0 > nc || nc >= W) continue;
      if (!visited[cur.k][nr][nc] && !map[nr][nc]) {
        if (nr == H - 1 && nc == W - 1) {
          printf("%d\n", cur.d + 1);
          return 0;
        }
        visited[cur.k][nr][nc] = 1;
        q[e++] = {nr, nc, cur.d + 1, cur.k};
      }
    }
  }
  printf("-1\n");
  return 0;
}
