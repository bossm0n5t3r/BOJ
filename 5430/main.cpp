#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T, n, i = 0;
  string p, x;
  bool reverse, error;
  cin >> T;
  while (T--) {
    deque<int> d;
    reverse = false;
    error = false;
    cin >> p >> n >> x;
    for (char c : x) {
      if (c >= '0' && c <= '9')
        i = i * 10 + (c - '0');
      else {
        if (i) d.push_back(i);
        i = 0;
      }
    }
    for (char c : p) {
      if (c == 'R')
        reverse = !reverse;
      else if (d.empty()) {
        error = true;
        break;
      } else {
        --n;
        reverse ? d.pop_back() : d.pop_front();
      }
    }
    if (error)
      cout << "error\n";
    else {
      cout << '[';
      if (n) {
        while (true) {
          if (reverse) {
            cout << d.back();
            d.pop_back();
          } else {
            cout << d.front();
            d.pop_front();
          }
          if (--n == 0) break;
          cout << ',';
        }
      }
      cout << "]\n";
    }
  }
  return 0;
}
