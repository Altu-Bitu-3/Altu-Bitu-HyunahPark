#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque<int> calculate(vector<int> &cal, int n)
{
  deque<int> original;
  int num = 1;

  for (int i = 0; i < n; i++)
  {
    switch (cal[i])
    {
    case 1:
      original.push_front(num++);
      break;
    case 2:
    {
      int tmp = original.front();
      original.pop_front();
      original.push_front(num++);
      original.push_front(tmp);
      break;
    }
    case 3:
      original.push_back(num++);
      break;
    }
  }

  return original;
}

int main()
{
  int n, input;
  cin >> n;

  vector<int> cal(n);

  for (int i = n-1; i >= 0; i--)
  {
    cin >> cal[i];
  }

  deque<int> result = calculate(cal, n);

  for (int i : result)
  {
    cout << i << " ";
  }
}
