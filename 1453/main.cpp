#include <iostream>

using namespace std;

bool seated[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, tmp, rejected = 0;
  cin >> N;
  while (N--) {
    cin >> tmp;
    if (seated[tmp])
      rejected++;
    else
      seated[tmp] = true;
  }
  cout << rejected << "\n";
  return 0;
}
