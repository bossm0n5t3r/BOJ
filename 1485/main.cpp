#include <algorithm>
#include <cstdio>

using namespace std;

int T, p[4][2];
long long d[6];

int main() {
  scanf("%d", &T);
  while (T--) {
    for (int i = 0; i < 4; i++) scanf("%d %d", &p[i][0], &p[i][1]);
    int idx = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = i + 1; j < 4; j++)
        d[idx++] = (p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) +
                   (p[i][1] - p[j][1]) * (p[i][1] - p[j][1]);
    }
    sort(d, d + 6);
    printf("%d\n",
           d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5]);
  }
  return 0;
}
