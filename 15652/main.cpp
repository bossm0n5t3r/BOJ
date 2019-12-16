#include <cstdio>

using namespace std;

int N, M;
char arr[20];

void dfs(int depth, int start) {
  if (depth == M) {
    printf("%s\n", arr);
    return;
  }
  for (int i = start; i <= N; i++) {
    arr[depth * 2] = i + '0';
    dfs(depth + 1, i);
  }
}

int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < 2 * M; i++) arr[i] = ' ';
  dfs(0, 1);
  return 0;
}
