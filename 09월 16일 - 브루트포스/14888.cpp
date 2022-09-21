#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> permutation(vector<int> &v, vector<int> &nums, int n)
{
  vector<int> answers;
  do
  {
    int answer = 0, prev = nums[0];
    for (int i = 0; i < (n - 1); i++)
    {
      switch (v[i])
      {
      case 1:
        prev += nums[i + 1];
        break;
      case 2:
        prev -= nums[i + 1];
        break;
      case 3:
        prev *= nums[i + 1];
        break;
      case 4:
        prev /= nums[i + 1];
        break;
      }
    }
    answers.push_back(prev);
  } while (next_permutation(v.begin(), v.end()));

  return answers;
}

int main()
{
  int n;
  cin >> n;

  vector<int> nums(n);
  vector<int> op;

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  for (int i = 1; i <= 4; i++)
  {
    int input;
    cin >> input;
    for (int j = 0; j < input; j++)
    {
      op.push_back(i);
    }
  }

  vector<int> answers = permutation(op, nums, n);
  cout << *max_element(answers.begin(), answers.end()) << "\n";
  cout << *min_element(answers.begin(), answers.end());
}