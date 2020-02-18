#include <memory.h>

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, max_cnt;
int cnt[10001];
bool visited[10001];
vector<int> graph[10001];

void bfs(int v) {
  if (graph[v].empty()) return;
  memset(visited, 0, N + 1);
  queue<int> q;
  q.push(v);
  visited[v] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    cnt[v]++;
    if (!graph[cur].empty()) {
      for (int w : graph[cur]) {
        if (!visited[w]) {
          visited[w] = true;
          q.push(w);
        }
      }
    }
  }
  if (cnt[v] > max_cnt) max_cnt = cnt[v];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  int v, w;
  while (M--) {
    cin >> v >> w;
    graph[w].push_back(v);
  }
  for (int v = 1; v <= N; v++) bfs(v);
  for (int v = 1; v <= N; v++) {
    if (cnt[v] == max_cnt) cout << v << " ";
  }
  cout << "\n";
  return 0;
}
