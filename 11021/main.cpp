#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int i, T, A, B;
  cin >> T;
  for (i = 1; i <= T; i++)
  {
    cin >> A >> B;
    cout << "Case #" << i << ": " << A + B << "\n";
  }
  return 0;
}
