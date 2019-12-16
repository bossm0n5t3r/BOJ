#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int N, M;
int input[10];

void dfs(int depth, string s) {
  if (depth == M) {
    cout << s << "\n";
    return;
  }
  for (int i = 0; i < N; i++) {
    dfs(depth + 1, s + to_string(input[i]) + " ");
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> input[i];
  sort(input, input + N);
  dfs(0, "");
  return 0;
}
