#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
  int n, m, answer = 0;
  string input;
  unordered_set<string> str;

  cin >> n >> m;

  while (n--)
  {
    cin >> input;
    str.insert(input);
  }

  while (m--)
  {
    cin >> input;

    if (str.find(input) != str.end())
    {
      answer++;
    }
  }

  cout << answer;
}