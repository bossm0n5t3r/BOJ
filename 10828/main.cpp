#include <cstdio>

using namespace std;

typedef struct STACK {
  int s[10001] = {0};
  int i = 0;

  void push(int X) { s[++i] = X; }
  void pop() {
    if (i) {
      printf("%d\n", s[i]);
      s[i--] = 0;
    } else
      printf("-1\n");
  }
  void size() { printf("%d\n", i); }
  void empty() {
    if (i)
      printf("0\n");
    else
      printf("1\n");
  }
  void top() {
    if (i)
      printf("%d\n", s[i]);
    else
      printf("-1\n");
  }
} STACK;

int main() {
  int N, X;
  STACK s;
  char cmd[7];
  scanf("%d", &N);
  while (N--) {
    scanf("%s", cmd);
    if (cmd[0] == 'p' && cmd[1] == 'u') {
      scanf("%d", &X);
      s.push(X);
    } else if (cmd[0] == 'p' && cmd[1] == 'o')
      s.pop();
    else if (cmd[0] == 's')
      s.size();
    else if (cmd[0] == 'e')
      s.empty();
    else if (cmd[0] == 't')
      s.top();
  }
  return 0;
}
