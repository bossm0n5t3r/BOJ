#include <cstdio>

using namespace std;

int main() {
  int N, arr[201] = {0}, v, tmp;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &tmp);
    arr[100 + tmp]++;
  }
  scanf("%d", &v);
  printf("%d", arr[100 + v]);
  return 0;
}
