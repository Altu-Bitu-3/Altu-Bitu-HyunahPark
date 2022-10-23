#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(string s1, string s2, int strike, int ball)
{
  int s = 0, b = 0;

  for (int i = 0; i < s1.size(); i++)
  {
    //자리와 숫자가 모두 같다면 strike
    if (s1[i] == s2[i])
    {
      s++;
    }

    //숫자만 같은 경우에는 ball
    else if (s2.find(s1[i]) != string::npos)
    {
      b++;
    }
  }

  return (s == strike && b == ball);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, target, s, b;
  vector<int> nums;

  //가능한 모든 경우의 수 저장
  for (int i = 1; i <= 9; i++)
  {
    for (int j = 1; j <= 9; j++)
    {
      if (i == j)
      {
        continue;
      }
      for (int k = 1; k <= 9; k++)
      {
        if (i == k || j == k)
        {
          continue;
        }
        nums.push_back(i * 100 + j * 10 + k);
      }
    }
  }

  cin >> n;

  while (n--)
  {
    cin >> target >> s >> b;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
      //영수의 대답과 일치하지 않는 숫자를 삭제
      if (!check(to_string(nums[i]), to_string(target), s, b))
      {
        nums.erase(nums.begin() + i);
      }
    }
  }

  cout << nums.size();
}