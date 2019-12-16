#include <iostream>

using namespace std;

int N, M;
char arr[20];

void dfs(int depth) {
  if (depth == M) {
    cout << arr << '\n';
    return;
  }
  for (int i = 0; i < N; i++) {
    arr[depth * 2] = i + '1';
    dfs(depth + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < 2 * M; i++) arr[i] = ' ';
  dfs(0);
  return 0;
}
