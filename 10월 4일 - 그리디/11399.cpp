#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> times(n, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> times[i];
  }

  //돈을 인출하는 데 시간이 적게 걸리는 순으로
  sort(times.begin(), times.end());

  int sum = 0, tmp = 0;

  for (auto i : times)
  {
    tmp += i;
    sum += tmp;
  }

  cout << sum;
}