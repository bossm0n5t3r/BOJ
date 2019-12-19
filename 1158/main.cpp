#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int N, K, X;
  vector<int> v;
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; i++) v.push_back(i);
  X = K - 1;
  printf("<");
  while (N-- > 1) {
    printf("%d, ", *(v.begin() + X));
    v.erase(v.begin() + X);
    X = (X + K - 1) % N;
  }
  printf("%d>", *v.begin());
  return 0;
}
