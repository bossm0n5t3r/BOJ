#include <cstdio>

using namespace std;

int main()
{
  int i, j, arr[5], sum = 0, mean = 0, mid = 0;
  for (i = 0; i < 5; i++)
  {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }
  for (i = 0; i < 4; i++)
  {
    for (j = i + 1; j < 5; j++)
    {
      if (arr[i] > arr[j])
        arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
    }
  }
  mean = sum / 5;
  mid = arr[2];
  printf("%d\n%d", mean, mid);
  return 0;
}
