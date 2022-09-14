#include <iostream>
#include <unordered_map>

using namespace std;

const int SIZE = 31;

int main()
{
  int t, n;
  string s, type;
  cin >> t;

  while (t--)
  {
    unordered_map<string, int> clothes;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      cin >> s >> type;

      if (clothes.count(type))
      {
        clothes[type]++;
      }
      else
      {
        clothes[type] = 1;
      }
    }

    int answer = 1;

    for (auto iter : clothes)
    {
      answer *= (iter.second + 1);
    }

    cout << answer - 1 << "\n";
  }
}