#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

int main()
{
  set<ci> pairs;
  vector<int> nums;
  int target, input;

  while (cin >> input)
  {
    nums.push_back(input);
  }

  target = nums.back();
  nums.pop_back();

  for (int i = 0; i < nums.size(); i++)
  {
    for (int j = i + 1; j < nums.size(); j++)
    {
      if (nums[i] + nums[j] == target)
      {
        if (nums[i] > nums[j])
          continue;
        else
        {
          pairs.insert({nums[i], nums[j]});
        }
      }
    }
  }

  for (auto iter : pairs)
  {
    cout << iter.first << " " << iter.second << "\n";
  }
  cout << pairs.size();
}