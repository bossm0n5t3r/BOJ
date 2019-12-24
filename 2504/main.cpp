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
