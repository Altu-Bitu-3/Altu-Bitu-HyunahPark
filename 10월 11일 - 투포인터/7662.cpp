#include <functional>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main()
{
  int t, k, n, num, min, max;
  char op;
  cin >> t;

  while (t--)
  {
    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;
    multiset<int> nums; //중복을 허용해야 하기 때문에 set이 아니라 multiset을 쓰면 된다..
    cin >> k;

    for (int i = 0; i < k; i++)
    {
      cin >> op;

      //삭제 연산
      if (op == 'D')
      {
        cin >> n;

        //비어 있는 경우
        if (nums.empty())
        {
          continue;
        }

        //최대값 삭제
        if (n == 1)
        {
          do
          {
            num = max_q.top();
            max_q.pop();
          } while (nums.count(num) == 0); //존재하지 않는 원소인 경우 큐에서 삭제
        }
        else
        { //최소값 삭제
          do
          {
            num = min_q.top();
            min_q.pop();
          } while (nums.count(num) == 0); //존재하지 않는 원소인 경우 큐에서 삭제
        }
        nums.erase(nums.find(num));
      }
      else
      { //입력 연산
        cin >> n;
        nums.insert(n);
        max_q.push(n);
        min_q.push(n);
      }
    }

    //비어 있는 경우
    if (nums.empty())
    {
      cout << "EMPTY\n";
    }
    else
    {
      do
      {
        max = max_q.top();
        max_q.pop();
      } while (nums.count(max) == 0);

      do
      {
        min = min_q.top();
        min_q.pop();
      } while (nums.count(min) == 0);

      cout << max << " " << min << "\n";
    }
  }
}