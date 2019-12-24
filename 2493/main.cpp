#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> arr = vector<int>(N);
  vector<int> ans = vector<int>(N, 0);
  stack<int> s;
  for (int i = 0; i < N; i++) cin >> arr[i];
  for (int i = (int)arr.size() - 1; i >= 0; i--) {
    while (!s.empty() && arr[s.top()] < arr[i]) {
      ans[s.top()] = i + 1;
      s.pop();
    }
    s.push(i);
  }
  for (int top : ans) cout << top << " ";
  return 0;
}
