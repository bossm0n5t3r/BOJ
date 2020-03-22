#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[12];  // 수열

int MAX = -1e9;
int MIN = 1e9;

void dfs(vector<int> ops) {
  int cur = arr[1];
  for (int i = 1; i < N; i++) {
    int op = ops[i - 1];
    if (op == 0) {
      cur += arr[i + 1];
    } else if (op == 1) {
      cur -= arr[i + 1];
    } else if (op == 2) {
      cur *= arr[i + 1];
    } else if (op == 3 && cur < 0) {
      int tmp = (-cur) / arr[i + 1];
      cur = -tmp;
    } else if (op == 3) {
      cur /= arr[i + 1];
    }
  }
  if (MAX < cur) MAX = cur;
  if (MIN > cur) MIN = cur;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tmp;
  vector<int> ops;  // 사칙연산 (+ : 0, - : 1, * : 2, / : 3)
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> arr[i];
  for (int i = 0; i < 4; i++) {
    cin >> tmp;
    while (tmp--) ops.push_back(i);
  }
  do {
    dfs(ops);
  } while (next_permutation(ops.begin(), ops.end()));
  cout << MAX << "\n" << MIN << "\n";
  return 0;
}
