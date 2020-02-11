#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, K, tmp, partial = 0, max = -10000001;
  cin >> N >> K;
  vector<int> data;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    data.push_back(tmp);
    if (i < K) partial += tmp;
  }
  if (partial > max) max = partial;
  for (int i = K; i < N; i++) {
    partial -= data[i - K];
    partial += data[i];
    if (partial > max) max = partial;
  }
  cout << max << "\n";
  return 0;
}
