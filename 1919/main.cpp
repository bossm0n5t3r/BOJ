#include <cstdio>
#include <string>

using namespace std;

char c1[1001];
char c2[1001];

int main() {
  int freq[26] = {0}, cnt = 0;
  scanf("%s%s", c1, c2);
  for (char c : c1) freq[c - 'a']++;
  for (char c : c2) freq[c - 'a']--;
  for (int n : freq) {
    if (n != 0) cnt += abs(n);
  }
  printf("%d\n", cnt);
  return 0;
}
