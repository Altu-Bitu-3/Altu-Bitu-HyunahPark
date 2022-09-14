#include <iostream>
#include <set>

using namespace std;

int main()
{
  int n;
  string name, status;
  set<string, greater<string>> names;

  cin >> n;

  while (n--)
  {
    cin >> name >> status;

    if (status == "enter")
    {
      names.insert(name);
    }
    else
    {
      names.erase(name);
    }
  }

  for (auto iter : names)
  {
    cout << iter << "\n";
  }
}