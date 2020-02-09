#include <cstdio>

using namespace std;

char arr[30];
int length, sum;

bool isWrong() {
  int s = 0, b = 0;
  for (int i = 0; i < length; i++) {
    if (arr[i] == '(') s++;
    if (arr[i] == ')') s--;
    if (arr[i] == '[') b++;
    if (arr[i] == ']') b--;
    if (s < 0 || b < 0) return true;
  }
  if (s != 0 || b != 0)
    return true;
  else
    return false;
}

int main() {
  int tmp = 1;
  scanf("%s", arr);
  for (int i = 0; arr[i]; i++) length++;
  if (isWrong()) {
    printf("0");
    return 0;
  }
  for (int i = 0; i < length; i++) {
    if (arr[i] == '(') tmp *= 2;
    if (arr[i] == '[') tmp *= 3;
    if (arr[i] == ')') {
      if (arr[i - 1] == '(') sum += tmp;
      tmp /= 2;
    }
    if (arr[i] == ']') {
      if (arr[i - 1] == '[') sum += tmp;
      tmp /= 3;
    }
  }
  printf("%d", sum);
  return 0;
}

// A solution that I've solved on my own.

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// void solve(string arr) {
//   int max = (int)arr.length() + 1;
//   vector<char> stack;
//   vector<int> v[max];
//   int level = 0;
//   for (int i = 0; i < (int)arr.length(); i++) {
//     char c = arr[i];
//     if (c == '(' || c == '[') {
//       level++;
//       stack.push_back(c);
//     } else {
//       level--;
//       if (level < 0) {
//         cout << 0 << "\n";
//         return;
//       }
//       if (c == ')') {
//         if (stack.back() != '(') {
//           cout << 0 << "\n";
//           return;
//         }
//         stack.pop_back();
//         if (!v[level + 1].empty()) {
//           int sum = 0;
//           while (!v[level + 1].empty()) {
//             sum += v[level + 1].back();
//             v[level + 1].pop_back();
//           }
//           sum *= 2;
//           v[level].push_back(sum);
//         } else {
//           v[level].push_back(2);
//         }
//       } else {
//         if (stack.back() != '[') {
//           cout << 0 << "\n";
//           return;
//         }
//         stack.pop_back();
//         if (!v[level + 1].empty()) {
//           int sum = 0;
//           while (!v[level + 1].empty()) {
//             sum += v[level + 1].back();
//             v[level + 1].pop_back();
//           }
//           sum *= 3;
//           v[level].push_back(sum);
//         } else {
//           v[level].push_back(3);
//         }
//       }
//     }
//   }
//   if (!stack.empty()) {
//     cout << 0 << "\n";
//     return;
//   }
//   int sum = 0;
//   while (!v[0].empty()) {
//     sum += v[0].back();
//     v[0].pop_back();
//   }
//   cout << sum << "\n";
// }

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   string arr;
//   cin >> arr;
//   solve(arr);
// }
