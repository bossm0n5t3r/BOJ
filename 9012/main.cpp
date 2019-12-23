#include <cstdio>

using namespace std;

int main() {
  int T, cnt;
  bool flag;
  scanf("%d", &T);
  while (T--) {
    cnt = 0;
    flag = 0;
    char s[50];
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
      if (s[i] == '(')
        cnt++;
      else
        cnt--;
      if (cnt < 0) flag = 1;
    }
    if (flag || cnt != 0)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
