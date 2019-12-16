#include <cstdio>

using namespace std;

int N, M;
int arr[10];

void dfs(int depth, int start) {
  if (depth == M) {
    for (int i = 0; i < M; i++) printf("%d ", arr[i]);
    printf("\n");
    return;
  }
  for (int i = start; i <= N; i++) {
    arr[depth] = i;
    dfs(depth + 1, i + 1);
  }
}

int main() {
  scanf("%d %d", &N, &M);
  dfs(0, 1);
  return 0;
}
