#include <cstdio>

using namespace std;

int main() {
  char p[100001];
  int cnt = 0, stack = 0;
  scanf("%s", p);
  for (int i = 0; p[i]; i++) {
    if (p[i] == '(')
      stack++;
    else {
      stack--;
      if (p[i - 1] == '(')
        cnt += stack;
      else
        cnt++;
    }
  }
  printf("%d", cnt);
  return 0;
}
