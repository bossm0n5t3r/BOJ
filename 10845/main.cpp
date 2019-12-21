#include <cstdio>

using namespace std;

typedef struct QUEUE {
  int q[10001] = {0};
  int s = 0, e = -1;

  void push(int X) { q[++e] = X; }
  void pop() {
    if (e >= s) {
      printf("%d\n", q[s]);
      q[s++] = 0;
    } else
      printf("-1\n");
  }
  void size() { printf("%d\n", e - s + 1); }
  void empty() {
    if (e >= s)
      printf("0\n");
    else
      printf("1\n");
  }
  void front() {
    if (e >= s)
      printf("%d\n", q[s]);
    else
      printf("-1\n");
  }
  void back() {
    if (e >= s)
      printf("%d\n", q[e]);
    else
      printf("-1\n");
  }
} QUEUE;

int main() {
  int N, X;
  QUEUE q;
  char cmd[7];
  scanf("%d", &N);
  while (N--) {
    scanf("%s", cmd);
    if (cmd[0] == 'p' && cmd[1] == 'u') {
      scanf("%d", &X);
      q.push(X);
    } else if (cmd[0] == 'p' && cmd[1] == 'o')
      q.pop();
    else if (cmd[0] == 's')
      q.size();
    else if (cmd[0] == 'e')
      q.empty();
    else if (cmd[0] == 'f')
      q.front();
    else if (cmd[0] == 'b')
      q.back();
  }
  return 0;
}
