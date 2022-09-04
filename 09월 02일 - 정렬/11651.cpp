#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

  int n;
  cin >> n;

  vector<pair<int, int>> arr(n);

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].second >> arr[i].first;
  }

  sort(arr.begin(), arr.end());

  for (int i = 0; i < n; i++)
  {
    cout << arr[i].second << " " << arr[i].first << "\n";
  }
}