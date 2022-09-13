#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countAp(vector<pair<int, int>> &ap, int n)
{
  int cnt = 1;
  int min = ap[0].second;

  for (int i = 1; i < n; i++)
  {
    if (ap[i].second < min)
    {
      cnt++;
      min = ap[i].second;
    }
  }

  return cnt;
}

int main()
{

  int t;
  cin >> t;

  for (int i = 0; i < t; i++)
  {
    int n;
    cin >> n;

    vector<pair<int, int>> ap(n);

    for (int i = 0; i < n; i++)
    {
      cin >> ap[i].first >> ap[i].second;
    }

    sort(ap.begin(), ap.end());

    cout << countAp(ap, n) << "\n";
  }
}