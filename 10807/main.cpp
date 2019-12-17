#include <cstdio>

using namespace std;

int main() {
  int N, arr[101], v, cnt = 0;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
  scanf("%d", &v);
  for (int i = 1; i <= N; i++) {
    cnt += (v == arr[i]);
  }
  printf("%d", cnt);
  return 0;
}
