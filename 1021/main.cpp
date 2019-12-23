#include <cstdio>

using namespace std;

int check[51];

int main() {
  int N, M, target, idx, cnt = 0, cur = 0;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < M; i++) {
    scanf("%d", &target);
    target--;
    idx = 0;
    while (cur != target) {
      if (check[cur] == 0) idx++;
      cur = (cur + 1) % N;
    }
    if (N - i - idx > idx)
      cnt += idx;
    else
      cnt += N - i - idx;
    check[cur] = 1;
  }
  printf("%d", cnt);
  return 0;
}
