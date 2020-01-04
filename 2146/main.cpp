#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int N;
int map[101][101];
bool visited[101][101];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int dist(pair<int, int> p1, pair<int, int> p2) {
  return abs(p1.first - p2.first) + abs(p1.second - p2.second) - 1;
}

int bfs() {
  vector<set<pair<int, int>>> borders;
  int minDist = 200;
  // 섬 이랑 섬 경계 찾고
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (map[r][c] && !visited[r][c]) {
        set<pair<int, int>> s;
        queue<pair<int, int>> q;
        q.push(make_pair(r, c));
        visited[r][c] = true;
        while (!q.empty()) {
          int r = q.front().first;
          int c = q.front().second;
          q.pop();
          for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 > nr || nr >= N || 0 > nc || nc >= N) continue;
            if (map[nr][nc] == 0) {
              s.insert(make_pair(r, c));
            }
            if (map[nr][nc] && !visited[nr][nc]) {
              visited[nr][nc] = true;
              q.push(make_pair(nr, nc));
            }
          }
        }
        borders.push_back(s);
      }
    }
  }
  // 각 섬 경계마다 가장 짧은 거리 찾고
  while (!borders.empty()) {
    set<pair<int, int>> s1 = borders.back();
    for (int i = 0; i < (int)borders.size() - 1; i++) {
      set<pair<int, int>> s2 = borders[i];
      for (pair<int, int> p1 : s1) {
        for (pair<int, int> p2 : s2) {
          if (abs(p1.first - p2.first) > minDist) continue;
          if (abs(p1.second - p2.second) > minDist) continue;
          int distance = dist(p1, p2);
          if (minDist > distance) minDist = distance;
        }
      }
    }
    borders.pop_back();
  }
  return minDist;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) cin >> map[r][c];
  }
  cout << bfs();
  return 0;
}
