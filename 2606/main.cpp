#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;  // 컴퓨터의 수
  int INF = 10001;
  cin >> N;
  int com[101][101];
  // 모든 컴퓨터의 연결을 INF로 초기화
  for (int v = 1; v <= N; v++) {
    for (int w = 1; w <= N; w++) {
      com[v][w] = INF;
    }
  }
  int test_case;
  cin >> test_case;
  // 연결이 있으면, 1로 초기화
  while (test_case--) {
    int v, w;
    cin >> v >> w;
    com[v][w] = 1;
    com[w][v] = 1;
  }
  // 자기자신과의 연결은 0으로 초기화
  for (int v = 1; v <= N; v++) com[v][v] = 0;
  // Floyd–Warshall algorithm
  for (int k = 1; k <= N; k++) {
    for (int v = 1; v <= N; v++) {
      for (int w = 1; w <= N; w++) {
        if (com[v][w] > com[v][k] + com[k][w])
          com[v][w] = com[v][k] + com[k][w];
      }
    }
  }
  int cnt = 0;  // 1번 컴퓨터와 연결된 컴퓨터의 개수
  for (int v = 2; v <= N; v++) {
    // INF 의 값은 연결되지 않은 컴퓨터를 의미하므로,
    // 그걸 제외하고 개수를 카운트
    if (com[1][v] != INF) cnt++;
  }
  cout << cnt << "\n";
  return 0;
}
