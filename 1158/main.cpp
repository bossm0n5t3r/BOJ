#include <iostream>
#include <list>

using namespace std;

void josephus(int N, int K) {
  cout << "<";
  list<int> survivors;
  for (int i = 1; i <= N; i++) survivors.push_back(i);
  list<int>::iterator kill = survivors.begin();
  for (int i = 1; i < K; i++) kill++;
  while (N > 1) {
    N--;
    cout << *kill << ", ";
    kill = survivors.erase(kill);
    if (kill == survivors.end()) kill = survivors.begin();
    for (int i = 0; i < K - 1; i++) {
      kill++;
      if (kill == survivors.end()) kill = survivors.begin();
    }
    if (N <= 1) break;
  }
  cout << *kill << ">\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  josephus(N, K);
  return 0;
}
