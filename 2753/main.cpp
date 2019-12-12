#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int year;
  cin >> year;
  cout << (!(year % 400) || (!(year % 4) && (year % 100))) << "\n";
  return 0;
}
