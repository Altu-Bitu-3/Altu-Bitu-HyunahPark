#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxElement(int n, vector<int> &nums)
{
  vector<int> dp(n, 1);

  for (int i = 1; i < n; i++)
  {
    int max_e = 0;
    for (int j = 0; j < i; j++)
    {
      if (nums[j] < nums[i] && dp[j] > max_e)
      {
        max_e = dp[j];
      }
    }
    dp[i] += max_e;
  }

  return *max_element(dp.begin(), dp.end());
}

int main()
{
  int n;
  cin >> n;

  vector<int> nums(n);

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  cout << maxElement(n, nums);
}