#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, root_node, delete_node, leaf_node;
vector<int> g[51];
bool visited[51];

void bfs() {
  queue<int> q;
  q.push(root_node);
  visited[root_node] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    int child_cnt = 0;
    for (int child : g[cur]) {
      if (!visited[child]) {
        visited[child] = true;
        q.push(child);
        child_cnt++;
      }
    }
    if (child_cnt == 0) leaf_node++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  int tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    if (tmp == -1)
      root_node = i;
    else {
      // parent : tmp
      // child : i
      g[tmp].push_back(i);
    }
  }
  cin >> delete_node;
  visited[delete_node] = true;
  if (!visited[root_node]) bfs();
  cout << leaf_node << "\n";
  return 0;
}
