#include <iostream>
#include <queue>

using namespace std;

bool isAble(priority_queue<int> &pq, int n)
{
  int input;
  while (n--)
  {
    cin >> input;

    //선물을 가져갈 수 있는 경우
    if (pq.top() >= input)
    {
      //남은 선물을 다른 사람이 또 가져갈 수 있게
      pq.push(pq.top() - input);
      pq.pop();
    }

    //없는 경우
    else
    {
      return false;
    }
  }

  return true;
}

int main()
{
  int n, m, input;

  cin >> n >> m;

  priority_queue<int> pq;

  while (n--)
  {
    cin >> input;
    pq.push(input);
  }

  cout << isAble(pq, m);
}