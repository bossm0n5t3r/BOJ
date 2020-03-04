#include <iostream>

using namespace std;

int A[1000001];
int B[1000001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) cin >> B[i];
  int aIdx = 0, bIdx = 0;
  while (aIdx < N || bIdx < M) {
    if (aIdx == N) {
      while (bIdx < M) cout << B[bIdx++] << " ";
      cout << "\n";
      break;
    }
    if (bIdx == M) {
      while (aIdx < N) cout << A[aIdx++] << " ";
      cout << "\n";
      break;
    }
    if (A[aIdx] <= B[bIdx]) {
      cout << A[aIdx++] << " ";
    } else {
      cout << B[bIdx++] << " ";
    }
  }
  return 0;
}
