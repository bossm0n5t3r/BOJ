#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T, A, B;
  cin >> T;
  while (T-- > 0)
  {
    cin >> A >> B;
    cout << A + B << "\n";
  }
  return 0;
}
