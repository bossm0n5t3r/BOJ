#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long A, B, C, i;
  cin >> A >> B;
  if (A > B)
  {
    i = A;
    A = B;
    B = i;
  }
  C = B - A - 1;
  if (C < 0)
    C = 0;
  cout << C << "\n";
  for (i = A + 1; i < B; i++)
    cout << i << " ";
  return 0;
}
