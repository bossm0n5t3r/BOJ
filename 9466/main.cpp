#include <iostream>
#include <vector>

using namespace std;

int cnt;
int arr[100001];
bool visited[100001];
bool done[100001];

void dfs(int cur) {
  visited[cur] = true;
  int next = arr[cur];
  if (!visited[next])
    dfs(next);
  else if (!done[next]) {
    for (int i = next; i != cur; i = arr[i]) cnt++;
    cnt++;
  }
  done[cur] = true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> arr[i];
      visited[i] = false;
      done[i] = false;
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) dfs(i);
    }
    cout << n - cnt << "\n";
  }
  return 0;
}
