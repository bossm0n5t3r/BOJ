#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int rooms[101][101];
bool visited[101][101];
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
vector<vector<int>> v;

int coord2idx(int r, int c) { return (r - 1) * N + (c - 1); }
pair<int, int> idx2coord(int idx) { return {(idx / N) + 1, (idx % N) + 1}; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  vector<int> tmp;
  for (int i = 0; i < N * N; i++) v.push_back(tmp);
  int x, y, a, b;
  while (M--) {
    cin >> x >> y >> a >> b;
    int from = coord2idx(x, y);
    int to = coord2idx(a, b);
    v[from].push_back(to);
  }
  return 0;
}

/*
5 25
5 3 4 3
1 1 1 3
1 3 2 2
4 2 4 3
1 1 1 2
1 4 3 5
5 1 3 1
5 3 5 2
4 3 4 5
5 4 3 1
5 4 3 4
3 4 5 4
3 3 4 3
3 3 1 5
1 2 2 1
4 5 3 1
1 4 3 3
4 5 1 3
2 1 5 1
3 5 5 1
2 1 1 4
4 3 5 4
1 3 2 3
3 3 5 2
1 2 3 1
*/