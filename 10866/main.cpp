#include <cstdio>

using namespace std;

typedef struct DEQUE {
  int d[30000] = {0};
  int s = 15001, e = 15000;

  void push_front(int X) { d[--s] = X; }
  void push_back(int X) { d[++e] = X; }
  void pop_front() {
    if (e >= s) {
      printf("%d\n", d[s]);
      d[s++] = 0;
    } else
      printf("-1\n");
  }
  void pop_back() {
    if (e >= s) {
      printf("%d\n", d[e]);
      d[e--] = 0;
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
      printf("%d\n", d[s]);
    else
      printf("-1\n");
  }
  void back() {
    if (e >= s)
      printf("%d\n", d[e]);
    else
      printf("-1\n");
  }
} DEQUE;

int main() {
  int N, X;
  DEQUE d;
  char cmd[10];
  scanf("%d", &N);
  while (N--) {
    scanf("%s", cmd);
    if (cmd[0] == 's')
      d.size();
    else if (cmd[0] == 'e')
      d.empty();
    else if (cmd[0] == 'f')
      d.front();
    else if (cmd[0] == 'b')
      d.back();
    else if (cmd[4] == 'f')
      d.pop_front();
    else if (cmd[4] == 'b')
      d.pop_back();
    else if (cmd[5] == 'f') {
      scanf("%d", &X);
      d.push_front(X);
    } else if (cmd[5] == 'b') {
      scanf("%d", &X);
      d.push_back(X);
    }
  }
  return 0;
}
