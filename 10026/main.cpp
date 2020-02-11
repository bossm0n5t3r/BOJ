#include <cstdio>

using namespace std;

int N;
char grid[101][101];
bool visited[101][101];

void dfs(int r, int c, char color) {
  if (0 > r || r >= N || 0 > c || c >= N || visited[r][c]) return;
  if (color == ' ' && grid[r][c] == 'B') return;
  if (color != ' ' && grid[r][c] != color) return;
  visited[r][c] = true;
  dfs(r + 1, c, color);
  dfs(r - 1, c, color);
  dfs(r, c + 1, color);
  dfs(r, c - 1, color);
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%s", grid[i]);
  int cnt = 0;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (!visited[r][c]) {
        dfs(r, c, grid[r][c]);
        cnt++;
      }
    }
  }
  printf("%d ", cnt);
  cnt = 0;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) visited[r][c] = false;
  }
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (!visited[r][c]) {
        dfs(r, c, grid[r][c] == 'B' ? 'B' : ' ');
        cnt++;
      }
    }
  }
  printf("%d", cnt);
  return 0;
}

// BFS method

// #include <memory.h>

// #include <iostream>
// #include <queue>

// using namespace std;

// int N;
// char picture[101][101];
// bool visited[101][101];
// int dr[] = {0, 0, 1, -1};
// int dc[] = {1, -1, 0, 0};

// char checkColor(int r, int c, bool colorBlindness) {
//   if (colorBlindness && picture[r][c] == 'G') return 'R';
//   return picture[r][c];
// }

// int bfs(bool colorBlindness) {
//   memset(visited, 0, sizeof(visited));
//   int cnt = 0;
//   for (int r = 0; r < N; r++) {
//     for (int c = 0; c < N; c++) {
//       if (!visited[r][c]) {
//         cnt++;
//         char basic = checkColor(r, c, colorBlindness);
//         queue<pair<int, int>> q;
//         q.push({r, c});
//         visited[r][c] = true;
//         while (!q.empty()) {
//           int curR = q.front().first;
//           int curC = q.front().second;
//           q.pop();
//           for (int i = 0; i < 4; i++) {
//             int nr = curR + dr[i];
//             int nc = curC + dc[i];
//             if (0 > nr || nr >= N || 0 > nc || nc >= N) continue;
//             if (checkColor(nr, nc, colorBlindness) == basic &&
//                 !visited[nr][nc]) {
//               visited[nr][nc] = true;
//               q.push({nr, nc});
//             }
//           }
//         }
//       }
//     }
//   }
//   return cnt;
// }

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> N;
//   for (int r = 0; r < N; r++) cin >> picture[r];
//   cout << bfs(false) << " " << bfs(true) << "\n";
//   return 0;
// }
