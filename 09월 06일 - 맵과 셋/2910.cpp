#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main()
{
  int N, C;
  cin >> N >> C;

  unordered_set<int> nums;
  vector<int> rep(C);

  for (int i = 0; i < N; i++)
  {
    int input;
    cin >> input;
    nums.insert(input);
    rep[input]++;
  }

  for (auto num : nums)
  {
    for (int i = 0; i < rep[num]; i++)
    {
      cout << num << " ";
    }
  }
}