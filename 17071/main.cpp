#include <memory.h>
#include <iostream>
#include <queue>

using namespace std;

int N, K;
int visited[500001][2];

void bfs() {
  memset(visited, -1, sizeof(visited));
  queue<pair<int, int>> q;
  q.push({N, 0});
  visited[N][0] = 0;
  while (!q.empty()) {
    int curN = q.front().first;
    int cnt = q.front().second;
    q.pop();
    bool flag = cnt % 2;
    for (int nextN : {curN + 1, curN - 1, curN * 2}) {
      if (0 > nextN || nextN > 500000 || visited[nextN][1 - flag] != -1)
        continue;
      visited[nextN][1 - flag] = cnt + 1;
      q.push({nextN, cnt + 1});
    }
  }
  int time = 0;
  int flag = 0;
  int ans = -1;
  while (K <= 500000) {
    if (visited[K][flag] != -1) {
      if (visited[K][flag] <= time) {
        ans = time;
        break;
      }
    }
    flag = 1 - flag;
    time++;
    K += time;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  bfs();
  return 0;
}
