#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string iterString(string s) { return s.substr(1) += s[0]; }

int main()
{
  int n;
  cin >> n;

  vector<string> input(n);

  for (int i = 0; i < n; i++)
  {
    cin >> input[i];
  }

  sort(input.begin(), input.end());
  input.erase(unique(input.begin(), input.end()), input.end());

  for (int i = 0; i < input.size(); i++)
  {
    string s_iter = iterString(input[i]);

    while (true)
    {
      if (s_iter == input[i])
      {
        break;
      }

      auto iter = find(input.begin(), input.end(), s_iter);
      if (iter != input.end())
      {
        input.erase(iter);
      }

      s_iter = iterString(s_iter);
    }
  }

  cout << input.size();
}