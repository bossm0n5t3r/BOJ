#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
int floors[1000001];
bool visited[1000001];

int bfs() {
  queue<int> q;
  q.push(S);
  visited[S] = true;
  while (!q.empty()) {
    int cur = q.front();
    if (cur == G) return floors[cur];
    q.pop();
    if (U && cur + U <= F && !visited[cur + U]) {
      visited[cur + U] = true;
      floors[cur + U] = floors[cur] + 1;
      q.push(cur + U);
    }
    if (D && cur - D >= 0 && !visited[cur - D]) {
      visited[cur - D] = true;
      floors[cur - D] = floors[cur] + 1;
      q.push(cur - D);
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> F >> S >> G >> U >> D;
  int ans = bfs();
  if (ans == -1)
    cout << "use the stairs\n";
  else
    cout << ans << "\n";
  return 0;
}
