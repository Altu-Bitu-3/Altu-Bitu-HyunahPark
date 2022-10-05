#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
  int n, input, centi, limit, cnt = 0;
  bool is_possible = false;

  cin >> n >> centi >> limit;

  priority_queue<int> pq;

  while (n--)
  {
    cin >> input;
    pq.push(input);
  }

  while (!pq.empty())
  {
    //모든 거인이 센티보다 키가 작아진 경우
    if (pq.top() < centi)
    {
      is_possible = true;
      break;
    }

    //뿅망치를 이용할 수 있는 경우
    if (pq.top() > 1 && cnt < limit)
    {
      pq.push(floor(pq.top() / 2));
      pq.pop();
      cnt++;
    }
    else
    {
      break;
    }
  }

  if (is_possible)
  {
    cout << "YES\n";
    cout << cnt;
  }
  else
  {
    cout << "NO\n";
    cout << pq.top();
  }
}