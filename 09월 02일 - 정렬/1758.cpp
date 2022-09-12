#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

long long calculateTip(vector<int> &arr)
{
  long long tip = 0;

  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] <= i)
    {
      return tip;
    }
    tip += (arr[i] - i);
  }
  return tip;
}

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

  cout << calculateTip(arr);
}
