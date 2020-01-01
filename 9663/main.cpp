#include <cstdio>

using namespace std;

int N, result;
int col[15];

int abs(int x) {
  if (x < 0) return -x;
  return x;
}

bool isSafe(int i) {
  for (int j = 0; j < i; j++) {
    if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j)) return false;
  }
  return true;
}

void dfs(int i) {
  if (i >= N)
    result++;
  else {
    for (int j = 0; j < N; j++) {
      col[i] = j;
      if (isSafe(i)) dfs(i + 1);
    }
  }
}

int main() {
  scanf("%d", &N);
  dfs(0);
  printf("%d\n", result);
  return 0;
}
