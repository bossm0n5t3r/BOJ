#include <iostream>
#include <queue>

using namespace std;

int N, K;
int second[100001];
bool visited[100001];

void bfs() {
  queue<int> q;
  q.push(N);
  visited[N] = true;
  while (!q.empty()) {
    int cur = q.front();
    if (cur == K) {
      cout << second[cur] << "\n";
      return;
    }
    q.pop();
    if (cur * 2 <= 100000 && !visited[cur * 2]) {
      visited[cur * 2] = true;
      second[cur * 2] = second[cur];
      q.push(cur * 2);
    }
    if (cur - 1 >= 0 && !visited[cur - 1]) {
      visited[cur - 1] = true;
      second[cur - 1] = second[cur] + 1;
      q.push(cur - 1);
    }
    if (cur + 1 <= 100000 && !visited[cur + 1]) {
      visited[cur + 1] = true;
      second[cur + 1] = second[cur] + 1;
      q.push(cur + 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  bfs();
  return 0;
}
