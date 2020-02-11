#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int w, h, N, type, num;
  vector<int> cut_h;
  vector<int> cut_w;
  cin >> w >> h;
  cin >> N;
  cut_h.push_back(0);
  cut_w.push_back(0);
  while (N--) {
    cin >> type >> num;
    if (type == 0) {
      cut_h.push_back(num);
    } else {
      cut_w.push_back(num);
    }
  }
  cut_h.push_back(h);
  cut_w.push_back(w);
  sort(cut_h.begin(), cut_h.end());
  sort(cut_w.begin(), cut_w.end());
  int final_h = 0, final_w = 0;
  for (int i = 0; i < (int)cut_h.size() - 1; i++) {
    int tmp = cut_h[i + 1] - cut_h[i];
    if (tmp > final_h) final_h = tmp;
  }
  for (int i = 0; i < (int)cut_w.size() - 1; i++) {
    int tmp = cut_w[i + 1] - cut_w[i];
    if (tmp > final_w) final_w = tmp;
  }
  cout << final_h * final_w << "\n";
  return 0;
}
