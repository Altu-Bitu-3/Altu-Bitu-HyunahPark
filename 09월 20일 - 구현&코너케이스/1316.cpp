#include <iostream>
#include <vector>

using namespace std;

//그룹단어인지 판별
bool isValid(string s)
{
  //해당 알파벳이 등장했는지 체크하는 배열
  vector<bool> alpha(27, false);
  alpha[s[0] - 'a'] = true;

  for (int i = 1; i < s.size(); i++)
  {
    //이미 등장한 알파벳이 비연속적으로 다시 등장한 경우
    if (s[i - 1] != s[i] && alpha[s[i] - 'a'])
    {
      return false;
    }
    alpha[s[i] - 'a'] = true;
  }
  return true;
}

int main()
{
  int n, answer = 0;
  cin >> n;

  string s;

  while (n--)
  {
    cin >> s;

    if (isValid(s))
    {
      answer++;
    }
  }

  cout << answer;
}