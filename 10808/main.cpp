#include <cstdio>

using namespace std;

int main() {
  int idx = 0, cnt[26] = {0};
  char word[101];
  scanf("%s", &word);
  while (word[idx]) cnt[word[idx++] - 'a']++;
  for (int i = 0; i < 26; i++) printf("%d ", cnt[i]);
  return 0;
}
