#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void josephus(queue<int> &q, vector<int> &deleted, int k)
{
  int num = 1;
  while (!q.empty())
  {
    if (num != k)
    {
      q.push(q.front());
      num++;
    }
    else
    {
      deleted.push_back(q.front());
      num = 1;
    }
    q.pop();
  }
}

int main()
{
  int n, k;
  queue<int> q;
  vector<int> deleted;

  cin >> n >> k;

  for (int i = 1; i <= n; i++)
  {
    q.push(i);
  }

  josephus(q, deleted, k);

  cout << "<";
  for (int i = 0; i < (n - 1); i++)
  {
    cout << deleted[i] << ", ";
  }

  cout << deleted[n - 1] << ">";
}