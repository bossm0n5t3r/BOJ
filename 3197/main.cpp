#include <iostream>
#include <queue>

using namespace std;

int R, C;
bool Find;
char lake[1501][1501];
bool visited[1501][1501];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
pair<int, int> swan;
queue<pair<int, int>> swan_q, swan_nq, water_q, water_nq;

void swanBFS() {
  while (!swan_q.empty() && !Find) {
    int r = swan_q.front().first;
    int c = swan_q.front().second;
    swan_q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (0 > nr || nr >= R || 0 > nc || nc >= C) continue;
      if (!visited[nr][nc]) {
        visited[nr][nc] = true;
        if (lake[nr][nc] == 'L') {
          Find = true;
          break;
        } else if (lake[nr][nc] == '.') {
          swan_q.push({nr, nc});
        } else if (lake[nr][nc] == 'X') {
          swan_nq.push({nr, nc});
        }
      }
    }
  }
}

void waterBFS() {
  while (!water_q.empty()) {
    int r = water_q.front().first;
    int c = water_q.front().second;
    water_q.pop();
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (0 > nr || nr >= R || 0 > nc || nc >= C) continue;
      if (lake[nr][nc] == 'X') {
        lake[nr][nc] = '.';
        water_nq.push({nr, nc});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C;
  Find = false;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      cin >> lake[r][c];
      if (lake[r][c] != 'X') water_q.push({r, c});
      if (lake[r][c] == 'L') {
        swan.first = r;
        swan.second = c;
      }
    }
  }
  int day = 0;
  swan_q.push(swan);
  visited[swan.first][swan.second] = true;
  while (!Find) {
    swanBFS();
    if (!Find) {
      waterBFS();
      water_q = water_nq;
      swan_q = swan_nq;
      water_nq = {};
      swan_nq = {};
      day++;
    }
  }
  cout << day << "\n";
  return 0;
}
