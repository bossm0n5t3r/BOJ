#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int N, M;
int input[10];
int arr[10];
bool visited[20];
unordered_set<string> set;

void dfs(int depth, string s) {
  if (depth == M) {
    if (!set.count(s)) {
      set.insert(s);
      cout << s << "\n";
    }
    return;
  }
  for (int i = 0; i < N; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    dfs(depth + 1, s + to_string(input[i]) + " ");
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
  dfs(0, "");
  return 0;
}
