#include <iostream>

using namespace std;

int N, numOfStudents, studentCode, num;
int switchs[101];

void change(int studentCode, int num) {
  if (studentCode == 1) {
    for (int i = 1; i <= N / num; i++) switchs[num * i] = 1 - switchs[num * i];
  } else {
    int start = num;
    int end = num;
    while (true) {
      if (switchs[start] != switchs[end]) {
        start++;
        end--;
        break;
      }
      if (start <= 1 || end >= N) break;
      start--;
      end++;
    }
    for (int i = start; i <= end; i++) switchs[i] = 1 - switchs[i];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> switchs[i];
  cin >> numOfStudents;
  while (numOfStudents--) {
    cin >> studentCode >> num;
    change(studentCode, num);
  }
  for (int i = 1; i <= N; i++) {
    cout << switchs[i] << " ";
    if (i % 20 == 0) cout << "\n";
  }
  return 0;
}
