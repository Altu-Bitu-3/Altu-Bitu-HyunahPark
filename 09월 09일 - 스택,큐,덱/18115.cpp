#include <iostream>
#include <deque>
#include <vector>

using namespace std;

deque<int> calculate(deque<int> &d, vector<int> cal, int n)
{
  deque<int> original;

  for (int i = 0; i < n; i++)
  {
    switch (cal[i])
    {
    case 1:
      original.push_front(d.back());
      break;
    case 2:
    {
      int tmp = original.front();
      original.pop_front();
      original.push_front(d.back());
      original.push_front(tmp);
      break;
    }
    case 3:
      original.push_back(d.back());
      break;
    }
    d.pop_back();
  }

  return original;
}

int main()
{
  int n, input;
  cin >> n;

  vector<int> cal(n);

  for (int i = 1; i <= n; i++)
  {
    cin >> cal[n - i];
  }

  deque<int> d;
  for (int i = 1; i <= n; i++)
  {
    d.push_front(i);
  }

  deque<int> result = calculate(d, cal, n);

  for (int i : result)
  {
    cout << i << " ";
  }
}