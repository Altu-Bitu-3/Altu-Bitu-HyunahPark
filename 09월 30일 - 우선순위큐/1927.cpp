#include <iostream>
#include <queue>
#include <vector>
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

  while (n--)
  {
    cin >> input;

    //배열에 자연수 x 넣음
    if (input)
    {
      pq.push(input);
    }

    //배열에서 가장 작은 값 출력 후 제거
    else if (!pq.empty())
    {
      cout << pq.top() << "\n";
      pq.pop();
    }

    //배열이 비어있는 경우
    else
    {
      cout << "0\n";
    }
  }
}