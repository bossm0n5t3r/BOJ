#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  int length;
  string input;
  cin >> T;
  while (T--) {
    cin >> input;
    length = input.length();
    list<char> l;
    list<char>::iterator it;
    it = l.begin();
    for (int i = 0; i < length; i++) {
      if (input[i] == '-') {
        if (it != l.begin()) it = l.erase(--it);
      } else if (input[i] == '<') {
        if (it != l.begin()) it--;
      } else if (input[i] == '>') {
        if (it != l.end()) it++;
      } else {
        l.insert(it, input[i]);
      }
    }
    for (it = l.begin(); it != l.end(); it++) cout << *it;
    cout << "\n";
  }
  return 0;
}
