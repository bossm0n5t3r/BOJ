#include <iostream>
#include <vector>

using namespace std;

int N, minDiff;
int status[21][21];
vector<vector<int>> v;

int min(int a, int b) {
  if (a > b) return b;
  return a;
}

int abs(int a) {
  if (a < 0) return -a;
  return a;
}

void comb(int arr[], vector<int> data, int start, int end, int index, int r) {
  if (index == r) {
    v.push_back(data);
    return;
  }
  for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
    data[index] = arr[i];
    comb(arr, data, i + 1, end, index + 1, r);
  }
}

void generateComb(int arr[], int n, int r) {
  vector<int> data;
  for (int i = 0; i < n / 2; i++) data.push_back(0);
  comb(arr, data, 0, n - 1, 0, r);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= N; c++) {
      cin >> status[r][c];
      minDiff += status[r][c];
    }
  }
  int arr[N] = {0};
  for (int i = 0; i < N; i++) arr[i] = i + 1;
  generateComb(arr, N, N / 2);
  for (vector<int> combination : v) {
    bool check[N + 1] = {0};
    for (int i : combination) check[i] = true;
    vector<int> others;
    for (int i = 1; i <= N; i++) {
      if (!check[i]) others.push_back(i);
    }
    int diff[2] = {0};
    for (int i = 0; i < N / 2 - 1; i++) {
      for (int j = i + 1; j < N / 2; j++) {
        diff[0] += status[combination[i]][combination[j]];
        diff[0] += status[combination[j]][combination[i]];
        diff[1] += status[others[i]][others[j]];
        diff[1] += status[others[j]][others[i]];
      }
    }
    minDiff = min(minDiff, abs(diff[0] - diff[1]));
    if (minDiff == 0) break;
  }
  cout << minDiff << "\n";
  return 0;
}
