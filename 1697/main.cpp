#include <cstdio>
#include <queue>

using namespace std;

int main() {
  int N, K, cnt = -1;
  bool visited[100001] = {0};
  scanf("%d %d", &N, &K);
  queue<int> q;
  q.push(N);
  visited[N] = true;
  while (int s = (int)q.size()) {
    cnt++;
    while (s--) {
      int cur = q.front();
      q.pop();
      if (cur == K) {
        printf("%d\n", cnt);
        return 0;
      };
      if (cur - 1 >= 0 && !visited[cur - 1]) {
        visited[cur - 1] = true;
        q.push(cur - 1);
      }
      if (cur + 1 <= 100000 && !visited[cur + 1]) {
        visited[cur + 1] = true;
        q.push(cur + 1);
      }
      if (cur * 2 <= 100000 && !visited[cur * 2]) {
        visited[cur * 2] = true;
        q.push(cur * 2);
      }
    }
  }
  return 0;
}
