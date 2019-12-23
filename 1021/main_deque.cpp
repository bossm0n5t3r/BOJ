#include <cstdio>
#include <deque>

using namespace std;

int main() {
  int N, M, X, left, right, pos = -1, cnt = 0, tmp;
  deque<int> d;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) d.push_back(i + 1);
  while (M--) {
    scanf("%d", &X);
    for (int i = 0; i < (int)d.size(); i++) {
      if (d[i] == X) {
        pos = i;
        break;
      }
    }
    left = pos;
    right = d.size() - pos;
    if (left < right) {
      cnt += left;
      while (left--) {
        tmp = d.front();
        d.pop_front();
        d.push_back(tmp);
      }
      d.pop_front();
    } else {
      cnt += right;
      while (right--) {
        tmp = d.back();
        d.pop_back();
        d.push_front(tmp);
      }
      d.pop_front();
    }
  }
  printf("%d\n", cnt);
  return 0;
}
