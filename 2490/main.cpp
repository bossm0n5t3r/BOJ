#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, a, b, c, d, sum;
  for (i = 0; i < 3; i++)
  {
    cin >> a >> b >> c >> d;
    sum = 4 - (a + b + c + d);
    cout << (char)(sum == 0 ? 'E' : 64 + sum) << "\n";
  }
  return 0;
}
