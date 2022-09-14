#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

map<int, int> num_orders;

bool cmp(const ci &a, const ci &b)
{
  if (a.second != b.second)
    return a.second > b.second;
  return num_orders[a.first] < num_orders[b.first];
}

int main()
{
  int N, C;
  cin >> N >> C;

  map<int, int> num_pairs;

  for (int i = 0; i < N; i++)
  {
    int input;
    cin >> input;

    if (!num_pairs.count(input))
    {
      num_orders[input] = i;
    }

    num_pairs[input]++;
  }

  vector<ci> vec(num_pairs.begin(), num_pairs.end());
  sort(vec.begin(), vec.end(), cmp);

  for (int i = 0; i < vec.size(); i++)
  {
    for (int j = 0; j < vec[i].second; j++)
    {
      cout << vec[i].first << " ";
    }
  }
}