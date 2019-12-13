#include <cstdio>

using namespace std;

int main()
{
  int i, input, sum = 0, min = 101;
  for (i = 1; i <= 7; i++)
  {
    scanf("%d", &input);
    if (input % 2)
    {
      sum += input;
      if (min > input)
        min = input;
    }
  }
  if (!sum)
    printf("-1");
  else
    printf("%d\n%d", sum, min);
  return 0;
}
