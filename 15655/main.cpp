#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int input[10];
int arr[10];

void dfs(int depth, int start) {
  if (depth == M) {
    for (int i = 0; i < M; i++) cout << arr[i] << " ";
    cout << "\n";
    return;
  }
  for (int i = start; i < N; i++) {
    arr[depth] = input[i];
    dfs(depth + 1, i + 1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> input[i];
  sort(input, input + N);
  for (int i = 0; i < 2 * M; i++) arr[i] = ' ';
  dfs(0, 0);
  return 0;
}
