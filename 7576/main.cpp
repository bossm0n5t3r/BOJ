#include <iostream>
#include <queue>

using namespace std;

int box[1001][1001];
int date[1001][1001];
bool visited[1001][1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int M, N, check = 0, max_date = 0;
  queue<pair<int, int>> q;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> box[i][j];
      if (box[i][j] == 1) q.push(make_pair(i, j));
      if (box[i][j] == 0)
        check++;
      else
        visited[i][j] = true;
    }
  }
  if (check == 0)
    cout << 0 << "\n";
  else {
    while (!q.empty()) {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < M && 0 <= ny && ny < N && box[nx][ny] == 0 &&
            !visited[nx][ny]) {
          visited[nx][ny] = true;
          date[nx][ny] = date[x][y] + 1;
          if (date[nx][ny] > max_date) max_date = date[nx][ny];
          q.push(make_pair(nx, ny));
        }
      }
    }
    bool notVisited = false;
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (!visited[i][j] && box[i][j] == 0) {
          notVisited = true;
          break;
        }
      }
    }
    if (notVisited)
      cout << -1 << "\n";
    else
      cout << max_date << "\n";
  }
  return 0;
}
