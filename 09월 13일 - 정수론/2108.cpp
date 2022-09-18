#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

bool cmp(const ci &a, const ci &b)
{
  if (a.second != b.second)
    return a.second > b.second;
  return a.first < b.first;
}

int main()
{
  int n, input;
  cin >> n;

  map<int, int> nums;

  for (int i = 0; i < n; i++)
  {
    cin >> input;
    nums[input]++;
  }

  // mean
  double sum =
      accumulate(nums.begin(), nums.end(), 0, [](auto prev_sum, auto &entry)
                 { return prev_sum + entry.first * entry.second; });
  cout << (int)round(sum / n) << "\n";

  // median
  vector<ci> vec(nums.begin(), nums.end());
  int target = (n - 1) / 2, cnt = 0, index = 0;
  for (int i = 0; i < vec.size(); i++)
  {
    for (int j = 0; j < vec[i].second; j++)
    {
      if (cnt == target)
      {
        index = i;
        break;
      }
      cnt++;
    }
    if (index)
    {
      break;
    }
  }
  cout << vec[index].first << "\n";

  // mode
  sort(vec.begin(), vec.end(), cmp);
  int mode = vec[0].second != vec[1].second ? vec[0].first : vec[1].first;
  cout << mode << "\n";

  // range
  auto min = nums.begin();
  auto max = --nums.end();
  cout << max->first - min->first;
}