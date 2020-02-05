#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  queue<int> q;
  cin >> N;
  for (int i = 1; i <= N; i++) q.push(i);
  while ((int)q.size() > 1) {
    q.pop();
    if ((int)q.size() == 1) break;
    q.push(q.front());
    q.pop();
  }
  cout << q.front() << "\n";
  return 0;
}
