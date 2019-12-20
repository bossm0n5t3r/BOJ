#include <cstdio>

using namespace std;

int arr[7][2];
int N, K, S, Y, cnt;

int main() {
  scanf("%d %d", &N, &K);
  while (N--) {
    scanf("%d %d", &S, &Y);
    arr[Y][S]++;
  }
  for (int i = 1; i <= 6; i++) {
    if (arr[i][0]) cnt += (arr[i][0] - 1) / K + 1;
    if (arr[i][1]) cnt += (arr[i][1] - 1) / K + 1;
  }
  printf("%d", cnt);
  return 0;
}
