#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, num, max = 0, index = 0;
  for (i = 1; i < 10; i++)
  {
    cin >> num;
    if (max < num)
    {
      max = num;
      index = i;
    }
  }
  cout << max << "\n";
  cout << index << "\n";
  return 0;
}
