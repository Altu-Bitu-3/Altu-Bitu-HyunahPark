#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//num 길이의 과자를 몇 명에게 줄 수 있는지 계산
int calc(int num, vector<int> &v)
{
  int sum = 0;

  for (int i = 0; i < v.size(); i++)
  {
    if (v[i] >= num)
    {
      sum += v[i] / num;
    }
  }

  return sum;
}

int binarySearch(int left, int right, int m, vector<int> &v)
{
  while (left <= right)
  {
    int mid = (left + right) / 2;

    int sum = calc(mid, v);

    //과자를 줄 수 있는 사람 수가 조카 수보다 적은 경우
    if (sum < m)
    {
      right = mid - 1;
    }

    //더 많거나 같은 경우
    else
    {
      left = mid + 1;
    }
  }

  return right;
}

int main()
{
  int m, n, maxv = 0;
  cin >> m >> n;

  vector<int> snacks(n, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> snacks[i];
    if (snacks[i] > maxv)
    {
      maxv = snacks[i];
    }
  }

  cout << binarySearch(0, maxv, m, snacks);
}