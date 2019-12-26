#include <cmath>
#include <cstdio>

using namespace std;

int main() {
  long long N, x1, y1, x2, y2, x3, y3, area = 0;
  scanf("%lld", &N);
  scanf("%lld %lld %lld %lld", &x1, &y1, &x3, &y3);
  for (int i = 2; i < N; i++) {
    x2 = x3, y2 = y3;
    scanf("%lld %lld", &x3, &y3);
    area += (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
  }
  printf("%.1lf", fabs(area) / 2);
  return 0;
}
