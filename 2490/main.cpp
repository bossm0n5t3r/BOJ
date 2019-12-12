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
    sum = a + b + c + d;
    if (sum == 4)
      cout << "E\n";
    else if (sum == 3)
      cout << "A\n";
    else if (sum == 2)
      cout << "B\n";
    else if (sum == 1)
      cout << "C\n";
    else
      cout << "D\n";
  }
  return 0;
}
