#include <cstdio>
#include <queue>

using namespace std;

int N, K;
bool visited[100001];

void bfs() {
  int cnt = 0, minSec = 0;
  queue<pair<int, int>> q;
  q.push(make_pair(N, 0));
  while (!q.empty()) {
    int cur = q.front().first;
    int sec = q.front().second;
    q.pop();
    visited[cur] = true;
    if (minSec && minSec == sec && cur == K) cnt++;
    if (!minSec && cur == K) {
      minSec = sec;
      cnt++;
    }
    if (cur + 1 <= 100000 && !visited[cur + 1])
      q.push(make_pair(cur + 1, sec + 1));
    if (cur - 1 >= 0 && !visited[cur - 1]) q.push(make_pair(cur - 1, sec + 1));
    if (cur * 2 <= 100000 && !visited[cur * 2])
      q.push(make_pair(cur * 2, sec + 1));
  }
  printf("%d\n%d\n", minSec, cnt);
}

int main() {
  scanf("%d %d", &N, &K);
  bfs();
  return 0;
}
