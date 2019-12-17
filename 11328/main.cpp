#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  string s1, s2;
  cin >> N;
  while (N--) {
    cin >> s1 >> s2;
    if (s1.length() != s2.length()) {
      cout << "Impossible\n";
      continue;
    }
    int freq[26] = {0};
    for (int i = 0; i < (int)s1.length(); i++) {
      freq[s1[i] - 'a']++;
      freq[s2[i] - 'a']--;
    }
    bool notStrfry = false;
    for (int i = 0; i < 26; i++) {
      if (freq[i] != 0) {
        notStrfry = true;
        break;
      }
    }
    if (notStrfry)
      cout << "Impossible\n";
    else
      cout << "Possible\n";
  }
  return 0;
}
