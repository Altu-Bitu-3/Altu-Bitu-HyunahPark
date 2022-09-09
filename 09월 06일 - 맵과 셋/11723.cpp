#include <iostream>
#include <set>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int m, x;
  string cal;
  set<int> s;
  cin >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> cal;

    if (cal == "all")
    {
      s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    }
    else if (cal == "empty")
    {
      s = {};
    }
    else
    {
      cin >> x;
      if (cal == "check")
      {
        cout << s.count(x) << "\n";
      }
      else if ((cal == "remove" || cal == "toggle") && s.count(x))
      {
        s.erase(x);
      }
      else
      {
        s.insert(x);
      }
    }
  }
}