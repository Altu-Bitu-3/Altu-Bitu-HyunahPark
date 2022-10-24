#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll cntPerson(ll time, vector<ll> &desk)
{
  ll cnt = 0;

  for (ll i : desk)
  {
    cnt += time / i; //하나의 심사대에서 time동안 처리될 수 있는 사람의 수
  }

  return cnt; //time 동안 처리될 수 있는 전체 사람의 수
}

ll binarySearch(ll left, ll right, int m, vector<ll> &desk)
{
  ll mid = 0, cnt = 0, ans = 0;

  while (left <= right)
  {
    mid = (left + right) / 2;
    cnt = cntPerson(mid, desk);

    //해당 시간 동안 처리될 수 있는 사람 수가 더 적은 경우, 더 많은 시간이 필요
    if (cnt < m)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }

  return left;
}

int main()
{
  int n, m;
  cin >> n >> m;

  vector<ll> desk(n, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> desk[i];
  }

  cout << binarySearch(0, *max_element(desk.begin(), desk.end()) * m, m, desk);
}