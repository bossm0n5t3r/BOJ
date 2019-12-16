#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int input[10];
int arr[10];
bool visited[20];

void dfs(int depth) {
  if (depth == M) {
    for (int i = 0; i < M; i++) cout << arr[i] << " ";
    cout << "\n";
    return;
  }
  for (int i = 0; i < N; i++) {
    if (visited[i]) continue;
    arr[depth] = input[i];
    visited[i] = true;
    dfs(depth + 1);
    visited[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> input[i];
  sort(input, input + N);
  for (int i = 0; i < 2 * M; i++) arr[i] = ' ';
  dfs(0);
  return 0;
}
