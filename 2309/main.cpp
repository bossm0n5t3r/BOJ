#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int i, j, k, l, dwarfs[9], ans[7], sum = 0, m = 0;
  for (i = 0; i < 9; i++)
    scanf("%d", &dwarfs[i]);
  for (i = 0; i < 9; i++)
  {
    for (j = i + 1; j < 9; j++)
    {
      for (k = 0; k < 9; k++)
      {
        if (k != i && k != j)
        {
          sum += dwarfs[k];
          ans[m++] = dwarfs[k];
        }
      }
      if (sum == 100)
      {
        sort(ans, ans + m);
        for (l = 0; l < m; l++)
          printf("%d\n", ans[l]);
        return 0;
      }
      sum = 0;
      m = 0;
    }
  }
  return 0;
}
