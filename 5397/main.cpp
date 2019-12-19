#include <deque>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  string input;
  cin >> T;
  while (T--) {
    cin >> input;
    deque<char> L;
    deque<char> R;
    for (char &c : input) {
      if (c == '<') {
        if (L.empty()) continue;
        R.push_back(L.back());
        L.pop_back();
      } else if (c == '>') {
        if (R.empty()) continue;
        L.push_back(R.back());
        R.pop_back();
      } else if (c == '-') {
        if (L.empty()) continue;
        L.pop_back();
      } else {
        L.push_back(c);
      }
    }
    string front(L.begin(), L.end());
    string back(R.rbegin(), R.rend());
    cout << front << back << '\n';
  }
  return 0;
}
