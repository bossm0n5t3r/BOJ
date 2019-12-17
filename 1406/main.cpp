#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  list<char> editor;
  list<char>::iterator cursor;
  string input;
  int N;
  char command, element;
  cin >> input;
  for (char c : input) editor.push_back(c);
  cursor = editor.end();
  cin >> N;
  while (N--) {
    cin >> command;
    if (command == 'P') cin >> element;
    if (command == 'L') {
      if (cursor != editor.begin()) cursor--;
    } else if (command == 'D') {
      if (cursor != editor.end()) cursor++;
    } else if (command == 'B') {
      if (cursor != editor.begin()) {
        cursor--;
        cursor = editor.erase(cursor);
      };
    } else if (command == 'P')
      editor.insert(cursor, element);
  }
  for (cursor = editor.begin(); cursor != editor.end(); cursor++)
    cout << *cursor;
  return 0;
}
