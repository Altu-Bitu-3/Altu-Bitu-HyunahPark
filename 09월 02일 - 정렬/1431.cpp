#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int sumUp(const string &a)
{
  int sum = 0;

  for (char c : a)
  {
    if (isdigit(c))
    {
      sum += (c - '0');
    }
  }

  return sum;
}

bool cmp(const string &a, const string &b)
{
  if (a.size() != b.size())
  {
    return a.size() < b.size();
  }

  int a_sum = sumUp(a);
  int b_sum = sumUp(b);

  if (a_sum != b_sum)
  {
    return a_sum < b_sum;
  }

  return a < b;
}

int main()
{

  int n;

  cin >> n;

  vector<string> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end(), cmp);

  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << "\n";
  }
}