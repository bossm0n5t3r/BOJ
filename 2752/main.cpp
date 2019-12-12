#include <iostream>

using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, j, tmp, n, arr[3];
  cin >> arr[0] >> arr[1] >> arr[2];
  n = sizeof(arr) / sizeof(arr[0]);
  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (arr[i] > arr[j])
      {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
      }
    }
  }
  cout << arr[0] << " " << arr[1] << " " << arr[2] << "\n";
  return 0;
}
