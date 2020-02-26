#include <iostream>

using namespace std;

char sudoku[10][10];
bool row[10][10], col[10][10], matrix[10][10];

void dfs(int pos) {
  if (pos == 81) {
    for (int r = 0; r < 9; r++) cout << sudoku[r] << "\n";
    exit(0);
  }
  int r = pos / 9, c = pos % 9;
  if (sudoku[r][c] == '0') {
    for (int i = 1; i <= 9; i++) {
      int matrixIdx = (r / 3) * 3 + (c / 3);
      if (!row[r][i] && !col[c][i] && !matrix[matrixIdx][i]) {
        row[r][i] = col[c][i] = matrix[matrixIdx][i] = true;
        sudoku[r][c] = i + '0';
        dfs(pos + 1);
        row[r][i] = col[c][i] = matrix[matrixIdx][i] = false;
        sudoku[r][c] = '0';
      }
    }
  } else
    dfs(pos + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int r = 0; r < 9; r++) {
    cin >> sudoku[r];
    for (int c = 0; c < 9; c++) {
      if (sudoku[r][c] != '0') {
        int num = sudoku[r][c] - '0';
        row[r][num] = col[c][num] = matrix[(r / 3) * 3 + (c / 3)][num] = true;
      }
    }
  }
  dfs(0);
  return 0;
}
