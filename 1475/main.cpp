#include <cstdio>

using namespace std;

int main() {
  int N, freq[10] = {0}, set = 0, i = 0;
  while (scanf("%1d", &N) == 1) freq[N]++;
  freq[6] = (freq[6] + freq[9] + 1) / 2;
  while (i <= 8)
    if (set < freq[i++]) set = freq[i - 1];
  printf("%d", set);
  return 0;
}
