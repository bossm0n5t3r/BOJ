#include <cstdio>

using namespace std;

int main()
{
  int T, A, B;
  scanf("%d", &T);
  while (T-- > 0)
  {
    scanf("%1d %*c %1d", &A, &B);
    printf("%d\n", A + B);
  }
  return 0;
}
