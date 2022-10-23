#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main()
{

  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, input;
  cin >> n;

  //오름차순 우선순위큐
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> input;

      //가장 큰 수 n개만 큐에 저장
      if (pq.size() >= n && input > pq.top())
      {
        pq.pop();
        pq.push(input);
      }
      else if (pq.size() < n)
      {
        pq.push(input);
      }
    }
  }

  //n번째로 큰 수 출력
  cout << pq.top();
}