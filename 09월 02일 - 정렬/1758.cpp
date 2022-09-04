#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{

  int n;
  cin >> n;

  vector<int> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end(), greater<>());

  long long tip = 0;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] > i)
    {
      tip += (arr[i] - i);
    }
  }

  cout << tip;
}